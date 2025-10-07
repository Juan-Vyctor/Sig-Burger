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
            tela_deletar_funcionario();
        }
        else if (operacao_principal == 4)
        {
            tela_atualizar_funcionario();
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
    printf("///   3. Deletar Funcionário                                                ///\n");
    printf("///   4. Atualizar Funcionário                                              ///\n");
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
    fprintf(arq_funcionario, "%s;\n", cargo);
    
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
    printf("///                           Buscar Funcionário                             ///\n");
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

    //Melhoramento de busca de funcionario.
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^;\n]", nome, cpf, numero, cargo ) == 4) {

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

void tela_deletar_funcionario(void)
{
    FILE *arq_funcionario;
    FILE *arq_funcionariostemp;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cargo[35];
    char cpf_lido[12];
    int encontrado = 0;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Deletar Funcionário                            ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do Funcionário (apenas números):                            ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    arq_funcionario = fopen("arq_funcionario.csv", "rt");
    if (arq_funcionario == NULL) {
        printf("Erro ao abrir o arquivo de Funcionários. \n");
        getchar();
        return;
    }

    arq_funcionariostemp = fopen("arq_funcionariostemp.csv", "wt");
    if (arq_funcionariostemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos Funcionários.""\n");
       fclose(arq_funcionario);
       getchar();
       return;
    }
    printf("Digite o CPF do Funcionário (apenas números):""\n");
    scanf("%s", cpf_lido);
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^\n]\n",nome, cpf, numero, cargo) == 4){
        if (strcmp(cpf, cpf_lido) !=0) {
        fprintf(arq_funcionariostemp, "%s;%s;%s\n", nome, cpf, numero);
        } else {
            encontrado = 1;
        }
    }
    fclose(arq_funcionario);
    fclose(arq_funcionariostemp);

    if (!encontrado) {
        printf("Funcionário com CPF %s não encontrado.\n", cpf_lido);
        remove("arq_funcionariostemp.csv");
        getchar();
        return;
    } 

    else {
        printf("Funcionário com CPF %s encontrado e excluido.\n", cpf_lido);
        
        if (remove("arq_funcionario.csv") != 0) {
            printf("Erro ao remover arq_funcionario.csv\n");
            getchar();
        }
        if (rename("arq_funcionariostemp.csv", "arq_funcionario.csv") != 0) {
            printf("Erro ao renomear arq_funcionariostemp.csv\n");
            getchar();
        }
    getchar();
    }
     
    printf("Funcionário excluido com sucesso!\n");
    getchar();
}

void tela_atualizar_funcionario(void)
{
    FILE *arq_funcionario;
    FILE *arq_funcionariostemp;
    char nome[51];
    char numero[12]; 
    char cpf[12];
    char cargo[25];
    char cpf_lido[12];
    int encontrado = 0;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Atualizar Funcionário                          ///\n");
    printf("///                                                                          ///\n");
    printf("/// Digite o CPF do Funcionário (apenas números):                            ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");

    arq_funcionario = fopen("arq_funcionario.csv", "rt");
    if (arq_funcionario == NULL) {
        printf("Erro ao abrir o arquivo de Funcionários.\n");
        getchar();
        return;
    }

    arq_funcionariostemp = fopen("arq_funcionariostemp.csv", "wt");
    if (arq_funcionariostemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos Funcionários.""\n");
       fclose(arq_funcionario);
       getchar();
       return;
    }


    printf("Digite o CPF do funcionário (apenas números):""\n");
    scanf("%s", cpf_lido);
    getchar();
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^\n]\n", nome, cpf, numero, cargo) == 4){
        if (strcmp(cpf, cpf_lido) == 0) {
            encontrado = 1;
            printf("Funcionário encontrado. Insira os novos dados do Funcionário: \n");

            printf("Digite seu Nome completo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
            getchar();
            
            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", cpf);
            getchar();
            
            printf("Digite seu celular (apenas números): ");
            scanf("%[0-9]", numero);
            getchar();

            printf("Digite seu Cargo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", cargo);
            getchar();

        } else {
            fprintf(arq_funcionariostemp, "%s;%s;%s;%s\n", nome, cpf, numero, cargo);
        } 
    }
        if (encontrado){
            fprintf(arq_funcionariostemp, "%s;%s;%s;%s\n", nome, cpf, numero, cargo);
            printf("Funcionário atualizado com sucesso!\n");
        }
        fclose(arq_funcionario);
        fclose(arq_funcionariostemp);

        if(!encontrado) {
            printf("Funcionário não encontrado!\n");
            remove("arq_funcionariostemp.csv");
            getchar();
        } else {
            
            if (remove("arq_funcionario.csv") != 0) {
                printf("Erro ao remover arq_funcionarios.csv\n");
            }
            if (rename("arq_funcionariostemp.csv", "arq_funcionario.csv") != 0) {
                printf("Erro ao  renomear o arq_funcionario.csv\n");
            }
        }
    getchar();
}

