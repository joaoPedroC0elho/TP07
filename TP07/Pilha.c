#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inicializar(Pilha *pilha) {
    pilha->topo = NULL;
}

void empilhar(Pilha *pilha, double valor) {
    No *novoNo = (No *)malloc(sizeof(No));
if (novoNo == NULL) {
printf("Erro: Falha na alocação de memória\n");
exit(EXIT_FAILURE);
}
novoNo->dado = valor;
novoNo->proximo = pilha->topo;
pilha->topo = novoNo;
}


double desempilhar(Pilha *pilha) {
 if (pilha->topo != NULL) {
No *temp = pilha->topo;
double valor = temp->dado;
pilha->topo = temp->proximo;
free(temp);
return valor;
} else {
printf("Erro: Pilha vazia\n");
exit(EXIT_FAILURE);
}
}