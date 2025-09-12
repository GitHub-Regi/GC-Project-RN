#include "Player.h"

Player::Player() 
{
}

Player::Player(Input* input, std::vector<Bullet*>* bullets)
{
    m_input = input;
    m_bullets = bullets;
}

Player::~Player()
{

}

void Player::initPlayer(){
    shape.setSize(sf::Vector2f(40, 70));
    shape.setOrigin({ 0.f, 0.f });
    shape.setFillColor(sf::Color(34, 139, 34, 255));
    shape.setPosition({ 620.f, 600.f });
    speed = 350.f;

    currentHealth = maxHealth;

    toState(0);
}

void Player::Update(float dt)
{
    UpdateStateTime(dt);
    onExecute(m_currentState, dt);   
}

void Player::onExit(int id)
{

}

void Player::onEnter(int id)
{
    if (id == alive)
    {
        shape.setFillColor(sf::Color(34, 139, 34, 255));
    }
    else if (id == touched)
    {
        shape.setFillColor(sf::Color(255, 215, 0, 255));
    }
    else if (id == dead)
    {
        shape.setFillColor(sf::Color::Red);
    }

    m_stateTime = 0.f;
}

void Player::onExecute(int id, float dt)
{
    if (id == alive && m_input->IsKeyDown(32))
    {
        sf::Vector2f bulletPos = shape.getPosition();
        bulletPos.y -= shape.getSize().y / 4;
        bulletPos.x += 15;

        Bullet* bul = new Bullet();
        bul->initBullet(bulletPos, sf::Color(30, 144, 255, 255));
        m_bullets->push_back(bul);
        bul->SetSpeed(400.f);
    }

    if (id == alive && m_input->IsKeyDown('P'))
    {
        currentHealth -= 100.f;

        if (currentHealth <= 0.f)
        {
            toState(2);
        }
        else
        {
            toState(1);

        }
    }

    sf::Vector2f movement(0.f, 0.f);

    if (id == alive || id == touched)
    {
        //Moving Right
        if (m_input->IsKey('D'))
        {
            movement.x += speed * dt;
        }
        if (m_input->IsKeyDown('D')) {
            movement.x += speed * dt;
        }

        //Moving Left
        if (m_input->IsKey('Q'))
        {
            movement.x -= speed * dt;
        }
        if (m_input->IsKeyDown('Q')) {
            movement.x -= speed * dt;
        }

        //Moving Up
        if (m_input->IsKey('Z'))
        {
            movement.y -= speed * dt;
        }
        if (m_input->IsKeyDown('Z')) {
            movement.y -= speed * dt;
        }

        //Moving Down
        if (m_input->IsKey('S'))
        {
            movement.y += speed * dt;
        }
        if (m_input->IsKeyDown('S')) {
            movement.y += speed * dt;
        }

        shape.move(movement);

        sf::Vector2f pos = shape.getPosition();
        sf::Vector2f size = shape.getSize();

        if (pos.x < 30) pos.x = 30;
        if (pos.y < 500) pos.y = 500;
        if (pos.x > 1250) pos.x = 1250;
        if (pos.y > 600) pos.y = 600;

        shape.setPosition(pos);
    }

    if (id == touched && m_stateTime >= 1.0f)
    {
        toState(0);
    }

    if (id == dead && m_stateTime >= 1.0f)
    {
        //Destruction du joueur dans Game
    }
}
