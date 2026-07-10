#include <sstream>
#include <iomanip>
#include "Product.h"

// Конструктор по умолчанию
Product::Product() : name(""), quantity(0), measure("шт"), price(0), status(false) {}

// Конструктор с параметрами
Product::Product(
    const std::string &name,
    float quantity,
    const std::string &measure,
    int price) : name(name),
                 quantity(quantity),
                 measure(measure),
                 price(price),
                 status(false) {}

// Методы
void Product::markAsPurchased()
{
    status = true;
}

void Product::markForPurchase()
{
    status = false;
}

// Строковое представление
std::string Product::toString() const
{
    std::ostringstream oss;
    oss << name << " | " 
        << quantity << ' ' << measure << " | "
        << "₽" << std::fixed << std::setprecision(2) << (float)price / 100
        << " | " << (status ? "[✓]" : "[ ]");
    return oss.str();
}