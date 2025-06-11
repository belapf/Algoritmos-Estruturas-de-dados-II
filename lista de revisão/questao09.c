#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() { // função principal
    double A_x = 0, A_y = 1; // definindo os vértices do triângulo
    double B_x = -1, B_y = -1;
    double C_x = 1, C_y = -1;

    double P_x = 0, P_y = 0; // ponto inicial

    int num_pontos = 10000; // número de pontos a serem gerados

    FILE *arquivo = fopen("pontos_sierpinski.csv", "w"); // abrir arquivo para salvar os pontos
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo.\n");
        return 1;
    }

    fprintf(arquivo, "x,y\n"); // cabeçalho do csv

    srand(time(NULL)); // inicializar o gerador de números aleatórios

    for (int i = 0; i < num_pontos; i++) {
        int escolha = rand() % 3; // para escolher um vértice aleatório
        double alvo_x, alvo_y;

        if (escolha == 0) {
            alvo_x = A_x;
            alvo_y = A_y;
        } else if (escolha == 1) {
            alvo_x = B_x;
            alvo_y = B_y;
        } else {
            alvo_x = C_x;
            alvo_y = C_y;
        }

        P_x = (P_x + alvo_x) / 2.0; // função para calcular o ponto médio
        P_y = (P_y + alvo_y) / 2.0;

        fprintf(arquivo, "%lf,%lf\n", P_x, P_y); // função para salvar o ponto no arquivo
    }

    fclose(arquivo);

    printf("Pontos gerados e salvos no arquivo 'pontos_sierpinski.csv'.\n");

    return 0;
}
