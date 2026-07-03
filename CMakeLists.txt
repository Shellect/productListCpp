# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(ProductListApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем статическую библиотеку из ядра проекта
add_library(product_lib STATIC
    Product.cpp
    ProductList.cpp
    Utils.cpp
    Menu.cpp
)

# Публичные заголовки
target_include_directories(product_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Исполняемый файл использует библиотеку
add_executable(app main.cpp)
target_link_libraries(app PRIVATE product_lib)