#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include"estatistica.h"


int main(int argc, char const *argv[])
{
    srand(time(NULL));   

    int *tabela;
    int n;

    // Otendo a quantidade de dados da tabela
    printf("\n Quantidade de dados da tabela: ");
    scanf("%d", &n); fflush(stdin);

    tabela = (int*)calloc(n, sizeof(int));
    if (tabela == NULL) {
        printf("\n\n Erro de alocação de memória !! \n\n");
    }
    
    printf("\n\n");
    // Gerando e exibindo os dados aleatoriamente
    for (int i = 0; i < n; i++) {
        tabela[i] = 10 + (rand() % 200);
        printf(" %3d", tabela[i]);
        if (i+1 % 30 == 0) {
            printf("\n");
        }
    }    

    printf("\n\n\n");
    return 0;
}
