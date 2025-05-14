#include <stdio.h>

typedef Status (*funcao)(Tarefa[], int *);   //receber um array para tarefas e um ponteiro de int que vai ser usaddo para indice

Status criar(Tarefa tarefas[], int *pos);   //declarando a função criar
Status deletar(Tarefa tarefas[], int *pos);  //declarando a função deletar
Status listar(Tarefa tarefas[], int *pos);  //declarando a função listar
Status salvar(Tarefa tarefas[], int *pos);  //declarando a função salvar
Status carregar(Tarefa tarefas[], int *pos);  //declarando a função carregar

void clearBuffer();  //função para limpar o buffer
