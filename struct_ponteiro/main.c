#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto{
    int x;
    int y;
} Ponto;

int main (int argc, char* argv[]) {

    int a = 2;
    int b = a;
    int* p = &a;

    printf("\nA: %d;\t B: %d", a, b);
    printf("\n$a: %p; $b: %p", &a, &b);

    b = 4;
    printf("\nA: %d; B: %d", a, b);

    a = 8;
    printf("\nA: %d; B: %d", a, b);

    printf("\n&P: %p; P: %p, *P: %d", &p, p, *p);

    *p = 15;
    printf("\nA: %d; B: %d", a, b);

    p = malloc(sizeof(int) * 5);
    p[0] = 3;
    p[1] = 55;

    printf("&p = %p \t p = %p \t *p = %d\n", &p, p, *p);
    printf("&p = %p \t p = %p \t *p = %d\n", &p, &p[1], p[1]);

    Ponto A;
    A.x = 4;
    A.y = 4;
    printf("\nA(%d, %d)", A.x, A.y);

    exit(0);
}