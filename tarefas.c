#include "tarefas.h"
#include <stdio.h>
#include <string.h>

Status criar(Tarefa tarefas[], int *pos) {  //a função criar que recebe um array de tarefas e um ponteiro int para os indices
    if (*pos >= TOTAL)   //verificar se o numero de tarefas atingiu o limite
      return MAX_TAREFA;   //se atingiu retorna como MAX_TAREFA


    printf("Entre com a prioridade: ");  //printf para mensagem pedindo a prioridade da tarefa
    scanf("%d", &tarefas[*pos].prioridade);   //le a mensagem do usuario e guarda no endereço de tarefa com um indice
    clearBuffer();  //limpa  o buffer apos o scanf

    printf("Entre com a categoria: ");  //printf pedindo a categoria
    fgets(tarefas[*pos].categoria, sizeof(tarefas[*pos].categoria), stdin); //le a resposta do usuario e guarda no array de tarefas e verifica se não chegou ao maximo de caracteres

    printf("Entre com a descricao: ");  //printf pedindo a descrição
    fgets(tarefas[*pos].descricao, sizeof(tarefas[*pos].descricao), stdin);  //le a resposta do usuario e guarda no array alem de verificar se não chegou ao limite de caracteres

    (*pos)++;   //incrementa o *pos

    return OK;  //retorna a mensagem de  ok como sucesso
}

Status deletar(Tarefa tarefas[], int *pos) { //criando função de deletar e um array para tarefas alem de um ponteiro de int para o indice
    if (*pos == 0)  //verifica se existe alguma tarefa no sistema
      return SEM_TAREFAS;  //se não tem nenhuma tarefa retorna a mensagem sem_tarefa

    int pos_deletar;   //variavel int
    printf("Entre com a posicao da tarefa a ser deletada: ");  //pedindo a posição da lista que sera deletada
    scanf("%d", &pos_deletar);  //le a resposta e guarda no endereço de pos_deletar
    clearBuffer();  //limpa o buffer apos o scanf
    
    pos_deletar--;  //decrementa a variavel
    if (pos_deletar >= *pos || pos_deletar < 0) //if para verificar se a posição e valida ajustando a posição de base o 0
        return NAO_ENCONTRADO;  //se não for volta essa mensagem


    int i;  //variavel chamada i
    for (i = pos_deletar; i < *pos - 1; i++) {  //for para empurrar ao outras  listar uma posição para tras e sobreescrever a lista deletada
        tarefas[i] = tarefas[i + 1];
    }
    (*pos)--;   //decrementa o numero total de tarefas
    return OK;  //retorna ok como sucesso
}

Status listar(Tarefa tarefas[], int *pos) { //criando a função de listar as tarefas e um array de tarefas e um ponteiro int para indice
    if (*pos == 0)   //verifica se tem tarefas criadas
      return SEM_TAREFAS;   //se não tem volta essa mensagem


    int i;
    for (i = 0; i < *pos; i++) {  //usa a variavel i para percorrer o array tarefas e mostrar os detalher de cada
        printf("Pos: %d\t", i + 1);   //mostra a posição
        printf("Prioridade: %d\t", tarefas[i].prioridade);
        printf("Categoria: %s\t", tarefas[i].categoria);
        printf("Descricao: %s\n", tarefas[i].descricao);
    }
    
    return OK;  //retorna essa mensagem se a ação for um sucesso
}

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
