#ifndef MODULOS_H
    #define MODULOS_H

    // Funções do módulo de Cardápio/Produtos
    void modulo_cardapio(void);
    int tela_menu_cardapio(void);
    int tela_cardapio(void);
    void tela_produto(void);
    void tela_adicionar_produto(void);

    // Funções do módulo de Cliente
    void tela_menu_clientes(void);
    void tela_cadastrar_cliente(void);
    void tela_listar_clientes(void);
    void tela_visualizar_cliente(void);
    void tela_cadastrar_endereco(void);
    void tela_visualizar_endereco(void);

    // Funções do módulo Funcionario
    void tela_menu_funcionario(void);
    void tela_cadastrar_funcionario(void);
    void tela_listar_funcionarios(void);
    void tela_visualizar_funcionario(void);

    // Funções do módulo Pedido
    void tela_informacoes_pedido(void);
    void tela_informar_item(void);
#endif