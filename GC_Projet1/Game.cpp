#include "Game.h"

#include "framework.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Bullet.h"

Game::Game()
{
    m_input = new Input();
    m_bullets = new std::vector<Bullet*>;
    m_player = new Player(m_input, m_bullets);
}

Game::~Game()
{
    delete m_input;
    delete m_bullets;
    delete m_player;
}

void Game::Run()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");
    window.setFramerateLimit(60);

    m_player->initPlayer();

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        

        m_timer.UpdateDeltaTime();
        m_input->update();
        m_player->Update(m_timer.getDeltaTime());

        //for (size_t i = 0)

        window.clear(sf::Color::Black);
        m_player->Draw(window);
        for (Bullet* b : (*m_bullets)) b->Draw(window);
        window.display();

    }
}
