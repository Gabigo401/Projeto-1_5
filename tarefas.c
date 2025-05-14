#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status carregar(Tarefa tarefas[], int *pos) {  //função para ler e um array de tarefas e ponteiro int para o indice
    FILE *f = fopen("tarefas.bin", "rb");  //abre o arquivo para leitura
    if (f == NULL)   //verifica se o arquivo foi aberto
      return ABRIR;   //se não foi aberto aparece essa mensagem de erro