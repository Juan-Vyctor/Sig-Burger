#include <stdio.h>
#include <stdlib.h>
#include "./include/geral.h"

void tela_gestao(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Tela de Gestão                                 ///\n");
    printf("///                                                                          ///\n");
    printf("///                   1 - Menu Pricipal                                      ///\n");
    printf("///                   2 - Sobre o Programa                                   ///\n");
    printf("///                   3 - Desenvolvedores                                    ///\n");
    printf("///                   0 - Sair do Sig-Burguer                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

int tela_principal(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cardápio                                                  ///\n");
    printf("///            2. Menu Clientes                                             ///\n");
    printf("///            3. Menu Funcionários                                         ///\n");
    printf("///            4. Menu Endereços                                            ///\n");
    printf("///            5. Histórico de pedidos                                      ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
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
    getchar();
    getchar();
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
    getchar();
    getchar();
}

int tela_confirmacao_voltar(void)
{
    int operacao = 0;
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                      Deseja voltar a gestão                              ///\n");
    printf("///                                                                          ///\n");
    printf("///                   1 - Continuar no Menu Principal                        ///\n");
    printf("///                   0 - Voltar                                             ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

int tela_confirmacao(void)
{
    int operacao = 0;
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                      Deseja finalizar o programa?                        ///\n");
    printf("///                                                                          ///\n");
    printf("///                   1 - Continuar no Sig-Burguer                           ///\n");
    printf("///                   0 - Sair do Sig-Burguer                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_saida(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                  Obrigado por utilizar o Sig-Burger!                     ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}