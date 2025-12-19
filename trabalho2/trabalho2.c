#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

EstruturaAuxiliar *vetorPrincipal[TAM];

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
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (tamanho < 1)
        return TAMANHO_INVALIDO;

    if (vetorPrincipal[posicao - 1] != NULL)
        return JA_TEM_ESTRUTURA_AUXILIAR;

    vetorPrincipal[posicao - 1] = (EstruturaAuxiliar *)malloc(sizeof(EstruturaAuxiliar));
    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao - 1]->dados = (int *)malloc(sizeof(int) * tamanho);
    if (vetorPrincipal[posicao - 1]->dados == NULL)
    {
        free(vetorPrincipal[posicao - 1]);
        vetorPrincipal[posicao - 1] = NULL;
        return SEM_ESPACO_DE_MEMORIA;
    }

    vetorPrincipal[posicao - 1]->tam = tamanho;
    vetorPrincipal[posicao - 1]->qtd = 0;

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
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao - 1]->qtd >= vetorPrincipal[posicao - 1]->tam)
        return SEM_ESPACO;

    vetorPrincipal[posicao - 1]->dados[vetorPrincipal[posicao - 1]->qtd++] = valor;

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
{
    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao - 1]->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    vetorPrincipal[posicao - 1]->qtd--;

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
{
    int i, j;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao - 1]->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    for (i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++)
    {
        if (vetorPrincipal[posicao - 1]->dados[i] == valor)
        {
            for (j = i; j < vetorPrincipal[posicao - 1]->qtd - 1; j++)
                vetorPrincipal[posicao - 1]->dados[j] = vetorPrincipal[posicao - 1]->dados[j + 1];

            vetorPrincipal[posicao - 1]->qtd--;
            return SUCESSO;
        }
    }

    return NUMERO_INEXISTENTE;
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
    int i;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++)
        vetorAux[i] = vetorPrincipal[posicao - 1]->dados[i];

    return SUCESSO;
}

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
    int i;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    for (i = 0; i < vetorPrincipal[posicao - 1]->qtd; i++)
        vetorAux[i] = vetorPrincipal[posicao - 1]->dados[i];

    qsort(vetorAux, vetorPrincipal[posicao - 1]->qtd, sizeof(int), comparar);

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
    int i, j, k = 0, encontrou = 0;

    for (i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] != NULL && vetorPrincipal[i]->qtd > 0)
        {
            for (j = 0; j < vetorPrincipal[i]->qtd; j++)
                vetorAux[k++] = vetorPrincipal[i]->dados[j];
            encontrou = 1;
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
    int retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
    if (retorno != SUCESSO)
        return retorno;

    int total = 0;
    for (int i = 0; i < TAM; i++)
        if (vetorPrincipal[i] != NULL)
            total += vetorPrincipal[i]->qtd;

    qsort(vetorAux, total, sizeof(int), comparar);
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
    int novoTam;

    if (posicao < 1 || posicao > TAM)
        return POSICAO_INVALIDA;

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    novoTam = vetorPrincipal[posicao - 1]->tam + novoTamanho;
    if (novoTam < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novo = realloc(vetorPrincipal[posicao - 1]->dados, sizeof(int) * novoTam);
    if (novo == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    vetorPrincipal[posicao - 1]->dados = novo;
    vetorPrincipal[posicao - 1]->tam = novoTam;

    if (vetorPrincipal[posicao - 1]->qtd > novoTam)
        vetorPrincipal[posicao - 1]->qtd = novoTam;

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

    if (vetorPrincipal[posicao - 1] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (vetorPrincipal[posicao - 1]->qtd == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return vetorPrincipal[posicao - 1]->qtd;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{
    No *cab = malloc(sizeof(No));
    if (cab == NULL)
        return NULL;

    cab->prox = NULL;
    No *atual = cab;
    int encontrou = 0;

    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            for (int j = 0; j < vetorPrincipal[i]->qtd; j++)
            {
                No *novo = malloc(sizeof(No));
                if (novo == NULL)
                    return NULL;
                novo->valor = vetorPrincipal[i]->dados[j];
                novo->prox = NULL;
                atual->prox = novo;
                atual = novo;
                encontrou = 1;
            }
        }
    }

    if (!encontrou)
    {
        free(cab);
        return NULL;
    }

    return cab;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
    int i = 0;
    No *p = inicio->prox;

    while (p != NULL)
    {
        vetorAux[i++] = p->valor;
        p = p->prox;
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
    No *p = *inicio;
    while (p != NULL)
    {
        No *aux = p->prox;
        free(p);
        p = aux;
    }
    *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 
*/
void inicializar()
{
    for (int i = 0; i < TAM; i++)
        vetorPrincipal[i] = NULL;
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.
*/
void finalizar()
{
    for (int i = 0; i < TAM; i++)
    {
        if (vetorPrincipal[i] != NULL)
        {
            free(vetorPrincipal[i]->dados);
            free(vetorPrincipal[i]);
            vetorPrincipal[i] = NULL;
        }
    }
}

void dobrar(int *x)
{
    if (x != NULL)
        *x = (*x) * 2;
}

