#include <iostream>



void sumar(int *);
int main()
{
    int n = 4;
    sumar(&n);
    std::cout << n << std::endl;
    system("pause");
    return 0;
}

void sumar(int *x)
{
    *x = *x + 1;
    std::cout << *x << std::endl;
}
