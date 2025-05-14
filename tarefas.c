#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status criar(Tarefa tarefas[], int *pos) {  //a função criar que recebe um array de tarefas e um ponteiro int para os indices
    if (*pos >= TOTAL)   //verificar se o numero de tarefas atingiu o limite
      return MAX_TAREFA;   //se atingiu retorna como MAX_TAREFA


    printf("Entre com a prioridade: ");  //printf para mensagem pedindo a prioridade da tarefa
    scanf("%d", &tarefas[*pos].prioridade);   //le a mensagem do usuario e guarda no endereço de tarefa com um indice
    clearBuffer();  //limpa  o buffer apos o scanf

    printf("Entre com a categoria: ");  //printf pedindo a categoria
    fgets(tarefas[*pos].categoria, sizeof(tarefas[*pos].categoria), stdin); //le a resposta do usuario e guarda no array de tarefas e verifica se não chegou ao maximo de caracteres

    printf("Entre com a descricao: ");  //printf pedindo a descrição
    fgets(tarefas[*pos].descricao, sizeof(tarefas[*pos].descricao), stdin);  //le a resposta do usuario e guarda no array alem de verificar se não chegou ao limite de caracteres

    (*pos)++;   //incrementa o *pos

    return OK;  //retorna a mensagem de  ok como sucesso
}

Status deletar(Tarefa tarefas[], int *pos) { //criando função de deletar e um array para tarefas alem de um ponteiro de int para o indice
    if (*pos == 0)  //verifica se existe alguma tarefa no sistema
      return SEM_TAREFAS;  //se não tem nenhuma tarefa retorna a mensagem sem_tarefa

    int pos_deletar;   //variavel int
    printf("Entre com a posicao da tarefa a ser deletada: ");  //pedindo a posição da lista que sera deletada
    scanf("%d", &pos_deletar);  //le a resposta e guarda no endereço de pos_deletar
    clearBuffer();  //limpa o buffer apos o scanf
    
    pos_deletar--;  //decrementa a variavel
    if (pos_deletar >= *pos || pos_deletar < 0) //if para verificar se a posição e valida ajustando a posição de base o 0
        return NAO_ENCONTRADO;  //se não for volta essa mensagem


    int i;  //variavel chamada i
    for (i = pos_deletar; i < *pos - 1; i++) {  //for para empurrar ao outras  listar uma posição para tras e sobreescrever a lista deletada
        tarefas[i] = tarefas[i + 1];
    }
    (*pos)--;   //decrementa o numero total de tarefas
    return OK;  //retorna ok como sucesso
}
