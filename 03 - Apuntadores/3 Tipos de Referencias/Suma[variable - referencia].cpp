#include <iostrema>

/*
Paso por referencia... con referencias

Las referencias son una buena forma de pasar un valor a otra funci�n sin ser por valor,
veamos el ejemplo anterior de paso por punteros, pero est� vez usando referencias.
*/

void sumar(int &);
int main()
{
    int n = 4;
    sumar(n);
    std::cout << n << std::endl;
    system("pause");
    return 0;
}
void sumar(int &x)
{
    x = x + 1;
    std::cout << x << std::endl;
}
