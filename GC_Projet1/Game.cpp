#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Run()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");
    window.setFramerateLimit(60);

    Timer timer;
    Input input;
    Player player;

    while (window.isOpen())
    {

        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        timer.UpdateDeltaTime();
        player.Update(timer.getDeltaTime(), input);
        input.update();

        window.clear(sf::Color::Black);
        player.Draw(window);
        window.display();

    }
}
