#include "Collision.h"

Collision::Collision()
{

}

Collision::~Collision()
{

}

bool Collision::IsColliding(const sf::RectangleShape& a, const sf::RectangleShape b)
{
    sf::Vector2f posA = a.getPosition();
    sf::Vector2f sizeA = a.getSize();
    sf::Vector2f posB = b.getPosition();
    sf::Vector2f sizeB = b.getSize();

    float leftA = posA.x;
    float rightA = posA.x + sizeA.x;
    float topA = posA.y;
    float bottomA = posA.y + sizeA.y;

    float leftB = posB.x;
    float rightB = posB.x + sizeB.x;
    float topB = posB.y;
    float bottomB = posB.y + sizeB.y;

    if (rightA <= leftB || leftA >= rightB) return false;
    if (bottomA <= topB || topA >= bottomB) return false;

    return true;
}
