#ifndef ENDERECOS_H
#define ENDERECOS_H
    
    typedef struct enderecos Enderecos;

    struct enderecos {

        char cpf[12];
        char rua[50];
        char bairro[25];
        char num_casa[4];
        int status;

    };



    void modulo_enderecos(void);
    int tela_menu_enderecos(void);
    void tela_cadastrar_endereco(void);
    void tela_visualizar_endereco(void);
    void tela_deletar_endereco(void);
    void tela_atualizar_endereco(void);
    
#endif