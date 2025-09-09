#include "Player.h"

Player::Player()
{
    shape.setSize(sf::Vector2f(40, 70));
    shape.setOrigin({ 20.f, 70.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 640.f, 700.f });
}

void Player::Update(float dt, Input& input)
{
    float speed = 350.0f;
    sf::Vector2f movement(0.f, 0.f);

    if (input.IsKeyPressed('Q'))
    {
        movement.x -= speed * dt;
    }
    if (input.IsKeyPressed('D'))
    {
        movement.x += speed * dt;
    }
    if (input.IsKeyPressed('Z'))
    {
        movement.y -= speed * dt;
    }
    if (input.IsKeyPressed('S'))
    {
        movement.y += speed * dt;
    }
    
    shape.move(movement);

    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f size = shape.getSize();

    if (pos.x < 100) pos.x = 100;
    if (pos.y < 500) pos.y = 500;
    if (pos.x > 1180) pos.x = 1180;
    if (pos.y > 700) pos.y = 700;

    shape.setPosition(pos);
}

