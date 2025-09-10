// GC_Projet1.cpp : Définit le point d'entrée de l'application.
//

#include "Game.h"
#include "framework.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    Game* game = new Game;
    game->Run();
    delete game;
    return 0;
}

    