#include <stdio.h>
#include "avaliacao.h"
#include "Pilha.h"
#include <math.h>

int main() {
    const char *expressao = "3 4 + 5 t *";
    double resultado = avaliarExpressaoPosfixada(expressao);
    printf("Resultado: %f\n", resultado);
    return 0;
}
