#include "Enemy.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

void Enemy::initEnemy()
{
    shape.setSize(sf::Vector2f(30, 50));
    shape.setOrigin({ 15.f, 50.f }); //modifie le point d'origine de la forme (ici au milieu bas)
    shape.setFillColor(sf::Color::Magenta);
    //Random this
    shape.setPosition({ 640.f, 700.f }); 
}

void Enemy::Update(float dt)
{   
    //Moving
    float speed = 200.0f;
    sf::Vector2f movement(0.f, 0.f);
    shape.move(movement);

    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f size = shape.getSize();

    if (pos.x < 30) pos.x = 30;
    if (pos.y < 550) pos.y = 550;
    if (pos.x > 1250) pos.x = 1250;
    if (pos.y > 700) pos.y = 700;

    shape.setPosition(pos);

    //shooting
}

void Enemy::onExit(int id)
{
}

void Enemy::onEnter(int id)
{
}

void Enemy::onExecute(int id, float dt)
{
}
