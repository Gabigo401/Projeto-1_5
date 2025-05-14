#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status listar(Tarefa tarefas[], int *pos) { //criando a função de listar as tarefas e um array de tarefas e um ponteiro int para indice
    if (*pos == 0)   //verifica se tem tarefas criadas
      return SEM_TAREFAS;   //se não tem volta essa mensagem


    int i;
    for (i = 0; i < *pos; i++) {  //usa a variavel i para percorrer o array tarefas e mostrar os detalher de cada
        printf("Pos: %d\t", i + 1);   //mostra a posição
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
    }
    
    return OK;  //retorna essa mensagem se a ação for um sucesso
}
    