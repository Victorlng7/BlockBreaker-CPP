// Include bibliothèque
#include <SFML/Graphics.hpp>

#include <algorithm>
#include <cmath>
#include <iostream>
// Include objects
#include "./includes/ball.hh"
#include "./includes/paddle.hh"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "Block Breaker");
    window.setFramerateLimit(60);

    // Creation des objets :
    Ball balle{};
    Paddle paddle{};

    // Creation des shapes :
    // Paddle :
    sf::RectangleShape paddleShape({(float)paddle.getWidth(), (float)paddle.getHeight()});
    paddleShape.setFillColor(sf::Color::White);
    // Balle :
    sf::CircleShape ballShape({(float)balle.getRadius()});
    ballShape.setFillColor(sf::Color::White);
    ballShape.setPointCount(100);
    ballShape.setPosition({(float)balle.getX(), (float)balle.getY()});

    while (window.isOpen())
    {
        // On traite tous les événements en attente
        while (std::optional<sf::Event> event = window.pollEvent())
        {
            // Si l'événement est de type "Fermeture de fenêtre" (clic sur la croix)
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
        // dimmention de la window (reactif)
        float winWidth = window.getSize().x;
        float winHeight = window.getSize().y;

        // Loop de jeu :

        // Lecture des input claviers
        const float paddleSpeed = 5.f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            paddle.setX(std::max(0.f, paddle.getX() - paddleSpeed));
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            const float maxPaddleX = winWidth - paddle.getWidth();
            paddle.setX(std::min(maxPaddleX, paddle.getX() + paddleSpeed));
        }
        paddleShape.setPosition({paddle.getX(), paddle.getY()});

        // Update de la balle :
        const float ballDiameter = ballShape.getRadius() * 2.f;
        const float maxBallX = winWidth - ballDiameter;
        const float maxBallY = winHeight - ballDiameter;
        const float previousY = balle.getY();
        float nextX = balle.getX() + balle.getVelX();
        float nextY = balle.getY() + balle.getVelY();

        // Rebonds sur le bord franchi en gardant la balle dans la fenêtre.
        if (nextX < 0.f)
        {
            nextX = 0.f;
            balle.setVelX(std::abs(balle.getVelX()));
            balle.addVelX();
        }
        else if (nextX > maxBallX)
        {
            nextX = maxBallX;
            balle.setVelX(-std::abs(balle.getVelX()));
            balle.addVelX();
        }
        if (nextY < 0.f)
        {
            nextY = 0.f;
            balle.setVelY(std::abs(balle.getVelY()));
            balle.addVelY();
        }
        else if (nextY > maxBallY)
        {
            nextY = maxBallY;
            balle.setVelY(-std::abs(balle.getVelY()));
            balle.addVelY();
        }

        balle.setX(nextX);
        balle.setY(nextY);
        ballShape.setPosition({balle.getX(), balle.getY()});

        // Collision sur le dessus de la raquette uniquement quand la balle descend.
        const sf::FloatRect paddleHB = paddleShape.getGlobalBounds();
        const sf::FloatRect ballHB = ballShape.getGlobalBounds();
        if (balle.getVelY() > 0.f &&
            previousY + ballDiameter <= paddle.getY() &&
            ballHB.findIntersection(paddleHB))
        {
            balle.setY(paddle.getY() - ballDiameter);
            balle.setVelY(-std::abs(balle.getVelY()));
            balle.addVelY();
            ballShape.setPosition({balle.getX(), balle.getY()});
        }

        // Rendu
        window.clear(sf::Color::Black);
        window.draw(paddleShape);
        window.draw(ballShape);
        window.display();
    }
}