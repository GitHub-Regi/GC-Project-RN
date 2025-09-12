#include "Enemy.h"

Enemy::Enemy() : m_speed(), m_pattern(), m_goal()
{

}

Enemy::~Enemy()
{
}

void Enemy::initEnemy(int spawnX, int spawnY, int pattern, EnemiesManager* manager)
{
    shape.setSize(sf::Vector2f(enemySizeX, enemySizeY));
    shape.setOrigin({ enemyOriginX, enemyOriginY }); 
    shape.setFillColor(enemyColor);
    shape.setPosition({ float(spawnX), float(spawnY) }); 
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

}

void Enemy::onEnter(int id)
{
    //Hit
    if (id == 2) 
    {
        shape.setFillColor(sf::Color::Transparent);
    }
    //Crash
    else if (id == 3) 
    {
        shape.setFillColor(sf::Color::Red);
    }
}

void Enemy::onExecute(int id, float dt)
{
    //Spawning
    if (id == 0) 
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
    //Alive
    else if (id == 1)
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

        //Shooting
        m_fireCooldown += dt;

        if (m_fireCooldown >= m_fireRate)
        {
            m_fireCooldown = 0.f;

            Bullet* bul = new Bullet();
            sf::Vector2f bulletPos = shape.getPosition();
            bulletPos.y += shape.getSize().y;
            bulletPos.x += 10;

            bul->initBullet(bulletPos, enemyBulletsColor);

            bul->SetSpeed(-400.f);

            enemiesManager->AddBullet(bul);


        }
    }
    //Hit
    else if (id == 2)
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

        //Hit animation
        if (m_stateTime >= 0.1f)
        {
            shape.setFillColor(enemyColor);
        }
        if (m_stateTime >= 0.2f)
        {
            shape.setFillColor(sf::Color::Transparent);
        }
        if (m_stateTime >= 0.3f)
        {
            shape.setFillColor(enemyColor);
            toState(1);
        }
    }
}
