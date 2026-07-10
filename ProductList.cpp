#include <fstream>
#include <iostream>
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

std::string ProductList::togglePurchased()
{
    int productIndex = Utils::getIntInput("Введите номер продукта для покупки\n");
    if (productIndex > products.size() || productIndex <= 0) 
    {
        return "Такого продукта не существует!";
    }
    products[productIndex - 1].markAsPurchased();
    return products[productIndex - 1].toString();
}

bool ProductList::saveList()
{
    // Открываем файл
    std::ofstream file("../dump_products", std::ios_base::binary);

    // Проверяем, открылся ли файл
    if (!file.is_open()) return false;

    // 1. Пишем размер вектора с продуктами
    ssize_t size = products.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));

    // 2. Пишем сырые данные всех элементов подряд
    file.write(reinterpret_cast<const char*>(products.data()), products.size() * sizeof(Product));

    // Закрываем файл 
    // При уничтожении объекта закроется автоматически
    file.close();
    return true;
}

bool ProductList::readList()
{
    // Открываем файл
    std::ifstream file("../dump_products", std::ios_base::binary);

    // Проверяем, открылся ли файл
    if (!file.is_open()) return false;

    // 1. Читаем размер
    size_t size = 0;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    // 2. Выделяем место в векторе
    products.resize(size);

    // 3. Читаем данные напрямую в память вектора 
    file.read(reinterpret_cast<char*>(products.data()), size * sizeof(Product));
    
    // Закрываем файл
    file.close();
    return true;
}
