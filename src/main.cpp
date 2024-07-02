#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


#include "physic/particule/Point.h"

int main()
{
    const int width = 1920;
    const int height = 1080;
    const int MAXPoint = 10000;
    std::srand(std::time(nullptr)); // use current time as seed for random generator


    sf::RenderWindow window(sf::VideoMode(width, height), "PlanetGravity");
    window.setFramerateLimit(60);

    Planet source(width/2, height/2, 2000);

    std::vector<Point*> points;

    for (int i = 0; i < MAXPoint; ++i) {
        points.push_back(new Point(width/2-(rand()%200+1), height/2+(rand()%200+1),4, 0, {rand()%255,rand()%255,rand()%255}, rand()%12+0.1));
    // std::cout << rand()%12+0.1 << '\n';
    }

    //Point particle(width/2-100, height/2+100, 4, 0);
    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch(event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                    }
                    break;
            }
            // if (event.type == sf::Event::Closed) window.close();
            // if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
        }



        window.clear();

        //particle.update_physics(source);
        for (int i = 0; i < MAXPoint; ++i) {
            points[i]->update_physics(source);
            points[i]->render(window);
        }
        source.render(window);
        //particle.render(window);

        window.display();
    }

    return 0;
}
