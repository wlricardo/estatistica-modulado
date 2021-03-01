
#include<stdlib.h>
#include<stdio.h>


// Tipos 
typedef struct {
    int F;
    int Fac;
    float xi;
} Classe;

// Funções
/* Função Gerar_Dados */
void Gerar_Dados(int *tabela, int qtd_dados) {
    for (int i = 0; i < qtd_dados; i++) {
        tabela[i] = 10 + (rand() % 120);
    }    
}