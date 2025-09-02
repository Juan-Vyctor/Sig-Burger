#include <stdio.h>
#include <stdlib.h>
#include "modulos.h"

int tela_menu_cardapio(void)
{
    int operacao = 0;
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Menu do Cardápio                                ///\n");
    printf("///                                                                          ///\n");
    printf("///   1. Ver cardápio                                                        ///\n");
    printf("///   2. Fazer pedido                                                        ///\n");
    printf("///   3. Adicionar um novo produto                                           ///\n");
    printf("///   0. Voltar                                                              ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

int tela_cardapio(void)
{
    int operacao = 0;
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
    printf("///   Digite o número do produto que deseja ver, ou 0 para sair              ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_produto(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Detalhes do Pedido                             ///\n");
    printf("///                                                                          ///\n");
    printf("///   Item: Duplo Smash                                                      ///\n");
    printf("///   Preço: R$ 25,00                                                        ///\n");
    printf("///                                                                          ///\n");
    printf("///   Ingredientes:                                                          ///\n");
    printf("///     - Dois hambúrgueres smash 100g cada                                  ///\n");
    printf("///     - Queijo cheddar derretido                                           ///\n");
    printf("///     - Bacon crocante                                                     ///\n");
    printf("///     - Cebola caramelizada                                                ///\n");
    printf("///     - Picles                                                             ///\n");
    printf("///     - Molho especial da casa                                             ///\n");
    printf("///     - Pão brioche levemente tostado                                      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_adicionar_produto(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                        Adicionar Novo Hambúrguer                         ///\n");
    printf("///                                                                          ///\n");
    printf("///   Para cadastrar um novo hambúrguer, informe:                            ///\n");
    printf("///                                                                          ///\n");
    printf("///   - Nome do hambúrguer:                                                  ///\n");
    printf("///   - Preço (em R$):                                                       ///\n");
    printf("///   - Ingredientes (separe por vírgulas):                                  ///\n");
    printf("///                                                                          ///\n");
    printf("///   - Cada um dos detalhes deverá ser enviado numa mensagem separada       ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}