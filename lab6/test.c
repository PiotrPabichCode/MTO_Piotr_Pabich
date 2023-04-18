#include <stdio.h>

int main() {
    int num = 233;

    // drugie mniejsze - brak zer
    // drugie wieksze - dopisanie zer
    // później sprawdzenie spacji
    // dopisanie z tyłu jeśli ujemna
    // dopisanie z przodu jeśli dodatnia

    printf("[%-6.2d]\n", num);
    printf("[%6d]\n", num);

    return 0;
}