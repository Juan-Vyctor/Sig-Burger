#ifndef CLIENTE_H
#define CLIENTE_H
    
    typedef struct cliente Cliente;

    struct cliente {

    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];

};

    void modulo_cliente(void);
    int tela_menu_clientes(void);
    void tela_cadastrar_cliente(void);
    void tela_deletar_cliente(void);
    void tela_visualizar_cliente(void);
    void tela_atualizar_cliente(void);
    
#endif