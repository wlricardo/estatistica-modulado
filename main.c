#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "estatistica.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));   

    int *tabela;        // Matriz de inteiros representando os dados
    Classe *c;           // Matriz de inteiros representando as classes
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

    // Exibindo a tabela com os dados gerados
    Exibe_Dados(tabela, n);
    
    // Obtendo variáveis estatísticas acessórias
    k = roundf(sqrtf(n));
    menor = Menor_Valor(tabela, n);
    maior = Maior_Valor(tabela, n);
    ac = (int)ceil((maior-menor)/(1.0*k));

    // Exibindo as variáveis acessórias
    Exibe_Variaveis_Auxiliares(n, k, maior, menor, ac);

    // Exibindo dados agrupados
    for (int i = 0; i < k; i++) {
        Intervalo_Classe(i, menor, maior, ac);
        printf(" %3d", Freq_Abs_Classe(tabela, n, i, menor, maior, ac));
    }

    printf("\n\n AC = %d\n\n", ac);
    
    printf("\n\n\n");
    return 0;
}
