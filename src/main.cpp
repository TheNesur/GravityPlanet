#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>


#include "physic/particule/Point.h"

int main()
{
    // Use 80% of the desktop resolution for the window size and center it
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int winW = static_cast<unsigned int>(desktop.width * 0.8f);
    unsigned int winH = static_cast<unsigned int>(desktop.height * 0.8f);
    const float width = static_cast<float>(winW);
    const float height = static_cast<float>(winH);
    const int MAXPoint = 1000;
    std::srand(std::time(nullptr)); // use current time as seed for random generator


    sf::RenderWindow window(sf::VideoMode(winW, winH), "PlanetGravity");
    window.setFramerateLimit(60);

    // Center the window on the desktop
    window.setPosition(sf::Vector2i((desktop.width - static_cast<int>(winW)) / 2,
                                    (desktop.height - static_cast<int>(winH)) / 2));

    // Planet source(width/10, height/10, 2000);

    std::vector<Point*> points;
    std::vector<Planet*> planets;
    points.reserve(MAXPoint);

    for (int i = 0; i < MAXPoint; ++i) {
        float px = /*width/2.0f -*/ static_cast<float>(rand()%2000 + 1);
        float py =/* height/2.0f +*/ static_cast<float>(rand()%2000 + 1);
        sf::Vector2f position(px, py);
        sf::Vector2f velocity(0.f, 0.f);
        sf::Color color(static_cast<sf::Uint8>(rand()%180), static_cast<sf::Uint8>(rand()%180), static_cast<sf::Uint8>(rand()%180));
        float radius = static_cast<float>(rand()%12) + 0.1f;
        points.push_back(new Point(position, velocity, color, radius));
        std::cout << "Point créer [" << px << ";" << py << "]\n";
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

                case sf::Event::MouseButtonPressed: {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        float xMouse = static_cast<float>(event.mouseButton.x);
                        float yMouse = static_cast<float>(event.mouseButton.y);
                        planets.push_back(new Planet(xMouse, yMouse, 2000));
                        std::cout << "Planete créer [" << xMouse << ";" << yMouse << "]\n";
                    } else if (event.mouseButton.button == sf::Mouse::Right) {
                        if (!planets.empty()) {
                            delete planets.back();
                            planets.pop_back();
                            std::cout << "Planete supprimée\n";
                        }
                    }
                    break;
                }
                
                
                default:
                    break;
            }
        }



        window.clear();

        //particle.update_physics(source);
        if (planets.size() == 0 ) {
            for (int i = 0; i < points.size(); ++i) {
                points[i]->render(window);
            }
        } else 
        for (int y = 0; y < planets.size(); ++y) {
            for (int i = 0; i < points.size(); ++i) {
                points[i]->update_physics(*(planets.at(y)));
                points[i]->render(window);
            }

            planets[y]->render(window);
        }
        //particle.render(window);

        window.display();
    }

    // cleanup
    for (auto p : points) delete p;
    points.clear();
    for (auto pl : planets) delete pl;
    planets.clear();

    return 0;
}
