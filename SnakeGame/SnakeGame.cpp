#include <iostream>

#include "GameMode.h"

void ShowMenu()
{
    std::cout << "Welcome to the snake game!" << std::endl;
    std::cout << "Use - w, a, s, d for move." << std::endl;
    std::cout << "Press 1 to start the game." << std::endl;
    std::cout << "Press 0 to exit the game." << std::endl;
}

int main()
{
    int n;
    GameMode gameMode;
    ShowMenu();

    std::cin >> n;
    switch (n)
    {
    case 1:
        gameMode.GameLoop();
        break;
    case 0:
        break;
    }
}