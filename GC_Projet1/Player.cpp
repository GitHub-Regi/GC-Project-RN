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
    shape.setSize(sf::Vector2f(playerSizeX, playerSizeY));
    shape.setOrigin({ playerOriginX, playerOriginY });
    shape.setPosition({ 620.f, 600.f });
    shape.setFillColor(playerColor);

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
        shape.setFillColor(playerColor);
    }
    else if (id == touched)
    {
        shape.setFillColor(playerColorImpact);
    }
    else if (id == dead)
    {
        shape.setFillColor(playerColorImpact);
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
    //Debug
    if (id == 0 && m_input->IsKeyDown('P'))
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

    //Shooting
    if (id == 0 && m_input->IsKeyDown(spaceBar))
    {
        sf::Vector2f bulletPos = shape.getPosition();
        bulletPos.y -= shape.getSize().y / 4.f;
        bulletPos.x += 15.f;;

        Bullet* bul = new Bullet();
        bul->initBullet(bulletPos, playerBulletsColor);
        m_bullets->push_back(bul);
        bul->SetSpeed(400.f);
    }

    //Movement
    sf::Vector2f playerMovement = sf::Vector2f(0.f, 0.f);

    if (id == alive || id == touched)
    {
        //Moving Right
        if (m_input->IsKey('D'))
        {
            playerMovement.x += speed * dt;
        }

        //Moving Left
        if (m_input->IsKey('Q'))
        {
            playerMovement.x -= speed * dt;
        }

        //Moving Up
        if (m_input->IsKey('Z'))
        {
            playerMovement.y -= speed * dt;
        }

        //Moving Down
        if (m_input->IsKey('S'))
        {
            playerMovement.y += speed * dt;
        }

        shape.move(playerMovement);

        //Movement clamping
        sf::Vector2f pos = shape.getPosition();
        sf::Vector2f size = shape.getSize();

        if (pos.x < 30) pos.x = 30;
        if (pos.y < 500) pos.y = 500;
        if (pos.x > 1250) pos.x = 1250;
        if (pos.y > 600) pos.y = 600;

        shape.setPosition(pos);
    }

    //Player hit -> 1 second invincibility
    if (id == 1 && m_stateTime >= 1.0f)
    {
        toState(0);
    }
}
