#ifndef MENU_H
#define MENU_H
#include <array>
#include <string>

class Menu
{
private:
    int menuOption;
    std::array<std::string, 7> menu = {
        "Выход",
        "Добавить новый продукт",
        "Посмотреть список",
        "Удалить товар",
        "Отметить купленным",
        "Сохранить",
        "Загрузить"
    };

public:
    Menu();
    ~Menu();
    void show();
};

#endif
