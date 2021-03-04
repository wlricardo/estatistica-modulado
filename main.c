#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include "estatistica.h"

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int *tabela;      // Matriz de inteiros representando os dados
    Classe *c;        // Matriz de inteiros representando as classes
    int n;            // Número de observações
    int k;            // Quantidade de classes
    int menor, maior; // O menor e o maior valores encontrados no rol de dados
    int ac;           // Amplitude de classe

    // Otendo a quantidade de dados da tabela
    printf("\n Quantidade de dados da tabela: ");
    scanf("%d", &n);
    fflush(stdin);

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
    ac = (int)ceil((maior - menor) / (1.0 * k));

    // Criando uma lista das classes
    c = (Classe *)calloc(k, sizeof(Classe));

    // Exibindo as variáveis acessórias
    Exibe_Variaveis_Auxiliares(n, k, maior, menor, ac);

    // Exibindo dados agrupados
    for (int i = 0; i < k; i++)
    {
        Intervalo_Classe(i, menor, maior, ac);                              // Intervalo de classes
        c[i].F = Freq_Abs_Classe(tabela, n, k, i, menor, maior, ac);        // Frequência absoluta da classe        
        printf(" %3d", c[i].F);                                             
        c[i].Fac = Freq_Acumulada(c, i);                                    // Frequência acumulada
        printf(" %6d", c[i].Fac);                    
        c[i].xi = Ponto_Medio_Classe(i, menor, ac);                         // Ponto médio da classe
        printf(" %9.2f", c[i].xi);
    }
    
    printf("\n\n\n");
    return 0;
}
