#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status salvar(Tarefa tarefas[], int *pos) {  //função para salvar e um array de tarefas e um ponteiro para o indice
    FILE *f = fopen("tarefas.bin", "wb");  //abre um arquivo binario para escrever nele
    if (f == NULL)   //verifica se o arquivo binario foi aberto
      return ABRIR;  //mensagem se não abriu