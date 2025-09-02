#include <stdio.h>
#include <stdlib.h>

//assinatura das funções

int tela_principal(void);

// funções de cliente
void tela_menu_clientes(void);
void tela_cadastrar_cliente(void);
void tela_listar_clientes(void);
void tela_visualizar_cliente(void);
void tela_cadastrar_endereco(void);
void tela_visualizar_endereco(void);

// funções funcionários
void tela_menu_funcionario(void);
void tela_cadastrar_funcionario(void);
void tela_listar_funcionarios(void);
void tela_visualizar_funcionario(void);

// funções de produtos
int tela_menu_cardapio(void);
int tela_cardapio(void);
void tela_produto(void);
void tela_adicionar_produto(void);

// funções de pedido
void tela_informacoes_pedido(void);
void tela_informar_item(void);

// funções de histórico
void tela_historico(void);

// funções gerais
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
            tela_informacoes_pedido();
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

void tela_menu_clientes(void) 
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Menu Clientes                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Clientes                                                 ///\n");
    printf("///   2. Listar Clientes                                                    ///\n");
    printf("///   3. Visualizar Clientes                                                ///\n");
    printf("///   4. Cadastrar Endereço                                                 ///\n");
    printf("///   5. Visualizar Endereço                                                ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_cadastrar_cliente(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Cadastro de Cliente                            ///\n");
    printf("///                                                                          ///\n");
    printf("///   Para se cadastrar, informe:                                            ///\n");
    printf("///                                                                          ///\n");
    printf("///   - Nome completo:                                                       ///\n");
    printf("///   - Telefone:                                                            ///\n");
    printf("///   - CPF:                                                                 ///\n");
    printf("///                                                                          ///\n");
    printf("///   - Senha:                                                               ///\n");
    printf("///   - Confirmar senha:                                                     ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_listar_clientes(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Lista de Clientes                              ///\n");
    printf("///                                                                          ///\n");
    printf("///   1. João da Silva Souza                                                 ///\n");
    printf("///   2. Maria Oliveira Santos                                               ///\n");
    printf("///   3. Pedro Henrique Almeida                                              ///\n");
    printf("///   4. Ana Clara Rodrigues                                                 ///\n");
    printf("///   5. Lucas Pereira Costa                                                 ///\n");
    printf("///                                                                          ///\n");
    printf("///   Digite o número do cliente que deseja visualizar:                      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_visualizar_cliente(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Dados do Cliente                                ///\n");
    printf("///                                                                          ///\n");
    printf("///   Nome completo:   João da Silva Souza                                   ///\n");
    printf("///   Telefone:        (11) 98765-4321                                       ///\n");
    printf("///   CPF:             123.456.789-00                                        ///\n");
    printf("///                                                                          ///\n");
    printf("///   Endereço:                                                              ///\n");
    printf("///       Rua das Flores, 123                                                ///\n");
    printf("///       Bairro: Centro                                                     ///\n");
    printf("///       Cidade: São Paulo - SP                                             ///\n");
    printf("///       Complemento: Apto 45, Bloco B                                      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_cadastrar_endereco(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///    Agora, informe seu endereço para entregas:                            ///\n");
    printf("///                                                                          ///\n");
    printf("///    Bairro:                                                               ///\n");
    printf("///    Rua:                                                                  ///\n");
    printf("///    Número:                                                               ///\n");
    printf("///    Complemento:                                                          ///\n");
    printf("///                                                                          ///\n"); 
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_visualizar_endereco(void)
{
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///   Endereço salvo no momento:                                             ///\n");
    printf("///       Rua das Flores, 123                                                ///\n");
    printf("///       Bairro: Centro                                                     ///\n");
    printf("///       Cidade: São Paulo - SP                                             ///\n");
    printf("///       Complemento: Apto 45, Bloco B                                      ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_menu_funcionario(void)
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Menu Funcionários                              ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Funcionário                                              ///\n");
    printf("///   2. Listar Funcionários                                                ///\n");
    printf("///   3. Visualizar Funcionário                                             ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_cadastrar_funcionario(void)
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Cadastrar Funcionários                           ///\n");
    printf("///                                                                         ///\n");
    printf("///   Para cadastrar o funcionário, informe:                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   - Nome completo:                                                      ///\n");
    printf("///   - Telefone:                                                           ///\n");
    printf("///   - CPF:                                                                ///\n");
    printf("///                                                                         ///\n");
    printf("///   - Cargo:                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
}
void tela_listar_funcionarios(void)
{
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                       Lista dos Funcionários                            ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Maria das Graças                                                   ///\n");
    printf("///                                                                         ///\n");
    printf("///    Digite o número do funcionário que deseja visualizar:                ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_visualizar_funcionario(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                       Dados do Funcionário                               ///\n");
    printf("///                                                                          ///\n");
    printf("///   Nome completo:   Maria das Graças                                      ///\n");
    printf("///   Telefone:        (11) 11111-1111                                       ///\n");
    printf("///   CPF:             111.111.111-11                                        ///\n");
    printf("///                                                                          ///\n");
    printf("///   Cargo: Atendente                                                       ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

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