#include <stdio.h>

int fatorial_tail(int n, int acc) {// função fatorial com recursão de cauda
    if (n == 0) return acc;
    return fatorial_tail(n - 1, acc * n);
}

int fatorial(int n) { // função wrapper (interface para o usuário)
    return fatorial_tail(n, 1);
}


int main() { //função principal
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Nao existe fatorial de numero negativo\n");
    } else {
        printf("Fatorial de %d e: %d\n", num, fatorial(num));
    }

    return 0;
}
