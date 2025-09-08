#include "Player.h"
#include "Timer.h"
#include <SFML/Graphics.hpp>

Player::Player()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "SFML works!");
    sf::RectangleShape playerShip({ 20.f, 100.f });
    playerShip.setFillColor(sf::Color::Green);

    playerShip.setOrigin({ 10.f, 100.f });
    playerShip.setPosition({ 640.f, 650.f});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear();
        window.draw(playerShip);
        window.display();
    }
}

Player::~Player()
{

}
void Player::MovePlayer()
{

}

