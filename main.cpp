#include "cola.h"

int main()
{
    cola MiCola;
    alumno x;
    for(int i = 1; i <= 2; i++){
        std::cin >> x;
        MiCola.enqueue(x);
    }
    for(int i = 1; i <= 2; i++)
        std::cout << MiCola.dequeue();

    return 0;
}
