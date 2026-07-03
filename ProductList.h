#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include <vector>
#include "Product.h"

class ProductList
{
private:
    std::vector<Product> products;

public:
    ProductList();
    ~ProductList();
    std::string show() const;
    void add();
    std::string remove();
};

#endif // PRODUCT_LIST_H