#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

    typedef struct funcionario Funcionario;

    struct funcionario {

        char nome[51];
        char numero[12]; 
        char cpf[12];
        char cargo[35];
        int status;
        
    };

    void modulo_funcionario(void);
    int tela_menu_funcionario(void);
    void tela_cadastrar_funcionario(void);
    void tela_visualizar_funcionario(void);
    void tela_atualizar_funcionario(void);
    void tela_deletar_funcionario(void);

#endif