//
// Created by pc-4 on 28/06/2024.
//

#include "Point.h"
#include "math.h"

Point::Point(sf::Vector2f position, sf::Vector2f velocity, sf::Color color, float radius) {
    position.x = position.x;
    position.y = position.y;

    velocity.x = velocity.x;
    velocity.y = velocity.y;

    this->_circle_shape.setPosition(position);
    this->_circle_shape.setFillColor(color);
    this->_circle_shape.setRadius(radius);
}

void Point::render(sf::RenderWindow &render_window) {
    this->_circle_shape.setPosition(this->_position);
    render_window.draw(this->_circle_shape);
}

void Point::update_physics(Planet &particules) {
    float distance_x = particules.getPos().x - this->_position.x;
    float distance_y = particules.getPos().y - this->_position.y;

    float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

    float inverse_distance = 1.f / distance;

    float normalized_x = inverse_distance * distance_x;
    float normalized_y = inverse_distance * distance_y;

    float inverse_square_dropoff = inverse_distance * inverse_distance;

    float acceleration_x = normalized_x * particules.getStrength() * inverse_square_dropoff;
    float acceleration_y = normalized_y * particules.getStrength() * inverse_square_dropoff;

    this->_velocity.x += acceleration_x;
    this->_velocity.y += acceleration_y;

    this->_position.x += this->_velocity.x;
    this->_position.y += this->_velocity.y;
}

const sf::Vector2f &Point::getPosition() const {
    return this->_position;
}

void Point::setPosition(const sf::Vector2f &position) {
    Point::_position = position;
}

const sf::Vector2f &Point::getVelocity() const {
    return this->_velocity;
}

void Point::setVelocity(const sf::Vector2f &velocity) {
    Point::_velocity = velocity;
}

const sf::CircleShape &Point::getCircleShape() const {
    return this->_circle_shape;
}

void Point::setCircleShape(const sf::CircleShape &circleShape) {
    this->_circle_shape = circleShape;
}

