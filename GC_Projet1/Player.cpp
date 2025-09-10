#include "Player.h"

Player::Player()
{
    shape.setSize(sf::Vector2f(40, 70));
    shape.setOrigin({ 20.f, 70.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 640.f, 700.f });
    speed = 350.f;

    toState(0);
}

Player::~Player()
{

}

void Player::Update(float dt, Input& input, std::vector<Bullet*>& bullets)
{
    UpdateStateTime(dt);
    onExecute(m_currentState, dt);

    //Shooting  
    if (m_currentState == 0 && input.IsKeyDown(32))
    {
        sf::Vector2f bulletPos(shape.getPosition());
        bulletPos.x -= shape.getSize().x / 2.f;
        bulletPos.y -= shape.getSize().y;
        bullets.push_back(new Bullet(bulletPos));
    }
}

void Player::onExit(int id)
{

}

void Player::onEnter(int id)
{
    if (id == 0)
    {
        shape.setFillColor(sf::Color::Green);
    }
    else if (id == 1)
    {
        shape.setFillColor(sf::Color::Yellow);
    }
    else if (id == 2)
    {
        shape.setFillColor(sf::Color::Red);
    }

    m_stateTime = 0.f;
}

void Player::onExecute(int id, float dt)
{
    sf::Vector2f movement(0.f, 0.f);

    if (id == 0 || id == 1)
    {
        
    }
    else if (id == 2)
    {
        
    }
}
/*
    //Moving Right
    if (input.IsKey('D'))
    {
        movement.x += speed * dt;
    }
    if (input.IsKeyDown('D')) {
        movement.x += speed * dt;
    }

    //Moving Left
    if (input.IsKey('Q'))
    {
        movement.x -= speed * dt;
    }
    if (input.IsKeyDown('Q')) {
        movement.x -= speed * dt;
    }

    //Moving Up
    if (input.IsKey('Z'))
    {
        movement.y -= speed * dt;
    }
    if (input.IsKeyDown('Z')) {
        movement.y -= speed * dt;
    }

    //Moving Down
    if (input.IsKey('S'))
    {
        movement.y += speed * dt;
    }
    if (input.IsKeyDown('S')) {
        movement.y += speed * dt;
    }

    shape.move(movement);

    sf::Vector2f pos = shape.getPosition();
    sf::Vector2f size = shape.getSize();

    if (pos.x < 30) pos.x = 30;
    if (pos.y < 550) pos.y = 550;
    if (pos.x > 1250) pos.x = 1250;
    if (pos.y > 700) pos.y = 700;

    shape.setPosition(pos);
}
*/
