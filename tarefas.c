#include "tarefas.h"
#include <stdio.h>
#include <string.h>

void clearBuffer() {  //void para limpar o buffer
    int c;   //int chamado c 
    while ((c = getchar()) != '\n' && c != EOF)   //limpa o buffer do teclado apos um scanf
      ;
  }