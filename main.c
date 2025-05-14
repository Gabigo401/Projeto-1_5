#include "tarefas.h"
#include <stdio.h>

int main() {
    funcao fs[] = {criar, deletar, listar, salvar, carregar};  //declara array de funções ee dentro do array cada elemento aposta para uma função 
  
    Tarefa tarefas[TOTAL];  //dddeclara um array tarefas com o valor maximo ja definido
    int pos;  //guardda quantas tarefas existem
    Status erro = fs[4](tarefas, &pos);  //chama a função de ler
    if (erro != OK) {  //verifica se a função de ler foi executaddad com sucesso
      printf("Nenhuma tarefa carregada. Iniciando vazio.\n");  //se não aparece essa mensagem
      pos = 0;   //pos vira
    }