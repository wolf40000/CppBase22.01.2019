#include <iostream>
#include <iomanip>
#include "mylib.h"

int main()
{
    std::cout << Mylib::exponentiation(10, 2) << std::endl;
    std::cout << Mylib::exponentiation(100, -1) << std::endl;
    std::cout << Mylib::exponentiation(100, 2.0) << std::endl;

    std::cout << std::boolalpha << Mylib::fuzzyCompare(4.5, 4.50000000000000000001) << std::endl;


    return 0;
}
