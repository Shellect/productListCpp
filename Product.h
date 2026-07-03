#ifndef PROD_H
#define PROD_H

#include <string>

struct Product
{
    std::string name;
    int quantity;
    std::string measure;
    int price;
    bool status;

    Product();
    Product(
        const std::string& name, 
        float quantity,
        const std::string& measure, 
        int price
    );

    void markAsPurchased();
    void markForPurchase();

    // Вывод строкового представления
    std::string toString() const;
};

#endif