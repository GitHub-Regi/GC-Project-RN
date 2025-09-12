#include "Enemy.h"

Enemy::Enemy() : m_speed(), m_pattern(), m_goal()
{

}

Enemy::~Enemy()
{
}

void Enemy::initEnemy(int spawnX, int spawnY, int pattern, EnemiesManager* manager)
{
    shape.setSize(sf::Vector2f(30, 50));
    shape.setOrigin({ 0.f, 0.f }); //modifie le point d'origine de la forme (ici au milieu bas)
    shape.setFillColor(sf::Color::Magenta);
    //Random this
    shape.setPosition({ float(spawnX) , float(spawnY) }); 
    m_speed = 200.f;

    currentHealth = maxHealth;

    m_pattern = pattern;
    if (m_pattern == 0) { //line
        m_goal.x = 1200;
        m_goal.y = 60;
    }
    else if (m_pattern == 1) { //half circle
        m_goal.x = 625;
        m_goal.y = 500;
    }
    else {
        m_goal.x = 0;
        m_goal.y = 0;
    }

    enemiesManager = manager;
    
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
    }
    else if (id == 2)
    {
        shape.setFillColor(sf::Color::Transparent);
    }
}

void Enemy::onExecute(int id, float dt)
{
    if (id == 0) //spawning
    { 
        //Moving
        sf::Vector2f movement(0.f, 0.f);
        if (shape.getPosition().y != 60) {
            movement.y += m_speed * dt;
        }
        else {
            toState(1);
        }
        shape.move(movement);

        sf::Vector2f pos = shape.getPosition();
        if (pos.y > 60) pos.y = 60;

        shape.setPosition(pos);

        //shooting

    }
    else if (id == 1) //alive
    {
        //Moving
        if (m_pattern == 0) {
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal.x && m_goal.x > 640) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal.x && m_goal.x < 640) {
                movement.x -= m_speed * dt;
            }
            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 1200) {
                m_goal.x = 80;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 80) {
                m_goal.x = 1200;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 80) pos.x = 80;
            if (pos.x > 1200) pos.x = 1200;

            shape.setPosition(pos);
        }
        else if (m_pattern == 1) { //pattern half circle
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal.x) {
                if (m_goal.x == 625){
                    movement.x += m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal.x == 1200) {
                    movement.x += m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
                if (m_goal.x == 80) {
                    movement.x -= m_speed * dt;
                }
            }

            shape.move(movement);
            
            if (shape.getPosition().x == m_goal.x && m_goal.x == 625) {
                m_goal.x = 1200;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 1200) {
                m_goal.x = 80;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 80) {
                m_goal.x = 625;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 80) pos.x = 80;
            if (pos.x > 1200) pos.x = 1200;
            if (pos.x > 623 && pos.x < 627) pos.x = 625;
            if (pos.y < 60) pos.y = 60;
            if (pos.y > 500) pos.y = 500;

            shape.setPosition(pos);
        }

        m_fireCooldown += dt;

        if (m_fireCooldown >= m_fireRate)
        {
            m_fireCooldown = 0.f;

            Bullet* bul = new Bullet();
            sf::Vector2f bulletPos = shape.getPosition();
            bulletPos.y += shape.getSize().y;
            bulletPos.x += 10;

            bul->initBullet(bulletPos);

            bul->SetSpeed(-400.f);

            enemiesManager->AddBullet(bul);


        }
    }
    else if (id == 2) //dead
    {
        
    }
}
