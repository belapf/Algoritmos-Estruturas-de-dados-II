#include <stdio.h>

int f_tail(int n, int a, int b) { // função recursiva de cauda
    if (n == 0) return a;  
    if (n == 1) return b;  
    return f_tail(n - 1, b, 2 * b + 3 * a);
}


int f(int n) { // função wrapper (interface simples)
    return f_tail(n, 1, 2);  
}


int main() { //função principal
    int num;

    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Erro. Digite valores positivos\n");
    } else {
        printf("f(%d) = %d\n", num, f(num));
    }

    return 0;
}
