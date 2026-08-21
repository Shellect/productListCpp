#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include <vector>
#include "Product.h"

class ProductList
{
private:
    std::vector<Product> products;
    void writeProduct(std::ofstream &file, const Product &product);
    bool readProduct(std::ifstream &file, Product &product);

public:
    ProductList();
    ~ProductList();
    std::string show() const;
    void add();
    std::string remove();
    /**
     * @brief Отмечает продукт купленным
     * @details Если продукт ещё был не куплен -
     * отмечает его купленным (ставит status = true).
     * @return Возвращает строку с купленным товаром (название, количество, статус)
     */
    std::string togglePurchased();
    bool saveList();
    bool readList();
};

#endif // PRODUCT_LIST_H