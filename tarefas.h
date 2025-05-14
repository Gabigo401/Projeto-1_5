#include <stdio.h>

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