#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./include/enderecos.h"

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
    char cpf[12];
    char rua[25];
    char bairro[20];
    char num_casa[4];

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Cadastrar Endereço                              ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
   
    printf("Digite o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
    printf("Digite o Nome da Rua: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", rua);
    getchar();
    printf("Digite o Nome do Bairro: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", bairro);
    getchar();
    printf("Digite o numero da casa (apenas números): ");
    scanf("%[0-4]", num_casa);
    getchar();
    printf("Endereço cadastrado!\n");
    printf("Digite enter para continuar!\n");
    getchar();


    arq_endereco = fopen("arq_endereco.csv", "at");
    if (arq_endereco == NULL){
        printf("erro na criaçao do arquivo!\n");
        printf("Digite enter para continuar");
        getchar();

        return;}
    
    fprintf(arq_endereco, "%s;", cpf);
    fprintf(arq_endereco, "%s;", rua);
    fprintf(arq_endereco, "%s;", bairro);
    fprintf(arq_endereco, "%s;\n", num_casa);

    fclose(arq_endereco);

}

void tela_visualizar_endereco(void)
{
    FILE *arq_endereco;
    char cpf[12];
    char cpf_lido[12];
    char rua[25];
    char bairro[20];
    char num_casa[4];
    int encontrado = 0;

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
    system("clear");
    printf("CPF Digitado: %s\n", cpf_lido);
    printf("\n");

    arq_endereco = fopen("arq_endereco.csv", "rt");

    if (arq_endereco == NULL) {
        printf("Erro na criacao do arquivo\n");
        getchar();
        return;
    }

// REMOVER FEOF!!! mas dps
    while (fscanf(arq_endereco, "%[^;];%[^;];%[^;];%[^;\n]", cpf, rua, bairro, num_casa ) == 4) {
        
        if (strcmp(cpf, cpf_lido) == 0) {
            printf("Endereço encontrado!\n");
            printf("CPF: %s\n", cpf);
            printf("Rua: %s\n", rua);
            printf("Bairro: %s\n", bairro);
            printf("Numero da Casa: %s\n", num_casa);
            printf("\n");
            printf("Tecle Enter para continuar...");
            encontrado = 1;
            getchar();
            fclose(arq_endereco);
            return;
        }
    }
    fclose(arq_endereco);

    if (!encontrado) {
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
    char cpf[12];
    char cpf_lido[12];
    char rua[25];
    char bairro[20];
    char num_casa[4];
    int encontrado = 0;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                          Atualizar Endereço                              ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();

    arq_endereco = fopen("arq_endereco.csv", "rt");

    if (arq_endereco == NULL) {
        printf("Erro ao abrir o arquivo de Endereços.\n");
        getchar();
        return;
    }

    arq_enderecotemp = fopen("arq_enderecotemp.csv", "wt");
    if (arq_enderecotemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos Endereços.""\n");
       fclose(arq_endereco);
       getchar();
       return;
    }


    printf("Digite o CPF (apenas números):""\n");
    scanf("%s", cpf_lido);
    getchar();
    while (fscanf(arq_endereco, "%[^;];%[^;];%[^;];%[^\n]\n",cpf, rua, bairro, num_casa) == 4){
        if (strcmp(cpf, cpf_lido) == 0) {
            encontrado = 1;
            printf("Endereço encontrado. Insira os novos dados do endereço: \n");

            printf("Digite seu CPF (apenas números): ");
            scanf("%[0-9]", cpf);
            getchar();

            printf("Digite o Nome da rua: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", rua);
            getchar();
            
            printf("Digite o Nome do bairro: ");
            scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", bairro);
            getchar();
            
            printf("Digite o Numero da Casa (apenas números): ");
            scanf("%[0-4]", num_casa);
            getchar();

        } else {
            fprintf(arq_enderecotemp, "%s;%s;%s;%s\n", cpf, rua, bairro, num_casa);
        } 
    }
        if (encontrado){
            fprintf(arq_enderecotemp, "%s;%s;%s;%s\n", cpf, rua, bairro, num_casa);
            printf("Endereço atualizado com sucesso!\n");
        }
        fclose(arq_endereco);
        fclose(arq_enderecotemp);

        if(!encontrado) {
            printf("Endereço não encontrado!\n");
            remove("arq_enderecotemp.csv");
            getchar();
        } else {
            
            if (remove("arq_endereco.csv") != 0) {
                printf("Erro ao remover Endereços.csv\n");
            }
            if (rename("arq_enderecotemp.csv", "arq_endereco.csv") != 0) {
                printf("Erro ao renomear o arq_endereco.csv\n");
            }
        }
    getchar();
}

void tela_deletar_endereco(void)
{
    FILE *arq_endereco;
    FILE *arq_enderecotemp; 
    char cpf[12];
    char cpf_lido[12];
    char rua[25];
    char bairro[20];
    char num_casa[4];
    int encontrado = 0;

    system("clear");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                          ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                          ///\n");
    printf("///                           Deletar Endereço                               ///\n");
    printf("///                                                                          ///\n");
    printf("////////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    getchar();
    
    arq_endereco= fopen("arq_endereco.csv", "rt");
    if (arq_endereco== NULL) {
        printf("Erro ao abrir o arquivo de Endereços. \n");
        getchar();
        return;
    }

    arq_enderecotemp = fopen("arq_enderecotemp.csv", "wt");
    if (arq_enderecotemp == NULL) {
       printf("erro ao abrir o arquivo temporario dos Endereços.""\n");
       fclose(arq_endereco);
       getchar();
       return;
    }
    printf("Digite o CPF (apenas números):\n");
    scanf("%s", cpf_lido);
    while (fscanf(arq_endereco, "%[^;];%[^;];%[^;]%[^\n]\n",cpf, rua, bairro, num_casa) == 4){
        if (strcmp(cpf, cpf_lido) !=0) {
        fprintf(arq_enderecotemp, "%s;%s;%s;%s\n",cpf, rua, bairro, num_casa);
        } else {
            encontrado = 1;
        }
    }
    fclose(arq_endereco);
    fclose(arq_enderecotemp);

    if (!encontrado) {
        printf("Endereço com CPF %s não encontrado.\n", cpf_lido);
        remove("arq_enderecotemp.csv");
        getchar();
        return;
    } 

    else {
        printf("Endereço com CPF %s encontrado e excluido.\n", cpf_lido);
        
        if (remove("arq_endereco.csv") != 0) {
            printf("Erro ao remover arq_endereco.csv\n");
            getchar();
        }
        if (rename("arq_enderecotemp.csv", "arq_endereco.csv") != 0) {
            printf("Erro ao renomear arq_enderecotemp.csv\n");
            getchar();
        }
    getchar();
    }
        
    printf("Endereço excluido com sucesso!\n");
    getchar();
}



