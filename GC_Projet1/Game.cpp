#include "Game.h"

Game::Game()
    : window(sf::VideoMode({ 1280, 720 }), "SFML works!")
{
    toState(0);
}

Game::~Game()
{
    for (auto b : bullets) delete b;
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

        float dt = timer.getDeltaTime();
        timer.UpdateDeltaTime();
        input.update();

        UpdateStateTime(dt);
        onExecute(m_currentState, dt);
    }
}

void Game::onExit(int id)
{
    
}

void Game::onEnter(int id)
{
    if (id == 0)
    {
        
    }
    else if (id == 1)
    {
        player = Player();

        for (auto b : bullets) delete b;
        bullets.clear();
    }
    else if (id == 2)
    {
        
    }
}

void Game::onExecute(int id, float dt)
{
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

        if (input.IsKeyDown(VK_RETURN))
        {
            toState(1);
        }
    }
    else if (id == 1)
    {
        player.Update(dt, input, bullets);

        for (auto b : bullets)
        {
            b->Update(dt, input, bullets);

            if (b->GetPos().y + b->GetSize().y < 0)
            {
                b->toState(2);
            }
        }

        for (auto it = bullets.begin(); it != bullets.end(); )
        {
            if ((*it)->GetState() == 2)
            {
                delete *it;
                it = bullets.erase(it);
            }
            else
            {
                ++it;
            }
        }

        window.clear(sf::Color::Black);
        player.Draw(window);
        for (auto b : bullets) b->Draw(window);

        if (player.GetPos().x + player.GetSize().x < 100)
        {
            toState(2);
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

        if (input.IsKeyDown(VK_RETURN))
        {
            toState(1);
        }
    }
    window.display();
}

        

    

