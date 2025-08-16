#include <stdio.h>
#include <stdlib.h>

//assinatura das funções

void tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_cardapio(void);
void tela_fazer_pedido(void);
void tela_historico(void);

//progama principal
int main(void)
{
    system("clear");
    int operacao_principal;
    do {
        tela_principal();
        scanf("%d", &operacao_principal);

        if (operacao_principal == 1)
        {
            tela_cardapio();
        }
        else if (operacao_principal == 2)
        {
            tela_fazer_pedido();
        }
        else if (operacao_principal == 3)
        {
            tela_historico();
        } 
        else if (operacao_principal == 4)
        {
            tela_sobre();
        }
        else if (operacao_principal == 5)
        {
            tela_equipe();
        }
        else if (operacao_principal != 0)
        {
            printf("Está opção é inválida, retornando ao menu inicial...");
        }
    } while (operacao_principal != 0);

    printf("Obrigado por ter utilizado nosso sistema!");
    return 0;
}

//Funções
void tela_principal(void)
{
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cardápio                                                  ///\n");
    printf("///            2. Pedido                                                    ///\n");
    printf("///            3. Histórico                                                 ///\n");
    printf("///            4. Sobre o Sig-Burguer                                       ///\n");
    printf("///            5. Sobre a Equipe                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_sobre(void)
{
    system("clear");
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

void tela_equipe(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///             Este projeto está em desenvolvimento por:                    ///\n");
    printf("///                                                                          ///\n");
    printf("///             Renan Medeiros Nogueira                                      ///\n");
    printf("///             E-mail: renan.medeiros.150@ufrn.edu.br                       ///\n");
    printf("///             Git: https://github.com/Renan988                             ///\n");
    printf("///                                                                          ///\n");
    printf("///             Juan Vyctor Silva Garcia de Oliveira                         ///\n");
    printf("///             E-mail: juanvyctor.sgo@gmail.com                             ///\n");    
    printf("///             Git: https://github.com/Juan-Vyctor                          ///\n");
    printf("///                                                                          ///\n");
    printf("///      Link do Projeto: https://github.com/Juan-Vyctor/Sig-Burger.git      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_cardapio(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Cardápio                                   ///\n");
    printf("///                                                                          ///\n");
    printf("///   1. Clássico Burguer ................................. R$ 18,90         ///\n");
    printf("///   2. Cheddar Bacon .................................... R$ 22,50         ///\n");
    printf("///   3. Duplo Smash ...................................... R$ 25,00         ///\n");
    printf("///   4. Veggie Burguer ................................... R$ 20,00         ///\n");
    printf("///   5. Frango Crispy .................................... R$ 21,50         ///\n");
    printf("///   6. Super Burguer (artesanal 200g) ................... R$ 27,90         ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_fazer_pedido(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                            Faça seu pedido                               ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_historico(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                     Registro de pedidos do usuário                       ///\n");
    printf("///                                                                          ///\n");
    printf("///                               Em breve...                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}