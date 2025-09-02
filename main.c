#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"

//assinatura das funções

// funções de pedido
void tela_informacoes_pedido(void);
void tela_informar_item(void);

// funções de histórico
void tela_historico(void);

// funções gerais
int tela_principal(void);
void tela_sobre(void);
void tela_equipe(void);
void tela_confirmacao(void);
void tela_saida(void);

//progama principal
int main(void)
{
    system("clear");
    int operacao_principal = 0;
    int operacao_secundaria = 0;

    // variavel temporarária de auxílio
    int auxiliar = 0;
    do {
        operacao_principal = tela_principal();

        if (operacao_principal == 1)
        {
            auxiliar = tela_menu_cardapio();

            if (auxiliar == 1)
            {
                operacao_secundaria = tela_cardapio();
                
                if (operacao_secundaria != 0)
                {
                    tela_produto();
                }

            }

            else if (auxiliar == 2)
            {
                tela_informacoes_pedido();
            }

            else if (auxiliar == 3)
            {
                tela_adicionar_produto();
            }
                }

        else if (operacao_principal == 2)
        {
            tela_menu_clientes();
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

        else
        {
            tela_confirmacao();
        }

    } while (operacao_principal != 0);

    tela_saida();
    return 0;
}

//Funções
int tela_principal(void)
{
    int operacao = 0;
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cardápio                                                  ///\n");
    printf("///            2. Pedido                                                    ///\n");
    printf("///            3. Histórico                                                 ///\n");
    printf("///            4. Menu Clientes                                             ///\n");
    printf("///            5. Menu Funcionários                                         ///\n");
    printf("///            6. Sobre o Sig-Burguer                                       ///\n");
    printf("///            7. Sobre a Equipe                                            ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_informacoes_pedido(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                        informações do seu pedido                         ///\n");
    printf("///                                                                          ///\n");
    printf("///   Para realizar seu pedido, informe:                                     ///\n");
    printf("///                                                                          ///\n");
    printf("///   - Endereço de entrega (rua, número, bairro, complemento).              ///\n");
    printf("///   - Número(s) do(s) item(ns) desejado(s) do cardápio.                    ///\n");
    printf("///   - Nome do cliente para registrar o pedido.                             ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_informar_item(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                 Digite o número do item que deseja                       ///\n");
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

void tela_confirmacao(void)
{
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
}

void tela_saida(void)
{
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                  Obrigado por utilizar o Sig-Burger!                     ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}