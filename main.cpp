#include "Application.h"
#include <iostream>     

const int P_CONST = 31;
const int M_CONST = 1e9 + 7;

int main()
{
    Application app;
    app.run(P_CONST, M_CONST);
    
    return 0;
}