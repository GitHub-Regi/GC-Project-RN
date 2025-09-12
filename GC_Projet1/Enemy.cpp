#include "Enemy.h"

Enemy::Enemy() : m_speed(), m_pattern(), m_goal()
{
}

Enemy::~Enemy()
{
}

void Enemy::initEnemy(int spawnX, int spawnY, int pattern)
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
        m_goal.x = 25;
        m_goal.y = 60;
    }
    else if (m_pattern == 1) { //half circle
        m_goal.x = 625;
        m_goal.y = 500;
    }
    else if (m_pattern == 2) { //line
        m_goal.x = 1225;
        m_goal.y = 60;
    }
    else if (m_pattern == 3) { //half circle
        m_goal.x = 625;
        m_goal.y = 500;
    }
    else {
        m_goal.x = 0;
        m_goal.y = 0;
    }
    
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
    else if (id == 2)
    {
        //shape.setFillColor(sf::Color::Magenta);
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
    else if (id == 2) //touch
    {
        shape.setFillColor(sf::Color::Transparent);
    }
    else if (id == 3) //dead
    {
        shape.setFillColor(sf::Color::Red);
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
    }
    else if (id == 1) //alive
    {

        //Moving
        if (m_pattern == 0) { //pattern line
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal.x && m_goal.x > 640) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal.x && m_goal.x < 640) {
                movement.x -= m_speed * dt;
            }
            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;

            shape.setPosition(pos);
        }
        else if (m_pattern == 1) { //pattern half circle
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal.x) {
                if (m_goal.x == 625){
                    movement.x += m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal.x == 1225) {
                    movement.x += m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
                if (m_goal.x == 25) {
                    movement.x -= m_speed * dt;
                }
            }

            shape.move(movement);
            
            if (shape.getPosition().x == m_goal.x && m_goal.x == 625) {
                m_goal.x = 1225;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 625;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;
            if (pos.x > 623 && pos.x < 627) pos.x = 625;
            if (pos.y < 60) pos.y = 60;
            if (pos.y > 500) pos.y = 500;

            shape.setPosition(pos);
        }
        //Moving
        if (m_pattern == 2) { // pattern line mirror
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal.x && m_goal.x > 640) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal.x && m_goal.x < 640) {
                movement.x -= m_speed * dt;
            }
            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;

            shape.setPosition(pos);
        }
        else if (m_pattern == 3) { //pattern half circle mirror
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal.x) {
                if (m_goal.x == 625) {
                    movement.x -= m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal.x == 1225) {
                    movement.x += m_speed * dt;
     
                }
                if (m_goal.x == 25) {
                    movement.x -= m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 625) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 625;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;
            if (pos.x > 623 && pos.x < 627) pos.x = 625;
            if (pos.y < 60) pos.y = 60;
            if (pos.y > 500) pos.y = 500;

            shape.setPosition(pos);
        }
        else if (m_pattern == 4) { //test pattern

        }

        //shooting
    }
    else if (id == 2) //touch
    {
        //Moving
        if (m_pattern == 0) { //pattern line
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal.x && m_goal.x > 640) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal.x && m_goal.x < 640) {
                movement.x -= m_speed * dt;
            }
            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;

            shape.setPosition(pos);
        }
        else if (m_pattern == 1) { //pattern half circle
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal.x) {
                if (m_goal.x == 625) {
                    movement.x += m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal.x == 1225) {
                    movement.x += m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
                if (m_goal.x == 25) {
                    movement.x -= m_speed * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 625) {
                m_goal.x = 1225;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 625;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;
            if (pos.x > 623 && pos.x < 627) pos.x = 625;
            if (pos.y < 60) pos.y = 60;
            if (pos.y > 500) pos.y = 500;

            shape.setPosition(pos);
        }
        //Moving
        if (m_pattern == 2) { // pattern line mirror
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal.x && m_goal.x > 640) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal.x && m_goal.x < 640) {
                movement.x -= m_speed * dt;
            }
            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;

            shape.setPosition(pos);
        }
        else if (m_pattern == 3) { //pattern half circle mirror
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal.x) {
                if (m_goal.x == 625) {
                    movement.x -= m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal.x == 1225) {
                    movement.x += m_speed * dt;

                }
                if (m_goal.x == 25) {
                    movement.x -= m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal.x && m_goal.x == 625) {
                m_goal.x = 25;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 25) {
                m_goal.x = 1225;
            }
            if (shape.getPosition().x == m_goal.x && m_goal.x == 1225) {
                m_goal.x = 625;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < 25) pos.x = 25;
            if (pos.x > 1225) pos.x = 1225;
            if (pos.x > 622 && pos.x < 628) pos.x = 625;
            if (pos.y < 60) pos.y = 60;
            if (pos.y > 500) pos.y = 500;

            shape.setPosition(pos);
        }
        else if (m_pattern == 4) { //test pattern

        }

        //touch animation

        if (m_stateTime >= 0.1f)
        {
            shape.setFillColor(sf::Color::Magenta);
        }
        if (m_stateTime >= 0.2f)
        {
            shape.setFillColor(sf::Color::Transparent);
        }
        if (m_stateTime >= 0.3f)
        {
            shape.setFillColor(sf::Color::Magenta);
            //this->SetCurrentHealth(-20);
            toState(1);
        }
    }
    else if (id == 3) //dead
    {
        
    }
}
