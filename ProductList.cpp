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

/**
 * Сохраняет один отдельный продукт в файл
 */
void ProductList::writeProduct(std::ofstream &file, const Product &product)
{
    // Сохраняем имя продукта
    size_t len = product.name.size();
    file.write(reinterpret_cast<const char *>(&len), sizeof(len));
    file.write(product.name.c_str(), len); // c_str даёт char*, тут reinterpret_cast не нужен

    // Сохраняем количество
    file.write(reinterpret_cast<const char *>(&product.quantity), sizeof(product.quantity));

    // Сохраняем единицу измерения
    len = product.measure.size();
    file.write(reinterpret_cast<char *>(&len), sizeof(len));
    file.write(product.measure.c_str(), len);

    // Сохраняем цену
    file.write(reinterpret_cast<const char *>(&product.price), sizeof(product.price));

    // Сохраняем статус
    file.write(reinterpret_cast<const char *>(&product.status), sizeof(product.status));
}

/**
 * Читаем один отдельный продукт из файла
 */
bool ProductList::readProduct(std::ifstream &file, Product &product)
{
    // Читаем название
    size_t len = 0;
    if (!file.read(reinterpret_cast<char *>(&len), sizeof(len)))
        return false;
    product.name.resize(len);
    if (len > 0)
    {
        if (!file.read(&product.name[0], len))
            return false;
    }

    // Читаем количество
    if (!file.read(reinterpret_cast<char *>(&product.quantity), sizeof(product.quantity)))
        return false;

    // Читаем еденицу измерения
    len = 0;
    if (!file.read(reinterpret_cast<char *>(&len), sizeof(len)))
        return false;
    product.measure.resize(len);
    if (len > 0)
    {
        if (!file.read(&product.measure[0], len))
            return false;
    }

    // Читаем цену
    if (!file.read(reinterpret_cast<char *>(&product.price), sizeof(product.price)))
        return false;

    // Читаем статус    
    if (!file.read(reinterpret_cast<char *>(&product.status), sizeof(product.status)))
        return false;

    return true;
}

bool ProductList::saveList()
{
    // Открываем файл
    std::ofstream file("../dump_products", std::ios_base::binary);

    // Проверяем, открылся ли файл
    if (!file.is_open())
        return false;

    // 1. Пишем размер вектора с продуктами
    ssize_t size = products.size();
    file.write(reinterpret_cast<char *>(&size), sizeof(size));

    // 2. Пишем сырые данные всех элементов подряд
    for (const auto &p : products)
    {
        writeProduct(file, p);
    }

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
    if (!file.is_open())
        return false;

    // 1. Читаем размер
    size_t size = 0;
    file.read(reinterpret_cast<char *>(&size), sizeof(size));

    // 2. Выделяем место в векторе
    products.clear();
    products.resize(size);

    // 3. Читаем данные каждого продукта напрямую в память вектора
    for(size_t i = 0; i < size; i++) {
        if(!readProduct(file, products[i])) {
            file.close();
            return false;
        }
    }

    // Закрываем файл
    file.close();
    return true;
}
