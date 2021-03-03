
#include<stdlib.h>
#include<stdio.h>

//*****************************************************************//
//                         TIPOS                                   //
//*****************************************************************//
typedef struct {
    int F;
    int Fac;
    float xi;
} Classe;


//*****************************************************************//
//                         FUNÇÕES                                 //
//*****************************************************************//

/* Função Gerar_Dados */
int *Gerar_Dados(int qtd_dados) {
    int *dados;

    dados = (int*)calloc(qtd_dados, sizeof(int));
    if (dados==NULL) {
        printf("\n\n Erro de alocacao de memoria !!\n\n");
    }    
    for (int i = 0; i < qtd_dados; i++) {
        dados[i] = 1 + (rand() % 50);
    } 
    return dados;   
}

/* Função Exibe_Dados */
void Exibe_Dados(int *tabela, int qtd_dados) {
    printf("\n  Dados gerados: ");
    printf("\n---------------------\n\n");
    for (int i = 0; i < qtd_dados; i++){
        printf(" %3d", tabela[i]);
        if ((i+1)%30 == 0) {
            printf("\n");
        } 
    }    
}

/* Função Menor_Valor */
int Menor_Valor(int *tabela, int qtd_dados) {
    int menor = tabela[0];
    for (int i = 1; i < qtd_dados; i++) {
        if (tabela[i] < menor) {
            menor = tabela[i];
        }
    }
    return menor;
}

/* Função Menor_Valor */
int Maior_Valor(int *tabela, int qtd_dados) {
    int maior = tabela[0];
    for (int i = 1; i < qtd_dados; i++) {
        if (tabela[i] > maior) {
            maior = tabela[i];
        }
    }
    return maior;
}

/* Funçao Lim_Inferior */
int Lim_Inferior(int classe, int menor, int amp_classe) {
    int linf = 0;
    linf = menor + (classe*amp_classe);
    return linf;
}

/* Função Lim_Superior */
int Lim_Superior(int classe, int menor, int amp_classe) {
    int lsup = 0;
    lsup = menor + ((classe+1)*amp_classe);
    return lsup;
}

/* Função Intervalo_Classe */
void Intervalo_Classe(int k, int menor, int maior, int amp_classe) {
    int inf = Lim_Inferior(k, menor, amp_classe);
    int sup = Lim_Superior(k, menor, amp_classe);

    if (sup == maior) {
        printf("\n %3d [--] %-3d ", inf, sup);
    } else {        
        printf("\n %3d [--) %-3d ", inf, sup);
    }   
}

/* Função Exibe_Variáveis_Auxiliares */
void Exibe_Variaveis_Auxiliares(int num_observacoes, int num_classes, int maior, int menor, int amp_classe) {
    printf("\n\n");    
    printf("\n >> Preparacao para agrupamento de dados:");
    printf("\n---------------------------------------------");    
    printf("\n  > Total de dados (n)...............: %d", num_observacoes);
    printf("\n  > Numero de classes (k)............: %d", num_classes);
    printf("\n  > Menor valor da tabela de dados...: %d", menor);    
    printf("\n  > Maior valor da tabela de dados...: %d", maior); 
    printf("\n  > Amplitude de classe (ac).........: %d", amp_classe);
    printf("\n\n"); 
}

int Freq_Abs_Classe(int *tabela, int n, int k, int classe, int menor, int maior, int amp_classe) {
    int total = 0;
    int inf = Lim_Inferior(classe, menor, amp_classe);
    int sup = Lim_Superior(classe, menor, amp_classe);
    
    for (int i = 0; i < n; i++) {        
        if (tabela[i] >= inf && tabela[i] < sup) {
            total++;                                             
        }    
        if (classe+1 == k) {
            int inf = Lim_Inferior(classe, menor, amp_classe);
            int sup = Lim_Superior(classe, menor, amp_classe);
            if ((int)(maior-menor) % k == 0) {
                if (tabela[i] == maior) {
                    total++;
                }                    
            }                
        }  
    }        
    return total; 
}