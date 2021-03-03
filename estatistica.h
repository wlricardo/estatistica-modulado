/*
** TIPOS DE DADOS CRIADOS PELO USUÁRIO
*/

// Tipo Classe 
// Essa tipo cria uma classe de uma tabela de dados agrupados
// onde são exibidos o intervalo de classe, freq. absoluta, 
// freq. acumulada e média da classe
typedef struct classe Classe;



/*
** FUNÇÕES AUXILIARES
*/
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

// Definir_Classes :
// Cria um vetor de classes baseado no núm. de observações
Classe *Definir_Classes(int *tabela, int );

// Intervalo_Classe :
// Calcula e exibe os intervalos de valores de cada classe
void Intervalo_Classe(int k, int menor, int maior, int amp_classe);

// Freq_Abs_Classe :
// Calcula a freq. absoluta de cada classe
int Freq_Abs_Classe(int *tabela, int n, int k, int menor, int maior, int amp_classe);