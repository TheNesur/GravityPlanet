//
// Created by pc-4 on 28/06/2024.
//

#ifndef POINT_H
#define POINT_H
#include "Particules.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Point {
private:
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape circle_shape;

public:
    Point(float pos_x, float pos_y, float vel_x, float vel_y);

    void render(sf::RenderWindow& win);
    void update_physics(Particules& particules);
};



#endif //POINT_H
