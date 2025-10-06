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
    printf("///   - CPF:                                                                 ///\n");
    printf("///   - Telefone:                                                            ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Digite seu Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("Digite seu CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("Digite seu celular (apenas números): ");
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
    fprintf(arq_cliente, "%s\n", numero);

}

void tela_visualizar_cliente(void)
{
    FILE *arq_cliente;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];
    int encontrado = 0;

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
    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_cliente = fopen("arq_cliente.csv", "r");

    if (arq_cliente == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }
// REMOVER FEOF!!! mas dps
    while (fscanf(arq_cliente, "%[^;];%[^;];%[^;]", nome, cpf, numero ) == 3) {
        
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", nome);
            printf("CPF: %s\n", cpf);
            printf("Telefone: %s\n", numero);
            printf("\n");
            printf("Tecle Enter para continuar...");
            getchar();
            encontrado = 1;
            fclose(arq_cliente);
            return;
        }
    }
    fclose(arq_cliente);

    if (!encontrado) {
        printf("Cliente não encontrado!\n");
        printf("\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
}

void tela_deletar_cliente(void)
{
    FILE *arq_cliente;
    FILE *arq_clientestemp;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];
    int encontrado = 0;

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

    arq_cliente = fopen("arq_cliente.csv", "rt");
    if (arq_cliente == NULL) {
        printf("Erro ao abrir o arquivo de clientes. \n");
        getchar();
        return;
    }

    arq_clientestemp = fopen("arq_clientestemp.csv", "wt");
    if (arq_clientestemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos clientes.""\n");
       fclose(arq_cliente);
       getchar();
       return;
    }
    printf("Digite o CPF do cliente (apenas números):""\n");
    scanf("%s", cpf_lido);
    while (fscanf(arq_cliente, "%[^;];%[^;];%[^\n]\n",nome, cpf, numero) == 3){
        if (strcmp(cpf, cpf_lido) !=0) {
        fprintf(arq_clientestemp, "%s;%s;%s\n", nome, cpf, numero);
        } else {
            encontrado = 1;
        }
    }
    fclose(arq_cliente);
    fclose(arq_clientestemp);

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido);
        remove("arq_clientestemp.csv");
        getchar();
        return;
    } 

    else {
        printf("Cliente com CPF %s encontrado e excluido.\n", cpf_lido);
        
        if (remove("arq_cliente.csv") != 0) {
            printf("Erro ao remover arq_cliente.csv\n");
            getchar();
        }
        if (rename("arq_clientestemp.csv", "arq_cliente.csv") != 0) {
            printf("Erro ao renomear arq_clientestemp.csv\n");
            getchar();
        }
    getchar();
    }
     
    printf("Cliente excluido com sucesso!\n");
    getchar();
}

void tela_atualizar_cliente(void)
{
    FILE *arq_cliente;
    FILE *arq_clientestemp;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];
    int encontrado = 0;

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

    arq_cliente = fopen("arq_cliente.csv", "rt");
    if (arq_cliente == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        getchar();
        return;
    }

    arq_clientestemp = fopen("arq_clientestemp.csv", "wt");
    if (arq_clientestemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos clientes.""\n");
       fclose(arq_cliente);
       getchar();
       return;
    }


    printf("Digite o CPF do cliente (apenas números):""\n");
    scanf("%s", cpf_lido);
    getchar();
    while (fscanf(arq_cliente, "%[^;];%[^;];%[^\n]\n",nome, cpf, numero) == 3){
        if (strcmp(cpf, cpf_lido) == 0) {
            encontrado = 1;
            printf("Cliente encontrado. Insira os novos dados do cliente: \n");

            printf("Digite seu Nome completo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
            getchar();
            
            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", cpf);
            getchar();
            
            printf("Digite seu celular (apenas números): ");
            scanf("%[0-9]", numero);
            getchar();

        } else {
            fprintf(arq_clientestemp, "%s;%s;%s\n", nome, cpf, numero);
        } 
    }
        if (encontrado){
            fprintf(arq_clientestemp, "%s;%s;%s\n", nome, cpf, numero);
            printf("Cliente atualizado com sucesso!\n");
        }
        fclose(arq_cliente);
        fclose(arq_clientestemp);

        if(!encontrado) {
            printf("Cliente não encontrado!\n");
            remove("arq_clientestemp.csv");
            getchar();
        } else {
            
            if (remove("arq_cliente.csv") != 0) {
                printf("Erro ao remover clientes.csv\n");
            }
            if (rename("arq_clientestemp.csv", "arq_cliente.csv") != 0) {
                printf("Erro ao  renomear o arq_cliente.csv\n");
            }
        }
    getchar();
}