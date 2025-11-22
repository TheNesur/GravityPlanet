//
// Created by Max on 26/06/2024.
//

#ifndef GRAVITYPLANET_PLANET_H
#define GRAVITYPLANET_PLANET_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Planet {
private:
    sf::Vector2f pos;
    float strength;
    sf::CircleShape circle_shape;
    float size;

public:
    Planet(float pos_x, float pos_y, float strength);

    void render(sf::RenderWindow& renderWindow);
    void grow();

    sf::Vector2f getPos() const;
    float getStrength() const;
    float getSize() const { return this->size;}
    float getRadius() const { return this->circle_shape.getRadius(); }

};


#endif //GRAVITYPLANET_PLANET_H
