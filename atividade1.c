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
    float soma = 0;
    float media = 0;
    int menor = atoi(argv[1]);
    int maior = atoi(argv[1]);
    
    
    for(int i = 1; i <= quantidade_numeros; i++) {
        int numero_convertido = atoi(argv[i]);
        soma += numero_convertido;

        //menor
        if(menor > numero_convertido) {
            menor = numero_convertido;
        }
        //maior
        if(maior < numero_convertido) {
            maior = numero_convertido;
        }
    }

    media = soma / quantidade_numeros;

    printf("Media: %.1f\n", media);
    printf("Maior: %d\n", maior);
    printf("Menor: %d\n", menor);
    printf("Quantidade de numeros recebidos: %d\n", quantidade_numeros);

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


/*
ordenacao - outra forma

int vetor-ord-n[quantidade-NUMEROS];


for(int i = 1; i <= quantidade_NUMEROS; i++) { FOR PRINCIPAL NA MAIN
    vetor-ord-n[]
}

for(int i = 0; i < qtd-n-1; i++) {
    for(int j = i; i < qtd-n; j++) {
        if(vetor-ord-n[i] > vetor-ord-n[j]) {
            int aux = vetor-ord-n[j];
            vetor-ord-n[j] = vetor-ord-n[i];
            vetor-ord-n[i] = aux;
        }
    }
}

for(int i = 0; i qtd-n; i++) { COPIA DO VETOR PARA IMPRIMIR
    printf("%d ", vetor-ord-n[i]);
}


*/