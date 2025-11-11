#include <stdio.h>
#include <stdlib.h>
#include "./include/cardapio.h"
#include "./include/cliente.h"
#include "./include/funcionario.h"
#include "./include/geral.h"
#include "./include/historico.h"
#include "./include/pedido.h"
#include "./include/enderecos.h"
#include "./include/relatorio.h"

// programa principal
int main(void)
{
    int opcao_gestao = 0; // controle do menu de gestão

    do
    {
        tela_gestao();
        scanf("%d", &opcao_gestao);
        getchar();

        switch (opcao_gestao)
        {
        case 1:
        {
            int operacao_principal = 0;

            do
            {
                operacao_principal = tela_principal();

                switch (operacao_principal)
                {
                case 1:
                    modulo_cardapio();
                    break;

                case 2:
                    modulo_cliente();
                    break;

                case 3:
                    modulo_funcionario();
                    break;

                case 4:
                    modulo_enderecos();
                    break;

                case 5:
                    relatorio();
                    break;

                case 0:
                    operacao_principal = tela_confirmacao_voltar();
                    break;

                default:
                    system("clear");
                    printf("Esta opção é inválida, retornando ao menu inicial...\n");
                    break;
                }

            } while (operacao_principal != 0);

            tela_saida();
            break;
        }

        case 2:
            tela_sobre();
            break;

        case 3:
            tela_equipe();
            break;

        case 0:
            opcao_gestao = tela_confirmacao();
            break;

        default:
            system("clear");
            printf("Opção inválida! Tente novamente.\n");
            break;
        }

    } while (opcao_gestao != 0);

    system("clear");
    tela_saida();

    return 0;
}