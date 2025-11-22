#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <valarray>


#include "physic/particule/Point.h"

void createSmockPoint(std::vector<Point*>& points, int count, float width, float height);

int main()
{
    const float G_STRENGTH = 100.0f;
    // Use 80% of the desktop resolution for the window size and center it
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    unsigned int winW = static_cast<unsigned int>(desktop.width * 0.8f);
    unsigned int winH = static_cast<unsigned int>(desktop.height * 0.8f);
    const float width = static_cast<float>(winW);
    const float height = static_cast<float>(winH);
    const int MAXPoint = 0;
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

    // Creation du nuages de points
    createSmockPoint(points, MAXPoint,2000, 2000);

    sf::Clock clock;

    while (window.isOpen()) {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

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

                        float planetStrength = 2000*G_STRENGTH; // 1000 = constante pour contrer le delta time
                        Planet* newPlanet = new Planet(xMouse, yMouse, planetStrength);
                        planets.push_back(newPlanet);

                        std::cout << "Planete créer [" << xMouse << ";" << yMouse << "]\n";

                        int particlesPerPlanet = 1000;

                        for (int i = 0; i < particlesPerPlanet; ++i) {
                            float angle = static_cast<float>(rand() % 360) * 3.14159f / 180.f;
                            float dist = static_cast<float>(rand() % 250 + 150 + newPlanet->getSize()); // 150 ou 50 (distance de planete)

                            float offsetX = std::cos(angle) * dist;
                            float offsetY = std::sin(angle) * dist;

                            float pX = xMouse + offsetX;
                            float pY = yMouse + offsetY;

                            float velocityMagnitude = std::sqrt(planetStrength / dist);


                            float dirX = -offsetY; // Note le signe moins ici !
                            float dirY = offsetX;

                            float length = std::sqrt(dirX*dirX + dirY*dirY);
                            dirX /= length;
                            dirY /= length;

                            float vX = dirX * velocityMagnitude;
                            float vY = dirY * velocityMagnitude;

                            sf::Color color(rand() % 255, rand() % 255, rand() % 255);
                            points.push_back(new Point(sf::Vector2f(pX, pY), sf::Vector2f(vX, vY), color, 4.f));
                        }
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

        for (Point *point : points) {
            for (Planet *planet : planets) {
                point->accumulateForce(*planet);
            }
        }

        for (Point *point : points) {
            point->updatePosition(dt);
            point->render(window);

        }
        for (Planet *planet : planets)
            planet->render(window);


        for (int i = points.size() -1; i >=0; i--) {
            if (points[i]->isDead()){

                delete points[i];
                points.erase(points.begin() + i);
            }
        }



        window.display();
    }

    // cleanup
    for (auto p : points) delete p;
    points.clear();
    for (auto pl : planets) delete pl;
    planets.clear();

    return 0;
}



void createSmockPoint(std::vector<Point*>& points, int count, float width, float height) {
    for (int i = 0; i < count; ++i) {
        // Position aléatoire
        float px = static_cast<float>(rand() % static_cast<int>(width) + 1);
        float py = static_cast<float>(rand() % static_cast<int>(height) + 1);
        sf::Vector2f position(px, py);

        sf::Vector2f velocity(0.f, 0.f);

        sf::Color color(static_cast<sf::Uint8>(rand() % 180), static_cast<sf::Uint8>(rand() % 180), static_cast<sf::Uint8>(rand() % 180));
        float radius = static_cast<float>(rand() % 12) + 0.1f;
        points.push_back(new Point(position, velocity, color, radius));
    }
}