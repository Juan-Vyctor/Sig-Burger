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
    Funcionario func;

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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func.nome);
    getchar();
    printf("Digite o CPF (apenas números): ");
    scanf("%[0-9]", func.cpf);
    getchar();
    printf("Digite o Celular (apenas números): ");
    scanf("%[0-9]", func.numero);
    getchar();
    printf("Digite o cargo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func.cargo);
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
    
    fprintf(arq_funcionario, "%s;", func.nome);
    fprintf(arq_funcionario, "%s;", func.cpf);
    fprintf(arq_funcionario, "%s;", func.numero);
    fprintf(arq_funcionario, "%s;\n", func.cargo);
    
    fclose(arq_funcionario);

    fclose(arq_funcionario);

}

void tela_visualizar_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario func;
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

    scanf("%s", func.cpf_lido);
    getchar();
    system("clear");
    printf("CPF Digitado: %s\n", func.cpf_lido);
    printf("\n");

    arq_funcionario = fopen("arq_funcionario.csv", "rt");

    if (arq_funcionario == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    //Melhoramento de busca de funcionario.
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^;\n]", func.nome, func.cpf, func.numero, func.cargo ) == 4) {

        if (strcmp(func.cpf, func.cpf_lido) == 0) {
            printf("Funcionário encontrado!\n");
            printf("Nome: %s\n", func.nome);
            printf("CPF: %s\n", func.cpf);
            printf("Telefone: %s\n", func.numero);
            printf("Cargo: %s\n", func.cargo);
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
    Funcionario func;
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
    scanf("%s", func.cpf_lido);
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^\n]\n",func.nome, func.cpf, func.numero, func.cargo) == 4){
        if (strcmp(func.cpf, func.cpf_lido) !=0) {
        fprintf(arq_funcionariostemp, "%s;%s;%s\n", func.nome, func.cpf, func.numero);
        } else {
            encontrado = 1;
        }
    }
    fclose(arq_funcionario);
    fclose(arq_funcionariostemp);

    if (!encontrado) {
        printf("Funcionário com CPF %s não encontrado.\n", func.cpf_lido);
        remove("arq_funcionariostemp.csv");
        getchar();
        return;
    } 

    else {
        printf("Funcionário com CPF %s encontrado e excluido.\n", func.cpf_lido);
        
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
    Funcionario func;
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
    scanf("%s", func.cpf_lido);
    getchar();
    while (fscanf(arq_funcionario, "%[^;];%[^;];%[^;];%[^\n]\n", func.nome, func.cpf, func.numero, func.cargo) == 4){
        if (strcmp(func.cpf, func.cpf_lido) == 0) {
            encontrado = 1;
            printf("Funcionário encontrado. Insira os novos dados do Funcionário: \n");

            printf("Digite seu Nome completo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func.nome);
            getchar();
            
            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", func.cpf);
            getchar();
            
            printf("Digite seu celular (apenas números): ");
            scanf("%[0-9]", func.numero);
            getchar();

            printf("Digite seu Cargo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func.cargo);
            getchar();

        } else {
            fprintf(arq_funcionariostemp, "%s;%s;%s;%s\n", func.nome, func.cpf, func.numero, func.cargo);
        } 
    }
        if (encontrado){
            fprintf(arq_funcionariostemp, "%s;%s;%s;%s\n", func.nome, func.cpf, func.numero, func.cargo);
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

