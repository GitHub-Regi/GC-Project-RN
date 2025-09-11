#include "Collision.h"

Collision::Collision()
{

}

Collision::~Collision()
{

}

void Collision::Update(float dt)
{
    UpdateStateTime(dt);
    onExecute(m_currentState, dt);
}


bool IsColliding(const Entity& a, const Entity& b)
{
    sf::Vector2f posA = a.GetPos();
    sf::Vector2f sizeA = a.GetSize();
    sf::Vector2f posB = a.GetPos();
    sf::Vector2f sizeB = b.GetSize();

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
