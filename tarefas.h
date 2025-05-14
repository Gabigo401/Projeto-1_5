#include <stdio.h>

#define TOTAL 100  //defininddo como 100 para o valor maximo da variavel int

typedef struct {  //criando struct para as opções
  int prioridade;  //int para a variavel prioridade
  char descricao[300];  //char com valor maximo de 300 caracteres
  char categoria[100];   //char com valor maximo de 100 caracteres
} Tarefa;  //nome da struct

typedef enum {  //enumeração para as possiveis respostas do sistema
    OK,   //operação feita com sucesso
    MAX_TAREFA,  //limite atingido de tarefas
    SEM_TAREFAS,   //não tem tarefas para exibir
    NAO_ENCONTRADO,   //a tarefa não foi encontrada
    ABRIR,  //abrindo arquivo
    FECHAR,  //fechando arquivo
    ESCREVER,   //escrevendo no arquivo
    LER   //lendo o arquivo
  } Status;   //nome desse typedef
