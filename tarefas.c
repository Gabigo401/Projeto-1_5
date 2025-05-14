#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status carregar(Tarefa tarefas[], int *pos) {  //função para ler e um array de tarefas e ponteiro int para o indice
    FILE *f = fopen("tarefas.bin", "rb");  //abre o arquivo para leitura
    if (f == NULL)   //verifica se o arquivo foi aberto
      return ABRIR;   //se não foi aberto aparece essa mensagem de erro

    int qtd = fread(tarefas, sizeof(Tarefa), TOTAL, f);   //le todas as informações dar tarefas como categoria e descrição
    if (qtd == 0)   //verifica se foi aberto e lido
        return LER;
    
    qtd = fread(pos, sizeof(int), 1, f);   //le a posição da lista
    if (qtd == 0)   //verifica se foi aberto e lido
        return LER;
    
    if (fclose(f))  //fecha o arquivo
        return FECHAR;
    
    return OK;  //mensagem de sucesso
};
    