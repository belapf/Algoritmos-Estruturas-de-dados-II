#include <stdio.h>

int contadorChamadas = 0; // variável global para contar o número de chamadas
double funcRecursiva(int n) {     // função recursiva
    contadorChamadas++;        // conta cada chamada feita

    if (n == 0) {
        return 1;
    } else {
        double resultado = funcRecursiva(n - 1);
        return resultado + 1 / resultado;
    }
}

int main() { // função principal
    int n = 5;

    contadorChamadas = 0; // zera o contador antes de começar
    double resultado = funcRecursiva(n);

    printf("Resultado de funcRecursiva(%d) = %.6lf\n", n, resultado);
    printf("Numero de chamadas recursivas: %d\n", contadorChamadas);

    return 0;
}
