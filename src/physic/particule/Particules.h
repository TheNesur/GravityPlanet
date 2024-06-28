//
// Created by Max on 26/06/2024.
//

#ifndef GRAVITYPLANET_PARTICULES_H
#define GRAVITYPLANET_PARTICULES_H
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/System/Vector2.hpp"


class Particules {
private:
    sf::Vector2f pos;
    float strenght;
    sf::CircleShape circle_shape;

public:
    Particules(float pos_x, float pos_y, float strenght);

    void render(sf::RenderWindow& renderWindow);

    sf::Vector2f getPos();
    float getStrenght();

};


#endif //GRAVITYPLANET_PARTICULES_H
