#include "Game.h"

#include "framework.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"

Game::Game()
    : window(sf::VideoMode({ 1280, 720 }), "SFML works!")
{
    m_input = new Input();
    m_bullets = nullptr;
    m_player = nullptr;
    toState(0);
}

Game::~Game()
{
    delete m_input;
    delete m_bullets;
    delete m_player;
}

void Game::Run()
{
    window.setFramerateLimit(60);

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        
        float dt = m_timer.getDeltaTime();
        m_timer.UpdateDeltaTime();
        m_input->update();

        UpdateStateTime(dt);
        onExecute(m_currentState, dt);
    }
}

void Game::onExit(int id)
{
    if (id == 0)
    {

    }
    else if (id == 1)
    {
        m_bullets->clear();
        m_enemiesManager.m_enemies.clear();
    }
    else if (id == 2)
    {

    }
}

void Game::onEnter(int id)
{
    if (id == 0)
    {
        
    }
    else if (id == 1)
    {
        m_bullets = new std::vector<Bullet*>;
        m_player = new Player(m_input, m_bullets);
        m_player->initPlayer();
        m_enemiesManager.initEnemies(10, 1);
    }
    else if (id == 2)
    {
      
    }
}

void Game::onExecute(int id, float dt)
{
    window.clear();

    if (id == 0)
    {
        sf::Font font;
        font.openFromFile("golden_varsity/Golden Varsity Regular.ttf");
        sf::Text text(font);
        text.setString("Press Enter");
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::Red);
        text.setPosition(sf::Vector2f(300.f, 350.f));
        window.draw(text);

        if (m_input->IsKeyDown(VK_RETURN))
        {
            toState(1);
        }
    }
    else if (id == 1)
    {
        m_player->Update(dt);
        m_enemiesManager.updateEnemies(dt);

        for (Bullet* b: (*m_bullets))
        {
            b->Update(dt);

            /*if (b->GetPos().y + b->GetSize().y < 0)
            {
                b->toState(2);
            }*/
        }

        for (auto it = (*m_bullets).begin(); it != (*m_bullets).end();)
        {
            if ((*it)->GetState() == 2)
            {
                delete *it;
                it = (*m_bullets).erase(it);
            }
            else
            {
                ++it;
            }
        }
;       
        m_player->Draw(window);
        m_enemiesManager.drawEnemies(window);
        for (Bullet* b : (*m_bullets)) b->Draw(window);

        if (m_player->GetState() == 2)
        {
            if (m_player->GetStateTime() >= 1.0f)
            {
                toState(2);
            }
        }
        
    }
    else if (id == 2)
    {
        sf::Font font;
        font.openFromFile("golden_varsity/Golden Varsity Regular.ttf");
        sf::Text text(font);
        text.setString("Game Over !\n Try Again ?");
        text.setCharacterSize(100);
        text.setFillColor(sf::Color::Red);
        text.setPosition(sf::Vector2f(300.f, 350.f));
        window.draw(text);

        if (m_input->IsKeyDown(VK_RETURN))
        {
            toState(1);
        }
    }
    window.display();
}

        

    

