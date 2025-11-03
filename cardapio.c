#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "./include/util.h"
#include "./include/cardapio.h"

#define True 1
#define False 0

void modulo_cardapio(void)
{
    int operacao_principal;
    do
    {
        operacao_principal = tela_menu_cardapio();

        if (operacao_principal == 1)
        {
            tela_cadastrar_produto();
        }
        else if (operacao_principal == 2)
        {
            tela_visualizar_produto();
        }
        else if (operacao_principal == 3)
        {
            tela_atualizar_produto();
        }
        else if (operacao_principal == 4)
        {
            tela_deletar_produto();
        }

    } while (operacao_principal != 0);
}

int tela_menu_cardapio(void)
{
    int operacao = 0;
    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                  = = = = = Sig - Burguer = = = = =                      ///\n");
    printf("///                                                                         ///\n");
    printf("///                          Menu do Cardápio                               ///\n");
    printf("///                                                                         ///\n");
    printf("///   1. Cadastrar Produto                                                  ///\n");
    printf("///   2. Visualizar Produto                                                 ///\n");
    printf("///   3. Atualizar Produto                                                  ///\n");
    printf("///   4. Deletar Produto                                                    ///\n");
    printf("///   0. Voltar                                                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    scanf("%d", &operacao);
    getchar();
    return operacao;
}

void tela_cadastrar_produto(void)
{
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                        Cadastro de Produto                              ///\n");
    printf("///                                                                         ///\n");
    printf("///   Informe os dados do novo produto:                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");

    ler_nome(prod->nome);
    printf("Preço (ex: 25.90): ");
    scanf("%f", &prod->preco);
    getchar();
    printf("Ingredientes (separe por vírgulas): ");
    fgets(prod->ingredientes, sizeof(prod->ingredientes), stdin);
    prod->ingredientes[strcspn(prod->ingredientes, "\n")] = '\0'; // remover \n
    prod->status = True;

    arq_cardapio = fopen("arq_cardapio.dat", "ab");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao criar arquivo do cardápio.\n");
        printf("Pressione Enter para continuar...");
        getchar();
        free(prod);
        return;
    }

    fwrite(prod, sizeof(Produto), 1, arq_cardapio);
    fclose(arq_cardapio);
    free(prod);

    printf("\nProduto cadastrado com sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void tela_visualizar_produto(void)
{
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    char nome_lido[50];
    int encontrado = False;

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Buscar Produto                                  ///\n");
    printf("///                                                                         ///\n");
    printf("/// Digite o nome do produto:                                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");

    fgets(nome_lido, sizeof(nome_lido), stdin);
    nome_lido[strcspn(nome_lido, "\n")] = '\0';

    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        return;
    }

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (strcmp(prod->nome, nome_lido) == 0 && prod->status == True)
        {
            printf("\nProduto encontrado!\n");
            printf("Nome: %s\n", prod->nome);
            printf("Preço: R$ %.2f\n", prod->preco);
            printf("Ingredientes: %s\n", prod->ingredientes);
            encontrado = True;
            break;
        }
    }

    fclose(arq_cardapio);
    free(prod);

    if (!encontrado)
    {
        printf("\nProduto não encontrado.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

void tela_atualizar_produto(void)
{
    FILE *arq_cardapio;
    FILE *arq_temp;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    char nome_lido[50];
    int encontrado = False;

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Atualizar Produto                               ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");

    printf("Digite o nome do produto que deseja atualizar: ");
    fgets(nome_lido, sizeof(nome_lido), stdin);
    nome_lido[strcspn(nome_lido, "\n")] = '\0';

    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    arq_temp = fopen("arq_cardapio_temp.dat", "wb");

    if (arq_cardapio == NULL || arq_temp == NULL)
    {
        printf("Erro ao abrir arquivos.\n");
        getchar();
        return;
    }

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (strcmp(prod->nome, nome_lido) == 0 && prod->status == True)
        {
            encontrado = True;
            printf("\nProduto encontrado. Insira os novos dados:\n");
            ler_nome(prod->nome);
            printf("Novo preço: ");
            scanf("%f", &prod->preco);
            getchar();
            printf("Novos ingredientes: ");
            fgets(prod->ingredientes, sizeof(prod->ingredientes), stdin);
            prod->ingredientes[strcspn(prod->ingredientes, "\n")] = '\0';
        }
        fwrite(prod, sizeof(Produto), 1, arq_temp);
    }

    fclose(arq_cardapio);
    fclose(arq_temp);
    free(prod);

    if (encontrado)
    {
        remove("arq_cardapio.dat");
        rename("arq_cardapio_temp.dat", "arq_cardapio.dat");
        printf("\nProduto atualizado com sucesso!\n");
    }
    else
    {
        remove("arq_cardapio_temp.dat");
        printf("\nProduto não encontrado.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

void tela_deletar_produto(void)
{
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    char nome_lido[50];
    char resposta;
    int encontrado = False;

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Deletar Produto                                 ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");

    printf("Digite o nome do produto: ");
    fgets(nome_lido, sizeof(nome_lido), stdin);
    nome_lido[strcspn(nome_lido, "\n")] = '\0';

    arq_cardapio = fopen("arq_cardapio.dat", "r+b");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        return;
    }

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (strcmp(prod->nome, nome_lido) == 0 && prod->status == True)
        {
            encontrado = True;
            printf("\nProduto encontrado:\n");
            printf("Nome: %s\nPreço: R$ %.2f\nIngredientes: %s\n", prod->nome, prod->preco, prod->ingredientes);
            
            printf("\nDeseja realmente excluir esse produto? (S/N): ");
            scanf(" %c", &resposta);
            getchar();
            resposta = toupper(resposta);

            if (resposta == 'S')
            {
                prod->status = False;
                fseek(arq_cardapio, (-1)*sizeof(Produto), SEEK_CUR);
                fwrite(prod, sizeof(Produto), 1, arq_cardapio);
                printf("\nProduto excluído com sucesso!\n");
            }
            else
            {
                printf("\nOperação cancelada.\n");
            }
            break;
        }
    }

    fclose(arq_cardapio);
    free(prod);

    if (!encontrado)
    {
        printf("\nProduto não encontrado.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}
