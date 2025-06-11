#include <stdio.h>

double p_sem_cauda(double x, int n) { // recursão sem cauda
    if (n < 0) {
        return 1;
    } else {
        return (x - n) * p_sem_cauda(x, n - 1);
    }
}

int main() { 
    double x;
    int n;

    printf("Digite o valor de x: ");
    scanf("%lf", &x);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    double resultado = p_sem_cauda(x, n);

    printf("Resultado (recursao sem cauda): %lf\n", resultado);

    return 0;
}
