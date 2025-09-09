#include "Player.h"

Player::Player()
{
    shape.setSize(sf::Vector2f(100, 30));
    shape.setOrigin({ 10.f, 100.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 640.f, 650.f });
}

void Player::Update(float dt, Input& input)
{
    float speed = 200.0f;
    sf::Vector2f movement(0.f, 0.f);

    shape.move(movement);
}

