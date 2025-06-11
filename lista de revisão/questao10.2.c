#include <stdio.h>

double com_cauda_aux(double x, int n, double acumulador) {// função auxiliar para recursão com cauda
    if (n < 0) {
        return acumulador;
    } else {
        return com_cauda_aux(x, n - 1, acumulador * (x - n));
    }
}

double com_cauda(double x, int n) { //função principal que chama a auxiliar
    return com_cauda_aux(x, n, 1);
}

int main() {
    double x;
    int n;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    double resultado = com_cauda(x, n);

    printf("Resultado (recursao com cauda): %lf\n", resultado);

    return 0;
}
