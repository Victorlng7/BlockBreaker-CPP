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
    //  sf::CircleShape ballShape({})

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
        // Definition de la taille de la window:
        unsigned int longueur = window.getSize().x;

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

        // MAJ des position avant le rendu
        paddleShape.setPosition({paddle.getX(), paddle.getY()});

        // Rendu
        window.clear(sf::Color::Black);
        window.draw(paddleShape);
        window.display();
    }
}