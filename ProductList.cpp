#include <sstream>
#include "ProductList.h"
#include "Utils.h"

ProductList::ProductList() {}

ProductList::~ProductList() {}

std::string ProductList::show() const
{
    if (std::size(products) == 0)
    {
        return "Тут пока пусто...\n";
    }

    std::ostringstream oss;
    for (size_t i = 0; i < products.size(); i++)
    {
        oss << '|' << i + 1 << '|' << products[i].toString()
            << '|' << std::endl;
    }

    return oss.str();
}

void ProductList::add()
{
    std::string name = Utils::getStringInput("Введите название товара");
    float quantity = Utils::getFloatInput("Введите количество");
    std::string measure = Utils::getStringInput("Введите меру измерения");
    int price = Utils::getIntInput("Введите цену в копейках");

    Product product = Product{name, quantity, measure, price};
    products.push_back(product);
}

std::string ProductList::remove()
{
    int productIndex = Utils::getIntInput("Введите номер продукта для удаления\n");
    if (productIndex > products.size() || productIndex <= 0) 
    {
        return "Такого продукта не существует!";
    }
    products.erase(products.begin() + productIndex - 1);
    return "Продукт успешно удалён\n";
}