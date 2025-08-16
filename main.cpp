#include "Application.h"
#include <iostream>     

const int P_CONST = 31;
const int M_CONST = 1e9 + 7;

int main()
{
    std::string filename;
    std::cout << "Enter the filename to search in: ";
    std::cin >> filename;

    Application app(filename, P_CONST, M_CONST);
    app.run();
    
    return 0;
}