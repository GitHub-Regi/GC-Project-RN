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
    shape.setPosition({ 640.f, 700.f });
}

void Player::Update(float dt)
{
    float speed = 400.0f;
    sf::Vector2f movement(0.f, 0.f);

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
    if (pos.y > 700) pos.y = 700;

    shape.setPosition(pos);

    //Shooting  
    if (m_input->IsKeyDown(32))
    {
        sf::Vector2f bulletPos(pos.x, pos.y + size.y);
        Bullet* bul = new Bullet();
        bul->initBullet(bulletPos);
        m_bullets->push_back(bul);
    }
}

