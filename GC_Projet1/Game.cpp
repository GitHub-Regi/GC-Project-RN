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

        std::vector<Bullet*> bullets;

        timer.UpdateDeltaTime();
        player.Update(timer.getDeltaTime(), input, bullets);
        input.update();

        //for (size_t i = 0)

        window.clear(sf::Color::Black);
        player.Draw(window);
        for (auto b : bullets) b->Draw(window);
        window.display();

    }
}
