#include <stdio.h>
#include <stdlib.h>
#include "./include/cliente.h"

void modulo_cliente(void){
    int operacao_principal;
    do{
        operacao_principal = tela_menu_clientes();
        
        if (operacao_principal == 1)
        {
            tela_cadastrar_cliente();
        }
        
        else if (operacao_principal == 2)
        {
            tela_listar_clientes();
        }
        
        else if (operacao_principal == 3)
        {
            tela_visualizar_cliente();
        }
        else if (operacao_principal == 4)
        {
            tela_cadastrar_endereco();
        }
        else if (operacao_principal == 5)
        {
            tela_visualizar_endereco();
        }

    } while (operacao_principal != 0);
}

int tela_menu_clientes(void)
{
    int operacao = 0;
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
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_cadastrar_cliente(void)
{
    
    char nome[51];
    char numero[12]; 
    char cpf[12];


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

    printf("Digite seu Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("Digite seu Celular (apenas números): ");
    scanf("%[0-9]", numero);
    getchar();
    printf("Digite seu cpf (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("cliente cadastrado!\n");
    printf("Digite enter para continuar!");
    getchar();
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