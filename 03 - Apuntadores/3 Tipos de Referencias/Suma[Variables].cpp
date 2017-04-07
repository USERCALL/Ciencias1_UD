#include <oistream>

/*al pasar los datos por variable este se copiado y duplicado*/
void sumar(int);
int main()
{
    int n = 4;
    sumar(n);
    std::cout << n << std::endl;
    system("pause");
    return 0;
}
void sumar(int x)
{
    x++;
    std::cout << x << std::endl;
}
