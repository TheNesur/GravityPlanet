//
// Created by Max on 26/06/2024.
//

#include "Planet.h"


Planet::Planet(float pos_x, float pos_y, float strenght) {
    this->pos.x = pos_x;
    this->pos.y = pos_y;
    this->strenght = strenght;

    this->circle_shape.setPosition(this->pos);
    this->circle_shape.setFillColor(sf::Color::White);
    circle_shape.setRadius(8);
}

void Planet::render(sf::RenderWindow& renderWindow) {
    renderWindow.draw(this->circle_shape);
}


sf::Vector2f Planet::getPos() {
    return this->pos;
}

float Planet::getStrenght() {
    return this->strenght;
}