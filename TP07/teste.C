#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
typedef struct No {
    double dado;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;


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

double avaliarExpressaoPosfixada(const char *expressao) {
    Pilha pilha;
    inicializar(&pilha);

    char buffer[100];
    int bufferIndex = 0;

    for (int i = 0; expressao[i] != '\0'; ++i) {
        if (isdigit(expressao[i])) {
            buffer[bufferIndex++] = expressao[i];
        } else if (expressao[i] == ' ' || expressao[i] == '\t') {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                double valor = atof(buffer);
                empilhar(&pilha, valor);
                bufferIndex = 0;
            }
            continue;
              } else if (expressao[i] == 'c') {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, cos(operando));
        } else if (expressao[i] == 's') {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, sin(operando));
        } else if (expressao[i] == 't') {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, tan(operando));
        } else if (expressao[i] == 'l') {
            double operando = desempilhar(&pilha);
            empilhar(&pilha, log10(operando));
        } else {
            if (expressao[i] == '^') {
                double operando2 = desempilhar(&pilha);
                double operando1 = desempilhar(&pilha);
                empilhar(&pilha, pow(operando1, operando2));
            } else {
                double operando2 = desempilhar(&pilha);
                double operando1 = desempilhar(&pilha);
                switch (expressao[i]) {
                    case '+':
                        empilhar(&pilha, operando1 + operando2);
                        break;
                    case '-':
                        empilhar(&pilha, operando1 - operando2);
                        break;
                    case '*':
                        empilhar(&pilha, operando1 * operando2);
                        break;
                    case '/':
                        if (operando2 != 0.0) {
                            empilhar(&pilha, operando1 / operando2);
                        } else {
                            printf("Erro: Divisão por zero\n");
                            exit(EXIT_FAILURE);
                        }
                        break;
                    default:
                        printf("Erro: Operador inválido\n");
                        exit(EXIT_FAILURE);
                }
            }
        }
    }

    return desempilhar(&pilha);
}






int main() {

const char *expressao = "3 4 + 5 t *";
double resultado = avaliarExpressaoPosfixada(expressao);
printf("Resultado: %f\n", resultado);
return 0;
}