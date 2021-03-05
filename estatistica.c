
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "estatistica.h"

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
        dados[i] = 1 + (rand() % 300);
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
        printf("  %3d [--] %-3d ", inf, sup);
    } else {        
        printf("  %3d [--) %-3d ", inf, sup);
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

/* Função Freq_Abs_Classe */
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

/* Função Freq_Acumulada */
int Freq_Acumulada(Classe *c, int classe) {
    int fac = 0;
    
    for (int i = 0; i <= classe; i++) {
        fac += c[i].F;
    }
    return fac;
}

/* Função Ponto_Medio_Classe */
float Ponto_Medio_Classe(int classe, int menor, int amp_classe) {
    
    int inf = Lim_Inferior(classe, menor, amp_classe);
    int sup = Lim_Superior(classe, menor, amp_classe);

    return ((sup+inf)/2.0);
}

/* Função Media_Ponderada */
float Media_Ponderada(Classe *c, int classe, int tam_amostra) {
    float media = 0.0;

    for (int i = 0; i < classe; i++) {
        media += (c[i].F * c[i].xi);
    }
    return (media/(1.0*tam_amostra));    
}

// Classe_Modal 
int Classe_Modal(Classe *c, int num_classes) {
    int classe_modal = 0;
    int maior_freq = c[0].F;
    int maior_freq_ac = c[0].Fac;

    for (int i = 1; i < num_classes; i++) {
        if (c[i].F >= maior_freq && c[i].Fac > maior_freq_ac) {
            maior_freq = c[i].F;
            maior_freq_ac = c[i].Fac;
            classe_modal = i;
        }  
    }
    return classe_modal;
}

// Moda 
float Moda(Classe *classe, int ac, int k, int menor) {
    float moda=0.0;    
    int c_modal;
    int li;                 // Limite inferior da classe modal    
    int fx;                 // Freq. absoluta da classe anterior à classe modal
    int f;                  // Freq. absoluta da classe modal
    int fy;                 // Freq. absoluta da classe posterior à classe modal
    
    c_modal = Classe_Modal(classe, k);
    if (c_modal == 0) {     // Significa que a classe modal é a 1a
        fx = 0;             // Como é a 1a classe, não haverá freq. absoluta anterior a ela
    } else {
        fx = classe[c_modal-1].F;
    }

    if (c_modal+1 == k) {   // Significa que a classe modal é a última
        fy = 0;             // Como é a última classe, não haverá freq. absoluta posterior a ela
    } else {
        fy = classe[c_modal+1].F;
    }
    
    f = classe[c_modal].F;
    li = Lim_Inferior(c_modal, menor, ac);
    
    moda = 1.0*(ac*(f - fx));     // Multiplico por 1.0 apenas para garantir que o valor seja real
    moda /= ((f-fx)+(f-fy));
    moda += li;

    return moda;
}

// Classe_Mediana
int Classe_Mediana(Classe *classe, int num_amostras) {
    int classe_mediana = 0;
    int i = 0;
    int p;

    p = (int)roundf(num_amostras/2.0);
    while (classe[i].Fac < p) {
        i++;
    }
    return classe_mediana = i;
}

// Mediana :
// Calcula a mediana de uma tabela de dados tabelados
float Mediana(Classe *classe, int num_classes, int ac, int menor, int num_amostras) {
    float mediana = 0.0;
    int f;          // Frequência absoluta da classe mediana
    int fant;       // Frequência acumulada da classe anterior a da mediana
    int li;         // Limite inferior da classe mediana
    int c_mediana;  // Indice que indica a classe mediana
    int p;          // Determina a posição da mediana

    c_mediana = Classe_Mediana(classe, num_amostras);
    li = Lim_Inferior(c_mediana, menor, ac);
    p = (int)roundf(num_amostras/2.0);

    // Determinação da classe mediana acumulada anterior a da classe mediana
    if (c_mediana == 0) {       // Indica que a classe mediana é a 1a
        fant = 0;
    } else {
        fant = classe[c_mediana-1].Fac;
    }
    
    // Determinação da freq. abssoluta da classe mediana
    f = classe[c_mediana].F;

    mediana = 1.0*(ac*(p - fant));
    mediana /= f;
    mediana += 1.0*li;

    return mediana;
}
