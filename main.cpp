#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <string>
#include "Product.h"
#include "ProductList.h"
#include "Utils.h"
#include "Menu.h"
int main()
{
    int menuOption;
    Menu menu = Menu();
    ProductList productList;

    do
    {
        menu.show();
        menuOption = Utils::getMenuChoice();
        switch (menuOption)
        {
        case 1:
            productList.add();
        case 2:
            std::cout << productList.show();
            break;
        case 3:
            std::cout << productList.remove();
            break;
        case 4:
            break;
        case 0:
            std::cout << "Выход из программы. До новых встреч!\n";
            return 0;

        default:
            std::cout << "Выбран несуществующий пункт меню!\n";
        }
        Utils::waitForEnter();
    } while (menuOption != 0);

    return 0;
}