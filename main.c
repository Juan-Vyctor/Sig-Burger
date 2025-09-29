#include <stdio.h>
#include <stdlib.h>
#include "./include/cardapio.h"
#include "./include/cliente.h"
#include "./include/funcionario.h"
#include "./include/geral.h"
#include "./include/historico.h"
#include "./include/pedido.h"
#include "./include/enderecos.h"

//progama principal
int main(void)
{
    system("clear");
    int operacao_principal = 0;
    
    do {
        operacao_principal = tela_principal();

        if (operacao_principal == 1)
        {
            modulo_cardapio();
        }

        else if (operacao_principal == 2)
        {
            modulo_cliente();
        }

        else if (operacao_principal == 3)
        {
            modulo_funcionario();
        }

        else if (operacao_principal == 4)
        {
            tela_historico();
        }

        else if (operacao_principal == 5)
        {
            tela_sobre();
        }

        else if (operacao_principal == 6)
        {
            tela_equipe();
        }

        else if (operacao_principal == 7)
        {
            tela_menu_enderecos();
        }

        else if (operacao_principal != 0)
        {
            system("clear");
            printf("Está opção é inválida, retornando ao menu inicial...\n");
        }

        else
        {
            operacao_principal = tela_confirmacao();
        }

    } while (operacao_principal != 0);

    tela_saida();
    return 0;
}