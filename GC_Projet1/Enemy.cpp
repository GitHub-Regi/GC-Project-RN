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
    shape.setPosition({ 40.f, 60.f }); 
    m_speed = 200.f;
}

void Enemy::Update(float dt)
{   
    //Moving
    sf::Vector2f movement(0.f, 0.f);
    //movement.x += m_speed * dt;
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
    if (id == 0)
    {
        //Fin du mouvement
    }
    else if (id == 1)
    {
        //Fin du crash
    }
}

void Enemy::onEnter(int id)
{
    if (id == 0)
    {
        //Pret a avancer
    }
    else if (id == 1)
    {
        shape.setFillColor(sf::Color::Red);
    }
}

void Enemy::onExecute(int id, float dt)
{
    if (id == 0)
    {
        shape.move(sf::Vector2f(0.f, -m_speed * dt));
    }
    else if (id == 1)
    {
        if (m_stateTime > 0.5f)//changer la condition si collision avec un missile du joueur
        {
            toState(1);
        }
    }
}
