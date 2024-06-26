#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 500), "PlanetGravity");
    window.setFramerateLimit(60);

    while (window.isOpen()) {

        window.clear();
        window.display();
    }

    return 0;
}