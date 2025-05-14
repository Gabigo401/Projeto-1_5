#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status salvar(Tarefa tarefas[], int *pos) {  //função para salvar e um array de tarefas e um ponteiro para o indice
    FILE *f = fopen("tarefas.bin", "wb");  //abre um arquivo binario para escrever nele
    if (f == NULL)   //verifica se o arquivo binario foi aberto
      return ABRIR;  //mensagem se não abriu

    int qtd = fwrite(tarefas, sizeof(Tarefa), TOTAL, f);  //escreve todas as tarefas no arquivo
    if (qtd == 0)    //verifica se escreveu
        return ESCREVER;   //se não retorna esse erro
    
    qtd = fwrite(pos, sizeof(int), 1, f);   //escreve a posição no arquivo
    if (qtd == 0)   //verifica se foi escrito
        return ESCREVER;
    
    if (fclose(f))   //fecha o arquivo
        return FECHAR;
    
    return OK;  //mensagem para sucesso
}
    