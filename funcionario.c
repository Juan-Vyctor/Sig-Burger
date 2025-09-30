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
    printf("///   - CPF:                                                                ///\n");
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
    getchar();
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