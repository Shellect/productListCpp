#include <iostream>
#include <sstream>
#include <string>
#include "Utils.h"

namespace Utils
{
    void clearScreen()
    {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif
    }

    void waitForEnter()
    {
        std::cout << "Нажмите [enter] для продолжения...";
        std::cin.get();
    }

    void clearInputBuffer()
    {
        std::cin.ignore(4096, '\n');
    }

    int getMenuChoice()
    {
        int menuOption;
        while (true)
        {
            std::cout << ">>> ";
            std::cin >> menuOption;
            if (std::cin.fail())
            {
                // Обработка ошибок
                std::cin.clear();
                clearInputBuffer();
                std::cout << "\nОшибка ввода! Попробуйте ещё раз.\n";
            }
            else
            {
                clearInputBuffer();
                return menuOption;
            }
        }
    } // getMenuChoice END

    int getIntInput(const std::string &prompt)
    {
        int value;
        while (true)
        {
            std::cout << prompt << "\n>>> ";
            std::cin >> value;

            if (std::cin.fail())
            {
                std::cin.clear();
                clearInputBuffer();
                std::cout << "\nОшибка ввода! Попробуйте ещё раз.\n";
            }
            else
            {
                clearInputBuffer();
                return value;
            }
        }
    } // getIntInput END

    float getFloatInput(const std::string &prompt)
    {
        float value;
        while (true)
        {
            std::cout << prompt << "\n>>> ";
            std::cin >> value;

            if (std::cin.fail())
            {
                std::cin.clear();
                clearInputBuffer();
                std::cout << "\nОшибка ввода! Попробуйте ещё раз.\n";
            }
            else
            {
                clearInputBuffer();
                return value;
            }
        }
    } // getIntInput END

    std::string getStringInput(const std::string &prompt)
    {
        std::string input;
        while (true)
        {
            std::cout << prompt << "\n>>> ";
            std::getline(std::cin, input);
            if (input.empty())
            {
                std::cout << "Ошибка ввода! Пустая строка.\n";
            }
            else
            {
                return input;
            }
        }
    } // getStringInput END

    std::string printPrompt(const std::string &prompt)
    {
        std::ostringstream oss;
        oss << "╔";
        for (int i = 0; i < std::size(prompt); i++)
        {
            oss << "═";
        }
        oss << "╗" << std::endl;
        oss << "║ " << prompt << ": ║" << std::endl;
        oss << "╚";
        for (int i = 0; i < std::size(prompt); i++)
        {
            oss << "═";
        }
        oss << "╝" << std::endl;
        oss << ">>> ";
        return oss.str();
    }

} // namespace Utils END
