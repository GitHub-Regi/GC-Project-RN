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
    shape.setOrigin({ 20.f, 70.f });
    shape.setFillColor(sf::Color::Green);
    shape.setPosition({ 640.f, 650.f });
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
    if (id == 0 && m_input->IsKeyDown(32))
    {
        sf::Vector2f bulletPos = shape.getPosition();
        bulletPos.y -= shape.getSize().y / 2;
        bulletPos.x -= 25;

        Bullet* bul = new Bullet();
        bul->initBullet(bulletPos);
        m_bullets->push_back(bul);
    }

    if (id == 0 && m_input->IsKeyDown('P'))
    {
        currentHealth -= 20.f;

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

    if (id == 0 || id == 1)
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
        if (pos.y < 550) pos.y = 550;
        if (pos.x > 1250) pos.x = 1250;
        if (pos.y > 650) pos.y = 650;

        shape.setPosition(pos);
    }

    if (id == 1 && m_stateTime >= 1.0f)
    {
        toState(0);
    }

    if (id == 2 && m_stateTime >= 1.0f)
    {
        //Destruction du joueur dans Game
    }
}
