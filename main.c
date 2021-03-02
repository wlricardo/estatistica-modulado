#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "estatistica.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));   

    int *tabela;        // Matriz de valores inteiros representando os dados
    int n;              // Número de observações
    int k;              // Quantidade de classes
    int menor, maior;   // O menor e o maior valores encontrados no rol de dados
    int ac;             // Amplitude de classe

    // Otendo a quantidade de dados da tabela
    printf("\n Quantidade de dados da tabela: ");
    scanf("%d", &n); fflush(stdin);

    /*tabela = (int*)calloc(n, sizeof(int));
    if (tabela == NULL) {
        printf("\n\n Erro de alocação de memória !! \n\n");
    }*/

    system("cls");
    
    printf("\n\n");
    // Gerando e exibindo os dados aleatoriamente
    tabela = Gerar_Dados(n);
    /*for (int i = 0; i < n; i++) {
        tabela[i] = 10 + (rand() % 200);
        printf(" %3d", tabela[i]);
        if (i+1 % 30 == 0) {
            printf("\n");
        }
    }*/    

    // Obtendo variáveis estatísticas acessórias
    k = (int)roundf(sqrtf(n));
    menor = Menor_Valor(tabela, n);
    maior = Maior_Valor(tabela, n);
    ac = (int)roundf((maior-menor)/(1.0*k));

    // Exibindo a tabela com os dados gerados
    Exibe_Dados(tabela, n);

    // Exibindo as variáveis acessórias
    Exibe_Variaveis_Auxiliares(n, k, maior, menor, ac);
    for (int i = 0; i < k; i++) {
        Intervalo_Classe(i, menor, ac);
    }
    
    printf("\n\n\n");
    return 0;
}
