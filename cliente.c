#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/cliente.h"
//#include "./include/validacoes.h"

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
            tela_visualizar_cliente();
        } 
        else if (operacao_principal == 3)
        {
            tela_atualizar_cliente();
        }
        else if (operacao_principal == 4)
        {
            tela_deletar_cliente();
        }
        else if (operacao_principal == 5)
        {
            tela_listar_clientes();
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
    printf("///   2. Visualizar Clientes                                                ///\n");
    printf("///   3. Atualizar Clientes                                                 ///\n");
    printf("///   4. Deletar Clientes                                                   ///\n");
    printf("///   5. Listar Clientes                                                    ///\n");
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
    FILE *arq_cliente;
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
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Digite seu Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("Digite seu cpf (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("Digite seu Celular (apenas números): ");
    scanf("%[0-9]", numero);
    getchar();
    printf("cliente cadastrado!\n");
    printf("Digite enter para continuar!");
    getchar();

    arq_cliente = fopen("arq_cliente.csv", "at");
    if (arq_cliente == NULL){
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar");
        getchar();

        return;}
    
    fprintf(arq_cliente, "%s;", nome);
    fprintf(arq_cliente, "%s;", cpf);
    fprintf(arq_cliente, "%s;", numero);

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
    getchar();
}

void tela_visualizar_cliente(void)
{
    FILE *arq_cliente;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Buscar Cliente                                 ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do cliente (apenas números):                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    scanf("%s", cpf_lido);
    getchar();

    arq_cliente = fopen("arq_cliente.csv", "r");

    if (arq_cliente == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    while (!feof(arq_cliente)) {
        fscanf(arq_cliente, "%[^;]", nome);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;]", cpf);
        fgetc(arq_cliente);
        fscanf(arq_cliente, "%[^;\n]", numero);
        fgetc(arq_cliente);
    

        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Cliente encontrado\n");
            printf("Nome: %s\n", nome);
            printf("CPF: %s\n", cpf);
            printf("Telefone: %s\n", numero);
            getchar();
            fclose(arq_cliente);
            return;
        }
    }
}

void tela_deletar_cliente(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Deletar Cliente                                ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do cliente (apenas números):                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}

void tela_atualizar_cliente(void)
{
    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Atualizar Cliente                              ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do cliente (apenas números):                                ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
}