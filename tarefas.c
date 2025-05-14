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
