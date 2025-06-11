#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 6  // para as combinações da Mega-Sena
#define LIMITE_COMBINACOES 1  // função para limitar os números da mega sena

int contador_combinacoes = 0;  // contador global

/*-----------------------------------------------
a - produto por somas sucessivas (recursivo)
------------------------------------------------*/
int produto(int a, int b) {
    if (b == 0) return 0;
    return a + produto(a, b - 1);
}

/*-----------------------------------------------
b - divisão inteira por subtrações sucessivas
------------------------------------------------*/
int divisao_inteira(int dividendo, int divisor) {
    if (dividendo < divisor) return 0;
    return 1 + divisao_inteira(dividendo - divisor, divisor);
}

/*-----------------------------------------------
c - verificar se uma palavra é palíndromo (recursivo)
------------------------------------------------*/
bool palindromo(const char *str, int inicio, int fim) {
    if (inicio >= fim) return true;
    if (str[inicio] != str[fim]) return false;
    return palindromo(str, inicio + 1, fim - 1);
}

/*-----------------------------------------------
d - inverter uma string (recursivo)
------------------------------------------------*/
void inverter_string(char *str, int inicio, int fim) {
    if (inicio >= fim) return;
    char temp = str[inicio];
    str[inicio] = str[fim];
    str[fim] = temp;
    inverter_string(str, inicio + 1, fim - 1);
}

/*-----------------------------------------------
e - gerar combinações da mega sena
------------------------------------------------*/
void gerar_combinacoes(int start, int profundidade, int combinacao[]) {
    if (contador_combinacoes >= LIMITE_COMBINACOES) return;

    if (profundidade == MAX) {
        for (int i = 0; i < MAX; i++) {
            printf("%02d ", combinacao[i]);
        }
        printf("\n");
        contador_combinacoes++;
        return;
    }

    for (int i = start; i <= 60; i++) {
        combinacao[profundidade] = i;
        gerar_combinacoes(i + 1, profundidade + 1, combinacao);

        if (contador_combinacoes >= LIMITE_COMBINACOES) break;
    }
}


int main() { //função principal
   
    int a = 4, b = 3;  // teste do produto
    printf("Produto de %d e %d = %d\n", a, b, produto(a, b));

  
    int dividendo = 15, divisor = 2;   // teste da divisão inteira
    printf("Divisao inteira de %d por %d = %d\n", dividendo, divisor, divisao_inteira(dividendo, divisor));

    
    const char *palavra = "arara"; // teste de palíndromo
    printf("'%s' e palindromo? %s\n", palavra, palindromo(palavra, 0, strlen(palavra) - 1) ? "Sim" : "Nao");

    
    char texto[] = "cacau"; // teste de inversão de string
    inverter_string(texto, 0, strlen(texto) - 1);
    printf("String invertida: %s\n", texto);

    
    printf("Combinacoes da Mega-Sena (limitadas a %d):\n", LIMITE_COMBINACOES); // teste da mega sena
    int combinacao[MAX];
    gerar_combinacoes(1, 0, combinacao);

    return 0;
}
