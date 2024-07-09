#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <array>


#include "physic/particule/Point.h"

int main()
{
    const float width = 1920;
    const float height = 1080;
    const int MAXPoint = 10000;
    std::srand(std::time(nullptr)); // use current time as seed for random generator


    sf::RenderWindow window(sf::VideoMode(width, height), "PlanetGravity");
    window.setFramerateLimit(60);

    Planet source(width/2, height/2, 2000);

//    std::vector<Point*> points;

    std::array<Point, MAXPoint> *points;

    for (int i = 0; i < MAXPoint; ++i) {
        points.push_back(new Point(width/2-(rand()%200+1), height/2+(rand()%200+1),4, 0, {rand()%180,rand()%180,rand()%180}, rand()%12+0.1));
        points[i]
    // std::cout << rand()%12+0.1 << '\n';
    }

    //Point particle(width/2-100, height/2+100, 4, 0);
    while (window.isOpen()) {

        sf::Event event{};
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
                        default:
                            break;
                    }
                    break;
                default:
                    break;
            }
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
