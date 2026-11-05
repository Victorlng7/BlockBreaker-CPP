#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 600}), "test window");

    sf::CircleShape shape(100);
    shape.setFillColor(sf::Color::Black);

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
        window.clear(sf::Color::White);
        window.draw(shape);
        window.display();
    }
}