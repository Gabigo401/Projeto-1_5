#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status criar(Tarefa tarefas[], int *pos) {  //a função criar que recebe um array de tarefas e um ponteiro int para os indices
    if (*pos >= TOTAL)   //verificar se o numero de tarefas atingiu o limite
      return MAX_TAREFA;   //se atingiu retorna como MAX_TAREFA
