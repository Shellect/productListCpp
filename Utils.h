#ifndef UTILS_H
#define UTILS_H

namespace Utils
{
    void clearScreen();

    void waitForEnter();

    void clearInputBuffer();

    int getMenuChoice();

    int getIntInput(const std::string &prompt);

    float getFloatInput(const std::string &prompt);

    std::string getStringInput(const std::string &prompt);

    std::string printPrompt(const std::string &prompt);

} // namespace Utils

#endif