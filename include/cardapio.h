#ifndef CARDAPIO_H
#define CARDAPIO_H

typedef struct produto {
    char nome[50];
    float preco;
    char ingredientes[200];
    int status;
} Produto;

void modulo_cardapio(void);
int tela_menu_cardapio(void);
void tela_cadastrar_produto(void);
void tela_visualizar_produto(void);
void tela_atualizar_produto(void);
void tela_deletar_produto(void);

#endif
