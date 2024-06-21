#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

int main() {
    Nodo* raiz = NULL;
    raiz = inserirNodo(raiz, 50);
    raiz = inserirNodo(raiz, 30);
    raiz = inserirNodo(raiz, 20);
    raiz = inserirNodo(raiz, 40);
    raiz = inserirNodo(raiz, 70);
    raiz = inserirNodo(raiz, 60);
    raiz = inserirNodo(raiz, 80);

    printf("\n");
    printf("Percurso pre ordem: ");
    percursoPreOrdem(raiz);
    printf("\n");

    printf("Percurso em ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    printf("Percurso pos ordem: ");
    percursoPosOrdem(raiz);
    printf("\n");

    printf("Buscar por 40: %s\n", buscarNodo(raiz, 40) != NULL ? "Encontrado" : "Nao Encontrado");
    printf("Buscar por 90: %s\n", buscarNodo(raiz, 90) != NULL ? "Encontrado" : "Nao Encontrado");

    raiz = removerNodo(raiz, 20);
    printf("Apos remover 20, percurso em ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    raiz = removerNodo(raiz, 30);
    printf("Apos remover 30, percurso em ordem: ");
    percursoEmOrdem(raiz);
    printf("\n");

    raiz = removerNodo(raiz, 50);
    printf("Apos remover 50, percurso em ordem: ");
    percursoEmOrdem(raiz);
    printf("\n\n");

    return 0;
}
