#include <stdio.h>
#include <stdlib.h>

void ordem_crescente(int numeros[], int quantidade_numeros) {
    for(int i = 0; i < quantidade_numeros - 1; i++) {
        for(int j = 0; j < quantidade_numeros - i - 1; j++) {
            if(numeros[j] > numeros[j + 1]) {
                // troca os numeros de posicao
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}

int main (int argc, char* argv[]) {

    // Quantidade de numeros recebidos
    int quantidade_numeros = argc - 1;
    printf("Quantidade de numeros recebidos: %d\n", quantidade_numeros);
    

    // Valor medio dos numeros
    float soma = 0;
    
    for(int i = 1; i <= quantidade_numeros; i++) {
        int numeros = atoi(argv[i]);
        soma += numeros;
    }

    float media = soma / quantidade_numeros;

    printf("Media: %.1f\n", media);
    

    // MAIOR
    int maior = atoi(argv[1]);
    for(int i = 2; i <= quantidade_numeros; i++) {
        int numero_atual = atoi(argv[i]);
        if(numero_atual > maior) {
            maior = numero_atual;
        }
    }
    printf("Maior: %d\n", maior);

    // MENOR
    int menor = atoi(argv[1]);
    for(int i = 2; i <= quantidade_numeros; i++) {
        int numero_atual = atoi(argv[i]);
        if(numero_atual < menor) {
            menor = numero_atual;
        }
    }
    printf("Menor: %d\n", menor);

    // ORDEM CRESCENTE
    int numeros[quantidade_numeros];
    for(int i = 0; i < quantidade_numeros; i++) {
        numeros[i] = atoi(argv[i + 1]);
    }

    // chama a função para ordernar em ordem crescente
    ordem_crescente(numeros, quantidade_numeros);

    // imprime os numeros em ordem
    printf("Numeros em ordem crescente: ");
    for(int i = 0; i < quantidade_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    exit(0);
}