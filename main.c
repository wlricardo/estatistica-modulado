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
    int *inf, *sup;   // Variáveis que recebem 

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

    // Moldura do cabeçalho
    printf("\n%c", 218);            // Moldura do canto superior esquerdo
    for (int  i = 0; i < 62; i++) {
        if (i==16 || i==33 || i==48) {
            printf("%c", 194);     // Moldura da parte interna
        } else {
            printf("%c", 196);     // Moldura da parte superior
        }
    }
    printf("%c", 191);  
    printf("\n%c", 179);
    printf(" Int. de classe");  
    printf("%2c", 179);
    printf(" Freq. Absoluta %c", 179);      
    printf(" Freq. Acumul.%c", 179);                                             
    printf(" Ponto medio %c", 179);  
       
    // Moldura da tabela de dados agrupados
    printf("\n%c", 195);            // Moldura do canto superior esquerdo
    for (int  i = 0; i < 62; i++) {
        if (i==16 || i==33 || i==48) {
            printf("%c", 197);      // Moldura da parte interna
        } else {
            printf("%c", 196);      // Moldura da parte superior
        }
    }
    printf("%c", 180);  
    // Exibindo dados agrupados
    for (int i = 0; i < k; i++)
    {
        printf("\n%c", 179);
        Intervalo_Classe(i, menor, maior, ac);                              // Intervalo de classes
        printf("%2c", 179);
        c[i].F = Freq_Abs_Classe(tabela, n, k, i, menor, maior, ac);        // Frequência absoluta da classe        
        printf("      %3d  %6c", c[i].F, 179);                                             
        c[i].Fac = Freq_Acumulada(c, i);                                    // Frequência acumulada
        printf("     %3d   %4c", c[i].Fac, 179);                    
        c[i].xi = Ponto_Medio_Classe(i, menor, ac);                         // Ponto médio da classe
        printf("   %6.2f  %3c", c[i].xi, 179);
    }
    // Moldura do rodapé
    printf("\n%c", 192);            // Moldura do canto inferior esquerdo
    for (int  i = 0; i < 62; i++) {
        if (i==16 || i==33 || i==48) {
            printf("%c", 193);     // Moldura da parte interna
        } else {
            printf("%c", 196);     // Moldura da parte superior
        }
    }
    printf("%c", 217);              // Moldura do canto inferior direito
    
    printf("\n\n\n");
    return 0;
}
