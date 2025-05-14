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

    if (opcao == 1) {  //se a repostar for 1
        Status s = criar(tarefas, &pos);  //chama a função dde criar
        if (s != OK)   //se  houver um erro mostra essa mensagem e codigo
          printf("Erro ao criar tarefa. Código: %d\n", s);
      } else if (opcao == 2) {  //se a resposta for 2
        Status s = deletar(tarefas, &pos);   //chama a função de deletar
        if (s != OK)   //se houver erro ao deletar aparece essa mensagem e codigo
          printf("Erro ao deletar tarefa. Código: %d\n", s);
      } else if (opcao == 3) {  //se a respostar for 3
        Status s = listar(tarefas, &pos);   //chama a função de listar as listas
        if (s != OK)   //se houver erro ao listar aparece essa mensagem 
          printf("Erro ao listar tarefas. Código: %d\n", s);
      } else if (opcao == 0) {   //se a opçao for 0
        printf("Salvando e saindo...\n");   //mostra essa mensagem e salva as listar e sai do programa
      } else {
        printf("Opcao invalida\n");  //aparece essa mensagem se for escolhida uma mensagem diferente dessas opções
      }
  
    } while (opcao != 0); //laço que se repete ate o usuario digitar 0
  
    Status s = salvar(tarefas, &pos); // Salva tarefas no arquivo
    if (s != OK)   //mostra essa mensagem se houver algum  erro ao salvar o arquivo
      printf("Erro ao salvar tarefas. Código: %d\n", s);
  
    return 0;
  }