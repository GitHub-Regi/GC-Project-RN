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
    if (m_pattern == line) {
        m_goal = left;
    }
    else if (m_pattern == triangle) {
        m_goal = midXForShape;
    }
    else if (m_pattern == lineMirror) { //line
        m_goal = right;
    }
    else if (m_pattern == triangleMirror) { //half circle
        m_goal = midXForShape;
    }
    else {
        m_goal = 0;
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
    if (id == touched) 
    {
        shape.setFillColor(sf::Color::Transparent);
    }
}

void Enemy::onExecute(int id, float dt)
{
    if (id == spawning)
    { 
        //Moving
        sf::Vector2f movement(0.f, 0.f);
        if (shape.getPosition().y != top) {
            movement.y += m_speed * dt;
        }
        else {
            toState(1);
        }
        shape.move(movement);

        sf::Vector2f pos = shape.getPosition();
        if (pos.y > top) pos.y = top;

        shape.setPosition(pos);
    }
    else if (id == alive)
    {
        //Moving
        if (m_pattern == line) {
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal && m_goal > midX) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal && m_goal < midX) {
                movement.x -= m_speed * dt;
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;

            shape.setPosition(pos);
        }
        else if (m_pattern == triangle) {
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal) {
                if (m_goal == midXForShape){
                    movement.x += m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal == right) {
                    movement.x += m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
                if (m_goal == left) {
                    movement.x -= m_speed * dt;
                }
            }

            shape.move(movement);
            
            if (shape.getPosition().x == m_goal && m_goal == midXForShape) {
                m_goal = right;
            }
            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = midXForShape;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;
            if (pos.x > midXForShape - 2 && pos.x < midXForShape + 2) pos.x = midXForShape;

            shape.setPosition(pos);
        }

        if (m_pattern == lineMirror) {
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal && m_goal > midX) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal && m_goal < midX) {
                movement.x -= m_speed * dt;
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;

            shape.setPosition(pos);
        }
        else if (m_pattern == triangleMirror) {
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal) {
                if (m_goal == midXForShape) {
                    movement.x -= m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal == right) {
                    movement.x += m_speed * dt;
     
                }
                if (m_goal == left) {
                    movement.x -= m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == midXForShape) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }
            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = midXForShape;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;
            if (pos.x > midXForShape - 2 && pos.x < midXForShape + 2) pos.x = midXForShape;

            shape.setPosition(pos);
        }
        else if (m_pattern == debugPattern) {

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
    else if (id == touched)
    {
        //Moving
        if (m_pattern == line) {
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal && m_goal > midX) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal && m_goal < midX) {
                movement.x -= m_speed * dt;
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;

            shape.setPosition(pos);
        }
        else if (m_pattern == triangle) {
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal) {
                if (m_goal == midXForShape) {
                    movement.x += m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal == right) {
                    movement.x += m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
                if (m_goal == left) {
                    movement.x -= m_speed * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == midXForShape) {
                m_goal = right;
            }
            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = midXForShape;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;
            if (pos.x > midXForShape - 2 && pos.x < midXForShape + 2) pos.x = midXForShape;

            shape.setPosition(pos);
        }

        if (m_pattern == lineMirror) {
            sf::Vector2f movement(0.f, 0.f);
            if (shape.getPosition().x != m_goal && m_goal > midX) {
                movement.x += m_speed * dt;
            }
            if (shape.getPosition().x != m_goal && m_goal < midX) {
                movement.x -= m_speed * dt;
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;

            shape.setPosition(pos);
        }
        else if (m_pattern == triangleMirror) {
            sf::Vector2f movement(0.f, 0.f);

            if (shape.getPosition().x != m_goal) {
                if (m_goal == midXForShape) {
                    movement.x -= m_speed * dt;
                    movement.y += m_speed / 1.8f * dt;
                }
                if (m_goal == right) {
                    movement.x += m_speed * dt;

                }
                if (m_goal == left) {
                    movement.x -= m_speed * dt;
                    movement.y -= m_speed / 1.8f * dt;
                }
            }

            shape.move(movement);

            if (shape.getPosition().x == m_goal && m_goal == midXForShape) {
                m_goal = left;
            }
            if (shape.getPosition().x == m_goal && m_goal == left) {
                m_goal = right;
            }
            if (shape.getPosition().x == m_goal && m_goal == right) {
                m_goal = midXForShape;
            }

            sf::Vector2f pos = shape.getPosition();
            if (pos.x < left) pos.x = left;
            if (pos.x > right) pos.x = right;
            if (pos.x > midXForShape - 3 && pos.x < midXForShape + 3) pos.x = midXForShape;

            shape.setPosition(pos);
        }
        else if (m_pattern == debugPattern) {

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
