#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./include/util.h"
#include "./include/cliente.h"
#define True 1
#define False 0
// #include "./include/validacoes.h"

void modulo_cliente(void)
{
    int operacao_principal;
    do
    {
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
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
    getchar();
    printf("Digite seu CPF (apenas números): ");
    scanf("%[0-9]", cli->cpf);
    getchar();
    printf("Digite seu celular (apenas números): ");
    scanf("%[0-9]", cli->numero);
    getchar();
    printf("cliente cadastrado!\n");
    printf("Digite enter para continuar!");
    getchar();

    cli->status = True;

    arq_cliente = fopen("arq_cliente.dat", "ab");
    if (arq_cliente == NULL)
    {
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar");
        getchar();
        free(cli);

        return;
    }

    fwrite(cli, sizeof(Cliente), 1, arq_cliente);
    fclose(arq_cliente);
    free(cli);

    fclose(arq_cliente);

}

void tela_visualizar_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

    char cpf_lido[12];
    int encontrado;

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

    encontrado = False;

    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_cliente = fopen("arq_cliente.dat", "rb");

    if (arq_cliente == NULL)
    {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }
    // REMOVER FEOF!!! mas dps
    while (fread(cli, sizeof(Cliente), 1, arq_cliente))
    {

        if (strcmp(cli -> cpf, cpf_lido) == 0 && cli -> status == True)
        {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", cli->nome);
            printf("CPF: %s\n", cli->cpf);
            printf("Telefone: %s\n", cli->numero);
            printf("\n");
            printf("Tecle Enter para continuar...");
            getchar();
            encontrado = True;
            return;
        }
    }

    fclose(arq_cliente);
    free(cli);

    if (encontrado == False)
    {
        printf("Cliente não encontrado!\n");
        printf("\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
}


void tela_atualizar_cliente(void)
{
    FILE *arq_cliente;
    FILE *arq_clientestemp;
    Cliente* cli;
    cli = (Cliente*)malloc(sizeof(Cliente));

    char cpf_lido[12];
    char encontrado;

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
    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    arq_cliente = fopen("arq_cliente.dat", "rb");
    if (arq_cliente == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        getchar();
        return;
    }

    arq_clientestemp = fopen("arq_clientestemp.dat", "wb");
    if (arq_clientestemp == NULL)
    {
        printf("erro ao abrir o arquivo temporario dos clientes.\n");
        getchar();
        return;
    }

    while (fread(cli, sizeof(Cliente), 1, arq_cliente))
    {
        if (strcmp(cli -> cpf, cpf_lido) == 0 && cli -> status == True)
        {   
            encontrado = True;
        
            printf("Cliente encontrado. Insira os novos dados do cliente: \n");

            printf("Digite seu Nome completo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cli->nome);
            getchar();

            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", cli->cpf);
            getchar();

            printf("Digite seu celular (apenas números): ");
            scanf("%[0-9]", cli->numero);
            getchar();
        }
        fwrite(cli, sizeof(Cliente), 1, arq_clientestemp);
    }
    
    fclose(arq_cliente);
    fclose(arq_clientestemp);

    if (encontrado)
    {
        remove("arq_cliente.dat");
        rename("arq_clientestemp.dat", "arq_cliente.dat");
        printf("\nCliente Alterado com sucesso!\n");
    } 
    
    else 
    {
        remove("arq_paciente_temp.dat");
        printf("\nCliente não encontrado!\n");
    }

    free(cli);
    getchar();
}

void tela_deletar_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = malloc(sizeof(Cliente));

    char cpf_lido[12];
    char resposta;
    int encontrado;

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
    scanf("%s", cpf_lido);

    encontrado = False;
    
    if (cli == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }

    arq_cliente = fopen("arq_cliente.dat", "r+b");
    if (arq_cliente == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes. \n");
        getchar();
        return;
    }
    
        while (fread(cli, sizeof(Cliente), 1, arq_cliente)){
            if (strcmp(cli -> cpf, cpf_lido) == 0 && cli->status == True)
            {
                printf("Cliente encontrado\n");
                printf("Nome: %s\n", cli->nome);
                printf("CPF: %s\n", cli->cpf);
                printf("Telefone: %s\n", cli->numero);
                getchar();
                encontrado = True;
            }
            do {
                printf("\nDeseja realmente excluir esse Cliente? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while(resposta == 0);

            if (resposta == 'S')
            {
                cli->status = False;
                fseek(arq_cliente, (-1)*sizeof(Cliente), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, arq_cliente);
                printf("\nPaciente excluído com sucesso!\n");
                getchar();
            } 
            
            else 
            { 
                printf("\nCliente não excluido.\n");
                getchar();
            }
            break;
        }

    fclose(arq_cliente);

    if (encontrado == False)
    {
        printf("Cliente com CPF %s não encontrado.\n", cpf_lido);
        getchar();
        return;
    }
}