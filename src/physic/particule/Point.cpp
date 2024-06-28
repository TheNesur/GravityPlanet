//
// Created by pc-4 on 28/06/2024.
//

#include "Point.h"
#include "math.h"

Point::Point(float pos_x, float pos_y, float vel_x, float vel_y) {
    pos.x = pos_x;
    pos.y = pos_y;

    vel.x = vel_x;
    vel.y = vel_y;

    circle_shape.setPosition(pos);
    circle_shape.setFillColor(sf::Color::White);
    circle_shape.setRadius(8);
}

void Point::render(sf::RenderWindow &render_window) {
    circle_shape.setPosition(pos);
    render_window.draw(circle_shape);
}

void Point::update_physics(Particules &particules) {
    float distance_x = particules.getPos().x - pos.x;
    float distance_y = particules.getPos().y - pos.y;

    float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

    float inverse_distance = 1.f / distance;

    float normalized_x = inverse_distance * distance_x;
    float normalized_y = inverse_distance * distance_y;

    float inverse_square_dropoff = inverse_distance * inverse_distance;

    float acceleration_x = normalized_x * particules.getStrenght() * inverse_square_dropoff;
    float acceleration_y = normalized_y * particules.getStrenght() * inverse_square_dropoff;

    vel.x += acceleration_x;
    vel.y += acceleration_y;

    pos.x += vel.x;
    pos.y += vel.y;
}
