/*
#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"


 //Retorna 1 se o caractere recebido for um caractere alfabético 
 //(letra entre 'A' e 'Z' ou entre 'a' e 'z') ou retorna 0 caso contrário

int ehletra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}






 //Retorna 1 se string recebido for exclusivamente alfabético ou
 //retorna 0 caso contrário
int validar_nome(char* nome) {
    for (int i=0; nome[i]!='\0'; i++) {
        if (!ehLetra(nome[i])) {
            return 0;
        }
    }
    return 1;
}
*/