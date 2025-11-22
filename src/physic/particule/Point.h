//
// Created by pc-4 on 28/06/2024.
//

#ifndef POINT_H
#define POINT_H
#include "Planet.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Point {
private:
    sf::Vector2f _position;
    sf::Vector2f _velocity;
    sf::CircleShape _circle_shape;
    sf::Vector2f _acceleration;
    bool _isDead = false;

public:
    Point(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float radius = 8);

    void render(sf::RenderWindow& win);
    //void updatePhysics(Planet& particules);
    void accumulateForce(Planet& planet);
    void updatePosition(float dt);

    const sf::Vector2f &getPosition() const;

    void setPosition(const sf::Vector2f &position);

    const sf::Vector2f &getVelocity() const;

    void setVelocity(const sf::Vector2f &velocity);

    const sf::CircleShape &getCircleShape() const;

    void setCircleShape(const sf::CircleShape &circleShape);

    bool isDead() const { return this->_isDead;}
};



#endif //POINT_H
