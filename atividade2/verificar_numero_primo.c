#include <stdio.h>
#include <stdlib.h>

int main (int argc, char* argv[]) {
    int numero = atoi(argv[1]);
    if(numero <= 1) {
        printf("False");
        exit(0);
    } 
    else if(numero == 2) {
        printf("True");
        exit(0);
    } 
    else if(numero > 2) {
        int verificao = numero % 2; // resto da divisao por 2

        if(verificao == 0) { // se o resto da divisao por 2 der 0, significa que nao e primo
            printf("False");
            exit(0);
        } else {
            printf("True"); // se o resto for diferente de 0, é primo, divisivel por 1 e por ele mesmo
            exit(0);
        }
    }

    exit(0);
}