#include <stdio.h>

//assinatura das funções

void tela_principal(void);
void tela_sobre(void);

//progama principal
int main(void)
{
    printf("Bem vindo a Sig Burguers!");

    int operacao_principal;
    do {
        printf("\nDigite 1 para o cardápio, 2 para um pedido, 3 para o histórico, 4 para nosso Sobre, e 0 para finalizar:\n");
        scanf("%d", &operacao_principal);
        printf("\n");

        if (operacao_principal == 1)
        {
            printf("Aqui está o Cardápio");
        }
        else if (operacao_principal == 2)
        {
            printf("Faça o seu pedido");
        }
        else if (operacao_principal == 3)
        {
            printf("Aqui está o histórico dos seus pedidos");
        } 
        else if (operacao_principal == 4) {
            printf("Sobre nós");
        } 
        else if (operacao_principal != 0) {
            printf("Está opção é inválida, retornando ao menu inicial...");
        }
    } while (operacao_principal != 0);

    printf("Obrigado por ter utilizado nosso sistema!");
    return 0;
}

//Funções
void tela_principal(void) {
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cardápio                                                  ///\n");
    printf("///            2. Pedido                                                    ///\n");
    printf("///            3. Histórico                                                 ///\n");
    printf("///            4. Sobre o Sig-Burguer                                       ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}


void tela_sobre(void) {
    printf("\n")
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///  Sistema de hamburgueria voltado para atendimento via delivery.         ///\n");
    printf("///  Permite cadastrar clientes, gerenciar pedidos, controlar o cardápio    ///\n");
    printf("///  e acompanhar o status das entregas. Oferece ferramentas para agilizar  ///\n");
    printf("///  o atendimento e manter o histórico de vendas de forma simples e segura.///\n");
    printf("///                                                                         ///\n");
    printf("///  Ideal para otimizar o processo de compra, preparar pedidos e garantir  ///\n");
    printf("///  a satisfação dos clientes em um serviço rápido e eficiente.            ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}