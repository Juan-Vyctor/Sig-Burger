#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/funcionario.h"

void modulo_funcionario(void)
{
    int operacao_principal;
    do{
        operacao_principal = tela_menu_funcionario();
        if (operacao_principal == 1)
        {
            tela_cadastrar_funcionario();
        }
        
        else if (operacao_principal == 2)
        {
            tela_visualizar_funcionario();
        }
        
        else if (operacao_principal == 3)
        {
            tela_listar_funcionarios();
        }
    } while (operacao_principal != 0);
}

int tela_menu_funcionario(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Menu Funcionários                              ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Funcionário                                              ///\n");
    printf("///   2. Visualizar Funcionário                                             ///\n");
    printf("///   3. Listar Funcionários                                                ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_cadastrar_funcionario(void)
{
     FILE *arq_funcionario;
    char nome[51];
    char cpf[12];
    char numero[12];
    char cargo[35]; 

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
    printf("///   - CPF:                                                                ///\n");
    printf("///   - Telefone:                                                           ///\n");
    printf("///                                                                         ///\n");
    printf("///   - Cargo:                                                              ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    printf("Digite o Nome completo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("Digite o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("Digite o Celular (apenas números): ");
    scanf("%[0-9]", numero);
    getchar();
    printf("Digite o cargo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cargo);
    getchar();
    printf("Funcionário cadastrado!\n");
    printf("Digite enter para continuar!\n");
    getchar();

    arq_funcionario = fopen("arq_funcionario.csv", "at");
    if (arq_funcionario == NULL){
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar!");
        getchar();

        return;}
    
    fprintf(arq_funcionario, "%s;", nome);
    fprintf(arq_funcionario, "%s;", cpf);
    fprintf(arq_funcionario, "%s;", numero);
    fprintf(arq_funcionario, "%s;", cargo);

    fclose(arq_funcionario);

}

void tela_visualizar_funcionario(void)
{
    FILE *arq_funcionario;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cpf_lido[12];
    char cargo[35];
    int encontrado = 0;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Buscar Cliente                                 ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do Funcionário (apenas números):                            ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    scanf("%s", cpf_lido);
    getchar();
    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_funcionario = fopen("arq_funcionario.csv", "rt");

    if (arq_funcionario == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    while (!feof(arq_funcionario)) {
        fscanf(arq_funcionario, "%[^;]", nome);
        fgetc(arq_funcionario);
        fscanf(arq_funcionario, "%[^;]", cpf);
        fgetc(arq_funcionario);
        fscanf(arq_funcionario, "%[^;]", numero);
        fgetc(arq_funcionario);
        fscanf(arq_funcionario, "%[^;\n]", cargo);
        fgetc(arq_funcionario);
    

        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Funcionário encontrado!\n");
            printf("Nome: %s\n", nome);
            printf("CPF: %s\n", cpf);
            printf("Telefone: %s\n", numero);
            printf("Cargo: %s\n", cargo);
            printf("\n");
            printf("Tecle Enter para continuar...");
            encontrado = 1;
            getchar();
            fclose(arq_funcionario);
            return;
        }
    }
    fclose(arq_funcionario);
    
    if (!encontrado) {
        printf("CPF não encontrado!\n");
        printf("\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
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
    getchar();
}