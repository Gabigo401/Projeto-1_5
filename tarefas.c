#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status deletar(Tarefa tarefas[], int *pos) { //criando função de deletar e um array para tarefas alem de um ponteiro de int para o indice
    if (*pos == 0)  //verifica se existe alguma tarefa no sistema
      return SEM_TAREFAS;  //se não tem nenhuma tarefa retorna a mensagem sem_tarefa