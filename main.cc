// Include bibliothèque
#include <SFML/Graphics.hpp>

#include <iostream>
// Include objects
#include "./includes/ball.hh"
#include "./includes/paddle.hh"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "Block Breaker");

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
    ballShape.setPosition({(float)balle.getX(), (float)balle.getVelY()});

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
        // Loop de jeu :

        // Lecture des input claviers
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            if (paddle.getX() > (float)0)
                paddle.setX(paddle.getX() - 0.25);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            if (paddle.getX() < 800 - paddle.getWidth())
                paddle.setX(paddle.getX() + 0.25);
        }

        // Update de la balle :

        // Simulation rebond si ça dépasse
        if (balle.getX() <= 0 || balle.getX() >= 800 - balle.getRadius())
        {
            balle.setVelX(balle.getVelX() * -1);
            balle.addVelX();
        }
        if (balle.getY() <= 0 || balle.getY() >= 600 - balle.getRadius())
        {
            balle.setVelY(balle.getVelY() * -1);
            balle.addVelY();
        }

        // Update de la position
        balle.setY(balle.getY() + balle.getVelY());
        balle.setX(balle.getX() + balle.getVelX());

        // MAJ des position avant le rendu
        paddleShape.setPosition({paddle.getX(), paddle.getY()});
        ballShape.setPosition({balle.getX(), balle.getY()});

        // Rendu
        window.clear(sf::Color::Black);
        window.draw(paddleShape);
        window.draw(ballShape);
        window.display();
    }
}