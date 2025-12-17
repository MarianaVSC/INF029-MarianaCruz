#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

int vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{

   if(posicao < 1 || posicao > TAM) {
    return POSICAO_INVALIDA;
    }

    if(tamanho < 1){
    return TAMANHO_INVALIDO;
    }

    if(vetorPrincipal[posicao-1] != NULL) {
    return JA_TEM_ESTRUTURA_AUXILIAR;
    }
    
    vetorPrincipal[posicao-1] = (EstruturaAuxiliar*)malloc(sizeof(EstruturaAuxiliar));
    if(vetorPrincipal[posicao-1] == NULL) {
    return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao-1]->tam = tamanho;
    vetorPrincipal[posicao-1]->qtd = 0;
    vetorPrincipal[posicao-1]->dados = (int*)malloc(sizeof(int)*tamanho);

    if(vetorPrincipal[posicao-1]->dados == NULL) {
        free(vetorPrincipal[posicao-1]);
        vetorPrincipal[posicao-1] = NULL;
        return SEM_ESPACO_DE_MEMORIA;
    }
    return SUCESSO;

}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    if(posicao < 1 || posicao > TAM) 
    return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao-1];

    if(estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    
    if(estrutura->qtd >= estrutura->tam) 
    return SEM_ESPACO;

    estrutura->dados[estrutura->qtd] = valor;
    estrutura->qtd++;

    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{    if(posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

     EstruturaAuxiliar *estrutura = vetorPrincipal[posicao-1];

    if(estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if(estrutura->qtd == 0)
    return ESTRUTURA_AUXILIAR_VAZIA;

    estrutura->qtd--;
    return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{ int i, encontrou=0;
    if(posicao < 1 || posicao > TAM)
    return POSICAO_INVALIDA;

     EstruturaAuxiliar *estrutura = vetorPrincipal[posicao-1];

    if(estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

        if(estrutura->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

       

        for(i=0; i<estrutura->qtd; i++) {
            if(estrutura->dados[i] == valor) {
                encontrou = 1;
                break;
            }
        }

        if(!encontrou) 
        return NUMERO_INEXISTENTE;

         for (; i < estrutura->qtd - 1; i++) {
        estrutura->dados[i] = estrutura->dados[i + 1];
    }

    estrutura->qtd--;

    return SUCESSO;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

     if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao - 1];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < estrutura->qtd; i++) {
        vetorAux[i] = estrutura->dados[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao - 1];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (int i = 0; i < estrutura->qtd; i++) {
        vetorAux[i] = estrutura->dados[i];
    }

    qsort(vetorAux, estrutura->qtd, sizeof(int), comparar);

    return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
 int k = 0;
    int encontrou = 0;

    for (int i = 0; i < TAM; i++) {
        EstruturaAuxiliar *estrutura = vetorPrincipal[i];

        if (estrutura != NULL && estrutura->qtd > 0) {
            for (int j = 0; j < estrutura->qtd; j++) {
                vetorAux[k++] = estrutura->dados[j];
                encontrou = 1;
            }
        }
    }

    return encontrou ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int k = 0;
    int encontrou = 0;

    for (int i = 0; i < TAM; i++) {
        EstruturaAuxiliar *estrutura = vetorPrincipal[i];

        if (estrutura != NULL && estrutura->qtd > 0) {
            for (int j = 0; j < estrutura->qtd; j++) {
                vetorAux[k++] = estrutura->dados[j];
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
        return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

    qsort(vetorAux, k, sizeof(int), comparar);

    return SUCESSO;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

     if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao - 1];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int tamanhoFinal = estrutura->tam + novoTamanho;

    if (tamanhoFinal < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoArray = realloc(estrutura->dados, tamanhoFinal * sizeof(int));
    if (novoArray == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    estrutura->dados = novoArray;
    estrutura->tam = tamanhoFinal;

    if (estrutura->qtd > tamanhoFinal)
        estrutura->qtd = tamanhoFinal; 

    return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

     if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    EstruturaAuxiliar *estrutura = vetorPrincipal[posicao - 1];

    if (estrutura == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (estrutura->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return estrutura->qtd;
} 

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
 No *cabecote = (No*)malloc(sizeof(No));
    if(cabecote == NULL) 
    return NULL;

    cabecote->proximo = NULL;
    No *atual = cabecote;

     for (int i = 0; i < TAM; i++) {
        EstruturaAuxiliar *estrutura = vetorPrincipal[i];
        if (estrutura != NULL && estrutura->qtd > 0) {
            for (int j = 0; j < estrutura->qtd; j++) {
                No *novo = (No *)malloc(sizeof(No));
                if (novo == NULL)
                    return NULL; 
                novo->valor = estrutura->dados[j];
                novo->proximo = NULL;
                atual->proximo = novo;
                atual = novo;
            }
        }
    }

    if (cabecote->proximo == NULL) {
        free(cabecote);
        return NULL;
    }

    return cabecote;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
  No *atual = inicio->proximo;
    int i = 0;

    while (atual != NULL) {
        vetorAux[i++] = atual->valor;
        atual = atual->proximo;
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
   No *atual = *inicio;
    No *prox;

    while (atual != NULL) {
        prox = atual->proximo;
        free(atual);
        atual = prox;
    }

    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for (int i = 0; i < TAM; i++) {
        vetorPrincipal[i] = NULL;
}
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for (int i = 0; i < TAM; i++) {
        if (vetorPrincipal[i] != NULL) {
            free(vetorPrincipal[i]->dados);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}
