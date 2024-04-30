#include <stdio.h>
#include <stdlib.h>
#include "lista_circular.h"

No* no(char valor, No* proximo_no){
    No* no = malloc(sizeof(No));
    no->valor = valor;
    no->proximo_no = proximo_no;
    return no;
}

void inserir_no(No* H, char valor){
    if(H != NULL){
        if(H->proximo_no == NULL){
            H->proximo_no = no(valor, H);
        }
        else{
            No* temp = H->proximo_no;
            while(temp->proximo_no != H){
                temp = temp->proximo_no;
            }
            temp->proximo_no = no(valor, H);
        }
    }
}

void imprimir_lista(No* H){
    if(H != NULL){    
        printf("%c ", H->valor);

        No* temp = H->proximo_no;
        while(temp != H & temp != NULL){
            printf("%c ", temp->valor);
            temp = temp->proximo_no;
        }
    }
}

void remove_no(No* H, char valor){
    if(H != NULL){
        No* temp = H->proximo_no;
        No* temp_ant = H;

        while(temp != H & temp != NULL){
            if(temp->valor == valor){
                temp_ant->proximo_no = temp->proximo_no;
                free(temp);
                temp = temp_ant->proximo_no;
            }
            else{
                temp_ant = temp;
                temp = temp->proximo_no;
            }
        }
    }
}