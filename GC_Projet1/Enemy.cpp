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
    m_goal = 1200;

    toState(0);
}

void Enemy::Update(float dt)
{   
    UpdateStateTime(dt);
    onExecute(m_currentState, dt);
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
        //Moving
        sf::Vector2f movement(0.f, 0.f);
        if (shape.getPosition().x != m_goal  && m_goal > 640) {
            if (shape.getPosition().x == m_goal) {
                m_goal = 80;
            }
            movement.x += m_speed * dt;
        }
        if (shape.getPosition().x != m_goal && m_goal < 640) {
            if (shape.getPosition().x == m_goal) {
                m_goal = 1200;
            }
            movement.x -= m_speed * dt;
        }
        shape.move(movement);

        //shooting

    }
    else if (id == 1)
    {
        if (m_stateTime > 0.5f)//changer la condition si collision avec un missile du joueur
        {
            toState(1);
        }
    }
}
