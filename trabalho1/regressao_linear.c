#include <stdio.h>
#include <stdlib.h>

typedef struct Ponto {
    int x;
    float y;
} Ponto;

int main(int argc, char *argv[]) {

    FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int quantidade_pontos = 0;

    while (fscanf(arquivo, "%*d,%*f\n") == 0) {
        quantidade_pontos++;
    }

    // retorna pro inicio do arquivo para ler os pontos
    rewind(arquivo);

    // aloca dinamicamente o array de pontos
    Ponto *pontos = (Ponto *)malloc(quantidade_pontos * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro ao alocar memória para os pontos.\n");
        fclose(arquivo);
        return 1;
    }

    // le e armazena os pontos do arquivo
    for (int i = 0; i < quantidade_pontos; i++) {
        if (fscanf(arquivo, "%d,%f\n", &pontos[i].x, &pontos[i].y) != 2) {
            printf("Erro ao ler os pontos do arquivo.\n");
            free(pontos);
            fclose(arquivo);
            return 1;
        }
    }

    fclose(arquivo);

    // calcula a media dos valores de x e y
    float media_x = 0.0f, media_y = 0.0f;
    for (int i = 0; i < quantidade_pontos; i++) {
        media_x += pontos[i].x;
        media_y += pontos[i].y;
    }
    media_x /= quantidade_pontos;
    media_y /= quantidade_pontos;
    
    // calcula a inclinação da reta de regressão
    float numerador = 0.0f, denominador = 0.0f;
    for (int i = 0; i < quantidade_pontos; i++) {
        numerador += (pontos[i].x - media_x) * (pontos[i].y - media_y);
        denominador += (pontos[i].x - media_x) * (pontos[i].x - media_x);
    }
    float inclinacao = numerador / denominador;

    // calcula o ponto de intercepção
    float interceptacao = media_y - inclinacao * media_x;

    // exibe os resultados
    printf("Saida: y = %.1fx + %.1f\n", inclinacao, interceptacao);

    free(pontos);

    return 0;
}
