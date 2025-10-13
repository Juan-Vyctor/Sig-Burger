#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// função do código: https://github.com/Thiago-braga7/Sig-DietPlan.git
char confirmar_acao(char valor) {
    valor = toupper(valor);  

    if (valor == 'S' || valor == 'N') {
        return valor; 
    }

    return 0; 
}