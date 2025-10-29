#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./include/enderecos.h"
#include "./include/util.h"
#define True 1
#define False 0

void modulo_enderecos(void){
    int operacao_principal;
    do{
        operacao_principal = tela_menu_enderecos();
        
        if (operacao_principal == 1)
        {
            tela_cadastrar_endereco();
        }
        else if (operacao_principal == 2)
        {
            tela_visualizar_endereco();
        } 
       else if (operacao_principal == 3)
        {
            tela_atualizar_endereco();
        }
        else if (operacao_principal == 4)
        {
            tela_deletar_endereco();
        }
    } while (operacao_principal != 0);
}

int tela_menu_enderecos(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                            Menu Endereços                               ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Endereços                                                ///\n");
    printf("///   2. Visualizar Endereços                                               ///\n");
    printf("///   3. Atualizar Endereços                                                ///\n");
    printf("///   4. Deletar Endereços                                                  ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_cadastrar_endereco(void)
{
    FILE *arq_endereco;
    Enderecos* end;
    end = (Enderecos*)malloc(sizeof(Enderecos));


    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Cadastrar Endereço                              ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
   
    ler_cpf(end->cpf);
    getchar();
    
    ler_rua(end->rua);
    getchar();
    
    ler_bairro(end->bairro);
    getchar();
    
    ler_num_casa(end->num_casa);
    getchar();
    
    printf("Endereço cadastrado!\n");
    printf("Digite enter para continuar!\n");
    getchar();

    end->status = True;

    arq_endereco = fopen("arq_endereco.dat", "ab");
    if (arq_endereco == NULL){
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar");
        getchar();
        free(end);

        return;}
    
    fwrite(end, sizeof(Enderecos), 1, arq_endereco);
    fclose(arq_endereco);
    free(end);

}

void tela_visualizar_endereco(void)
{
    FILE *arq_endereco;
    Enderecos* end;
    end = (Enderecos*)malloc(sizeof(Enderecos));

    char cpf_lido[12];
    int encontrado;


    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Visualizar Endereço                             ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Digite o CPF (apenas números):\n");

    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_endereco = fopen("arq_endereco.dat", "rb");

    if (arq_endereco == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

    while (fread(end, sizeof(Enderecos), 1, arq_endereco)) {
        
        if (strcmp(end->cpf, cpf_lido) == 0 && end->status == True) {
            printf("Endereço encontrado!\n");
            printf("CPF: %s\n", end->cpf);
            printf("Rua: %s\n", end->rua);
            printf("Bairro: %s\n", end->bairro);
            printf("Numero da Casa: %s\n", end->num_casa);
            printf("\n");
            printf("Tecle Enter para continuar...");
            encontrado = True;
            getchar();
            fclose(arq_endereco);
            return;
        }
    }
    fclose(arq_endereco);
    free(end);

    if (!encontrado == False) {
        printf("Endereço não encontrado!\n");
        printf("\n");
        printf("Pressione Enter para continuar...");
        getchar();
    }
}

void tela_atualizar_endereco(void)
{
    FILE *arq_endereco;
    FILE *arq_enderecotemp;

    Enderecos* end;
    end = (Enderecos*)malloc(sizeof(Enderecos));

    char cpf_lido[12];
    int encontrado;


    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Atualizar Endereço                              ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Digite o CPF (apenas números):\n");
    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    arq_endereco = fopen("arq_endereco.dat", "rb");

    if (arq_endereco == NULL)
    {
        printf("Erro ao abrir o arquivo de Endereços.\n");
        getchar();
        return;
    }

    arq_enderecotemp = fopen("arq_enderecotemp.dat", "wb");
    if (arq_enderecotemp == NULL) 
    {
       printf("erro ao abrir o arquivo temporario dos Endereços.""\n");
       getchar();
       return;
    }


        
    while (fread(end, sizeof(Enderecos), 1, arq_endereco)) {
        if (strcmp(end->cpf, cpf_lido) == 0 && end->status == True) {
            encontrado = True;
            printf("Endereço encontrado. Insira os novos dados do endereço: \n");

            ler_cpf(end->cpf);
            getchar();

            ler_rua(end->rua);
            getchar();

            ler_bairro(end->bairro);
            getchar();

            ler_num_casa(end->num_casa);
            getchar();

        } 
        fwrite(end, sizeof(Enderecos), 1, arq_enderecotemp);
    } 

    fclose(arq_endereco);
    fclose(arq_enderecotemp);

    if (encontrado){
        remove("arq_endereco.dat");
        rename("arq_enderecotemp.dat", "arq_endereco.dat");
        printf("\nEndereço Alterado com sucesso!\n");
    } else {
        remove("arq_enderecotemp.dat");
        printf("\nEndereço não encontrado!\n");
    }
    free(end);
    getchar();
}

void tela_deletar_endereco(void)
{
    FILE *arq_endereco;
    Enderecos* end;
    end = malloc(sizeof(Enderecos));

    char cpf_lido[12];
    int encontrado;
    char resposta;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Deletar Endereço                               ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("Digite o CPF (apenas números):\n");
    scanf("%s", cpf_lido);
    getchar();

    encontrado = False;

    if (end == NULL)
    {
        printf("Erro na alocação de memória.\n");
    }

    arq_endereco= fopen("arq_endereco.dat", "rb");

    if (arq_endereco== NULL)
     {
        printf("Erro ao abrir o arquivo de Endereços. \n");
        getchar();
        return;
    }

        while (fread(end, sizeof(Enderecos), 1, arq_endereco)) {
            if (strcmp(end->cpf, cpf_lido) !=0 && end->status == True) {
                printf("Endereço encontrado\n");
                printf("CPF: %s\n", end->cpf);
                printf("Rua: %s\n", end->rua);
                printf("Bairro: %s\n", end->bairro);
                printf("Numero da Casa: %s\n", end->num_casa);
                getchar();

                encontrado = True; 

            }
            do {
                printf("\nDeseja realmente excluir esse endereço? (S/N): ");
                scanf(" %c", &resposta);
                resposta = confirmar_acao(resposta);

                if(resposta == 0){
                    printf("Opção inválida! Digite apenas S ou N.\n");
                }

            } while(resposta == 0);

            if (resposta == 'S')
            {
                end->status = False;
                fseek(arq_endereco, (-1)*sizeof(Enderecos), SEEK_CUR);
                fwrite(end, sizeof(Enderecos), 1, arq_endereco);
                printf("\nEndereço excluído com sucesso!\n");
                getchar();
            } 
            
            else 
            { 
                printf("\nEndereço não excluido.\n");
                getchar();
            }
            break;
        }
        
    fclose(arq_endereco);

    if (encontrado == False) {
        printf("Endereço com CPF %s não encontrado.\n", cpf_lido);
        getchar();
        return;
    } 
}           

            



