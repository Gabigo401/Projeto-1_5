#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status listar(Tarefa tarefas[], int *pos) { //criando a função de listar as tarefas e um array de tarefas e um ponteiro int para indice
    if (*pos == 0)   //verifica se tem tarefas criadas
      return SEM_TAREFAS;   //se não tem volta essa mensagem