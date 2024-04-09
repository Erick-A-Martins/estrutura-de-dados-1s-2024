#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {


    char txt[100];
    FILE *arq_txt;

    arq_txt = fopen("arq.txt", "r");

    if(arq_txt == NULL) {
        printf("Erro ao abrir arquivo arq.txt");
        exit(1);
    }

    while(fscanf(arq_txt, "%[^\n]\n", &txt) != EOF) { // enquanto difente de EOF(end of file) // "%[^\n]\n" - lê string que possuem espacos
        printf("\n");
        printf("txt = %s", txt);
    }    

    fclose(arq_txt);
    
    exit(0);
}