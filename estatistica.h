/*
** TIPOS DE DADOS CRIADOS PELO USUÁRIO
*/

// Tipo Classe 
// Essa tipo cria uma classe de uma tabela de dados agrupados
// onde são exibidos o intervalo de classe, freq. absoluta, 
// freq. acumulada e média da classe
typedef struct classe{
    int F;
    int Fac;
    float xi;
} Classe;


/*
** FUNÇÕES AUXILIARES
*/

// *Gerar_Dados :
// Gera um vetor com os dados gerados aleatoriamente
int *Gerar_Dados(int quantidade);

// Menor_Valor :
// Determina o menor valor encontrado na lista de dados
int Menor_Valor(int *lista, int qtd_dados);

// Maior_Valor :
// Determina o maior valor encontrado na lista de dados
int Maior_Valor(int *lista, int qtd_dados);

// Exibe_Variaveis_Auxiliares :
// Exibe em tela os valores do número de observações, 
// quantidade de classe, o maior valor observado, o 
// menor valor observado e a amplitude de classe.
void Exibe_Variaveis_Auxiliares(int num_observacoes, int num_classes, int maior, int menor, int amp_classe);

// Exibe_Dados :
// Exibe os dados em forma de matriz com 30 colunas
void Exibe_Dados(int *tabela, int qtd_dados);

// Lim_Inferior :
// Calcula o limite inferior de uma classe
int Lim_Inferior(int classe, int menor, int amp_classe);

// Lim_Superiro :
// Calcula o limite superior de uma classe
int Lim_Superior(int classe, int menor, int amp_classe);

// Intervalo_Classe :
// Calcula e exibe os intervalos de valores de cada classe
void Intervalo_Classe(int k, int menor, int maior, int amp_classe);

// Freq_Abs_Classe :
// Calcula a freq. absoluta de uma classe
int Freq_Abs_Classe(int *tabela, int n, int k, int classe, int menor, int maior, int amp_classe);

// Freq_Acumulada :
// Calcula a freq. acumulada de uma classe
int Freq_Acumulada(Classe *k, int classe);

// Ponto_Medio_Classe :
// Calcula o ponto médio do intervalo de classe
float Ponto_Medio_Classe(int classe, int menor, int amp_classe);

// Media_Ponderada :
// Calcula a média ponderada dos dados tabelados
float Media_Ponderada(Classe *c, int k, int tam_amaostra);

// Classe_Modal :
// Determina a classe modal da tabela de dados
int Classe_Modal(Classe *c, int num_classes);

// Moda :
// Calcula a moda de uma tabela de dados tabelados
float Moda(Classe *classe, int ac, int k, int menor);

// Mediana :
// Cálculo da classe mediana
int Classe_Mediana(Classe *classe, int num_amostras);

// Mediana :
// Calcula a mediana de uma tabela de dados tabelados
float Mediana(Classe *classe, int num_classes, int h, int menor, int num_amostras);

// Variância :
// Cálculo da variância de dados amostrais
float Variancia(int *lista, int tam_amostra, float media);

// Desvio-padrão :
// Calcula o devio-padrão de valores tabelados
float Desvio_Padrao(float variancia);

// Coef_Variacao :
// Valor que indica o quão confiável é a média dos valores
float Coef_Variacao(float desv_padrao, float media);