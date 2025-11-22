//
// Created by Max on 26/06/2024.
//

#include "Planet.h"


Planet::Planet(float pos_x, float pos_y, float strength) {
    this->pos.x = pos_x;
    this->pos.y = pos_y;
    this->strength = strength;

    size = 8 + (strength / 10000);
    this->circle_shape.setOrigin(size,size);
    this->circle_shape.setPosition(this->pos);
    this->circle_shape.setFillColor(sf::Color::White);
    circle_shape.setRadius(size);
}

void Planet::render(sf::RenderWindow& renderWindow) {
    renderWindow.draw(this->circle_shape);
}


sf::Vector2f Planet::getPos() const {
    return this->pos;
}

float Planet::getStrength() const {
    return this->strength;
}

void Planet::grow() {
    this->strength += 500.f;

    float currentRadius = this->circle_shape.getRadius();
    float newRadius = currentRadius + 0.05f; // On grandit tout doucement à chaque impact

    this->circle_shape.setRadius(newRadius);

    this->circle_shape.setOrigin(newRadius, newRadius);
}
