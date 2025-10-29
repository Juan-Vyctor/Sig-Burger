#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>

int valida_nome(char *nome) {
    setlocale(LC_CTYPE, "");

    int tamanho = strlen(nome);

    // Permite nomes a partir de 2 letras
    if (tamanho < 2) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        unsigned char c = nome[i];

        // Permite apenas letras, espaços e acentos
        if (!(isalpha(c) || c == ' ' || strchr("áàâãäéèêëíìîïóòôõöúùûüçÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇ", c))) {
            return 0;
        }
    }

    return 1;
}

int valida_cpf(char *cpf) {
    setlocale(LC_CTYPE, "");
    int tamanho = strlen(cpf);

    if (tamanho != 11) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(cpf[i])) {
            return 0;
        }
    }

    return 1;
}

int valida_numero(char *numero) {
    setlocale(LC_CTYPE, "");
    int tamanho = strlen(numero);

    if (tamanho < 11) {
        return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(numero[i])) {
            return 0;
        }
    }

    return 1;
}

int valida_cargo(char *cargo) {
    setlocale(LC_CTYPE, "");

    int tamanho = strlen(cargo);

    if (tamanho < 2) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        unsigned char c = cargo[i];
        if (!(isalpha(c) || c == ' ' || strchr("áàâãäéèêëíìîïóòôõöúùûüçÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇ", c))) {
            return 0;
        }
    }

    return 1;
}

int valida_rua(char *rua) {
    setlocale(LC_CTYPE, "");

    int tamanho = strlen(rua);

    // Permite nomes a partir de 2 letras
    if (tamanho < 2) {
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        unsigned char c = rua[i];

        // Permite apenas letras, espaços e acentos
        if (!(isalpha(c) || c == ' ' || strchr("áàâãäéèêëíìîïóòôõöúùûüçÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇ", c))) {
            return 0;
        }
    }

    return 1;
}

int valida_bairro(char *bairro) {
    setlocale(LC_CTYPE, "");

    int tamanho = strlen(bairro);
    if (tamanho < 2) {
        return 0;
    }
    for (int i = 0; i < tamanho; i++) {
        unsigned char c = bairro[i];
        if (!(isalpha(c) || c == ' ' || strchr("áàâãäéèêëíìîïóòôõöúùûüçÁÀÂÃÄÉÈÊËÍÌÎÏÓÒÔÕÖÚÙÛÜÇ", c))) {
            return 0;
        }
    }

    return 1;
}

int valida_num_casa(char *num_casa) {
    setlocale(LC_CTYPE, "");

    int tamanho = strlen(num_casa);

    if (tamanho < 1 || tamanho > 4) {
        return 0;
    }
    
    for (int i = 0; i < tamanho; i++) {
        if (!isdigit(num_casa[i])) {
            return 0;
        }
    }

    return 1;
}
