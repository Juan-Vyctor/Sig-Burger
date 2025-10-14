#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./include/util.h"
#define True 1
#define False 0
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
    Funcionario* func;
    func = (Funcionario*)malloc(sizeof(Funcionario));

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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
    getchar();
    printf("Digite o CPF (apenas números): ");
    scanf("%[0-9]", func->cpf);
    getchar();
    printf("Digite o Celular (apenas números): ");
    scanf("%[0-9]", func->numero);
    getchar();
    printf("Digite o cargo: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->cargo);
    getchar();
    printf("Funcionário cadastrado!\n");
    printf("Digite enter para continuar!\n");
    getchar();

    func->status = True;

    arq_funcionario = fopen("arq_funcionario.dat", "ab");
    if (arq_funcionario == NULL){
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar!");
        getchar();
        free(func);

        return;}
    
    fwrite(func, sizeof(Funcionario), 1, arq_funcionario);
    fclose(arq_funcionario);
    free(func);

    fclose(arq_funcionario);

}

void tela_visualizar_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario* func;
    func = (Funcionario*)malloc(sizeof(Funcionario));

    char cpf_lido[12];
    int encontrado;

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

    encontrado = False;

    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_funcionario = fopen("arq_funcionario.dat", "rb");

    if (arq_funcionario == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    while (fread(func, sizeof(Funcionario), 1, arq_funcionario)) {
        
        if (strcmp(func->cpf, cpf_lido) == 0 && func->status == True){
            printf("Funcionário encontrado!\n");
            printf("Nome: %s\n", func->nome);
            printf("CPF: %s\n", func->cpf);
            printf("Telefone: %s\n", func->numero);
            printf("Cargo: %s\n", func->cargo);
            printf("\n");
            printf("Tecle Enter para continuar...");
            getchar();
            fclose(arq_funcionario);
            encontrado = True;
            return;
        }
    }
    fclose(arq_funcionario);
    free(func);

    if (encontrado == False) {
        printf("CPF não encontrado!\n");
        printf("\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
}


void tela_atualizar_funcionario(void)
{
    FILE *arq_funcionario;
    FILE *arq_funcionariostemp;
    Funcionario* func;
    func = (Funcionario*)malloc(sizeof(Funcionario));

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
    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    arq_funcionario = fopen("arq_funcionario.dat", "rb");
    if (arq_funcionario == NULL) 
    {
        printf("Erro ao abrir o arquivo de Funcionários.\n");
        getchar();
        return;
    }

    arq_funcionariostemp = fopen("arq_funcionariostemp.dat", "wb");
    if (arq_funcionariostemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos Funcionários.""\n");
       getchar();
       return;
    }

    while (fread(func, sizeof(Funcionario), 1, arq_funcionario)) {
        if (strcmp(func -> cpf, cpf_lido) == 0 && func -> status == True)  {
            encontrado = True;

            printf("Funcionário encontrado. Insira os novos dados do Funcionário: \n");

            printf("Digite seu Nome completo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->nome);
            getchar();
            
            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", func->cpf);
            getchar();
            
            printf("Digite seu celular (apenas números): ");
            scanf("%[0-9]", func->numero);
            getchar();

            printf("Digite seu Cargo: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", func->cargo);
            getchar();

        } 
        fwrite(func, sizeof(Funcionario), 1, arq_funcionariostemp);
    }

    fclose(arq_funcionario);
    fclose(arq_funcionariostemp);

    if (encontrado) {
        remove("arq_funcionario.dat");
        rename("arq_funcionariostemp.dat", "arq_funcionario.dat");
        printf("\nFuncionário Alterado com sucesso!\n");
    } else {
        remove("arq_funcionariostemp.dat");
        printf("\nFuncionário não encontrado!\n");
    }
    
    free(func);
    getchar();
    
}

void tela_deletar_funcionario(void)
{
    FILE *arq_funcionario;

    Funcionario* func;
    func = malloc(sizeof(Funcionario));

    char cpf_lido[12];
    char resposta;
    int encontrado;

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
    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    if (func == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }

    arq_funcionario = fopen("arq_funcionario.dat", "r+b");

    if (arq_funcionario == NULL) {
        printf("Erro ao abrir o arquivo de Funcionários. \n");
        getchar();
        return;
    }

        while (fread(func, sizeof(Funcionario), 1, arq_funcionario)) {
            if (strcmp(func -> cpf, cpf_lido) !=0 && func->status == True) {
                printf("Funcionário encontrado\n");
                printf("Nome: %s\n", func->nome);
                printf("CPF: %s\n", func->cpf);
                printf("Telefone: %s\n", func->numero);
                printf("Cargo: %s\n", func->cargo);
                getchar();

                encontrado = True;
            }
            do {
                printf("\nDeseja realmente excluir esse funcionário? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);
                
                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while(resposta == 0);

            if (resposta == 'S')
            {
                func->status = False;
                fseek(arq_funcionario, (-1)*sizeof(Funcionario), SEEK_CUR);
                fwrite(func, sizeof(Funcionario), 1, arq_funcionario);
                printf("\nFuncionário excluído com sucesso!\n");
            } 
            
            else 
            { 
                printf("\nFuncionário não excluido.\n");
            }
            break;
        }
    fclose(arq_funcionario);

    if (encontrado == False) {
        printf("Funcionário com CPF %s não encontrado.\n", cpf_lido);
        getchar();
        return;
    } 
}