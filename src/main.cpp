#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

#include "physic/particule/Point.h"

int main()
{
    const int width = 1600;
    const int height = 1000;
    sf::RenderWindow window(sf::VideoMode(width, height), "PlanetGravity");
    window.setFramerateLimit(60);

    Particules source(width/2, height/2, 7000);

    Point particle(width/2-100, height/2+100, 4, 0);
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }




        window.clear();

        particle.update_physics(source);
        source.render(window);
        particle.render(window);

        window.display();
    }

    return 0;
}
