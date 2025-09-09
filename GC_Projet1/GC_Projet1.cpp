// GC_Projet1.cpp : Définit le point d'entrée de l'application.
//

#include "framework.h"
#include "GC_Projet1.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "Player.h"
#include "Input.h"
#include "Timer.h"
#include "Resource.h"




int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{

    //App* pApp = new App;
    //App->Run();
    //delete pApp;
    //return 0;

    sf::RenderWindow window(sf::VideoMode({ 1280, 720  }), "SFML works!");
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

        float dt = timer.GetDeltaTime();
        player.Update(dt, input);
        input.update();

        window.clear(sf::Color::Black);
        player.Draw(window);
        window.display();

    }
}

    