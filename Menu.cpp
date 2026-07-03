#include "Menu.h"
#include "Utils.h"
#include <iostream>
Menu::Menu() {}
Menu::~Menu() {}
void Menu::show()
{
    Utils::clearScreen();
    std::printf("%35s", "Список покупок\n");
    for (int i = 1; i < std::size(menu); i++)
    {
        std::cout << i << ". " << menu[i] << std::endl;
    }
    std::cout << "0. " << menu[0] << std::endl;
}
