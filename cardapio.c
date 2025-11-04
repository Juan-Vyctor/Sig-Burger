#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "./include/util.h"
#include "./include/cardapio.h"
#include "./include/validacoes.h"

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
            tela_visualizar_produto();
        }
        else if (operacao_principal == 2)
        {
            tela_cadastrar_produto();
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
    printf("///   1. Visualizar Produto                                                 ///\n");
    printf("///   2. Cadastrar Produto                                                  ///\n");
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


void tela_visualizar_produto(void)
{
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));
    
    int contador = 1;
    int escolha;

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Cardápio Interativo                             ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");
    
    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        return;
    }

    printf("--- Produtos Disponíveis ---\n\n");
    
    // --- ETAPA 1: Listar todos os produtos ---
    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (prod->status == True)
        {
            printf("  %d. %s\n", contador, prod->nome);
            contador++;
        }
    }

    // Se contador == 1, nenhum produto foi encontrado
    if (contador == 1)
    {
        printf("\nNenhum produto ativo cadastrado.\n");
        fclose(arq_cardapio);
        free(prod);
        printf("\nPressione Enter para continuar...");
        getchar();
        getchar();
        return;
    }
    
    // --- ETAPA 2: Pedir a seleção do usuário ---
    printf("\nDigite o número do produto para ver os detalhes (ou 0 para sair): ");
    scanf("%d", &escolha);
    
    // Limpa o buffer de entrada (o '\n' deixado pelo scanf)
    // Isso é MUITO importante para os próximos 'getchar()'
    while (getchar() != '\n'); 
    
    // Se o usuário digitou 0 ou um número inválido
    if (escolha <= 0 || escolha >= contador)
    {
        printf("Saindo ou opção inválida...\n");
        getchar();
        fclose(arq_cardapio);
        free(prod);
        return;
    }
    
    // --- ETAPA 3: Buscar o produto escolhido ---
    
    // Volta o ponteiro do arquivo para o início
    rewind(arq_cardapio); 

    int contador_busca = 1;
    int encontrado = False;

    system("clear"); // Limpa a tela para mostrar os detalhes
    
    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        // Precisamos pular os produtos inativos
        if (prod->status == True)
        {
            // Se o contador ATUAL for igual à escolha do usuário...
            if (contador_busca == escolha)
            {
                printf("--- Detalhes do Produto ---\n\n");
                printf("Nome: %s\n", prod->nome);
                printf("Preço: R$ %s\n", prod->preco);
                printf("Ingredientes: %s\n", prod->ingredientes);
                
                encontrado = True;
                break; // Achamos o produto, podemos parar o loop
            }
            // Incrementa o contador APENAS se o produto estiver ativo
            contador_busca++; 
        }
    }

    fclose(arq_cardapio);
    free(prod);
    
    if (!encontrado)
    {
        // Isso não deve acontecer se a lógica estiver correta, mas é bom ter
        printf("\nErro: Produto não encontrado.\n");
    }
    
    printf("\nPressione Enter para voltar...");
    getchar(); // Pausa a tela
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
    ler_preco(prod->preco);
    getchar();
    ler_ingredientes(prod->ingredientes);
    getchar();

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

void tela_atualizar_produto(void)
{
    FILE *arq_cardapio;
    FILE *arq_temp;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));
    
    int contador = 1;
    int escolha = 0;
    int encontrado = False;

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Atualizar Produto                               ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");



    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        free(prod);
        return;
    }

    printf("--- Produtos Disponíveis para Atualizar ---\n\n");

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (prod->status == True)
        {
            printf("  %d. %s\n", contador, prod->nome);
            contador++;
        }
    }


    if (contador == 1)
    {
        printf("\nNenhum produto ativo cadastrado para atualizar.\n");
        fclose(arq_cardapio);
        free(prod);
        printf("\nPressione Enter para continuar...");
        getchar();
        return;
    }

    fclose(arq_cardapio); 

    
    
    printf("\nDigite o número do produto que deseja atualizar (ou 0 para cancelar): ");
    scanf("%d", &escolha);

    while (getchar() != '\n'); 

    if (escolha <= 0 || escolha >= contador)
    {
        printf("\nCancelando ou opção inválida...\n");
        free(prod);
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }


    arq_cardapio = fopen("arq_cardapio.dat", "rb");
    arq_temp = fopen("arq_cardapio_temp.dat", "wb");

    if (arq_cardapio == NULL || arq_temp == NULL)
    {
        printf("Erro ao reabrir arquivos para atualização.\n");
        getchar();
        free(prod);
        return;
    }

    int contador_busca = 1; 

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (prod->status == True && contador_busca == escolha)
        {
            encontrado = True;
            printf("\n--- Produto encontrado: %s ---\n", prod->nome);
            printf("Insira os novos dados (deixe em branco para manter):\n");

            printf("Novo nome \n");
            ler_nome(prod->nome); // Assumindo que esta função lê e valida o nome
            
            printf("Novo preço \n");
            ler_preco(prod->preco); // Assumindo que esta é a função com o loop do-while
            
            printf("Novos ingredientes \n");
            ler_ingredientes(prod->ingredientes); // Assumindo que esta é a função com o loop do-while

            printf("\nAtualizando produto...\n");
            getchar();

        }

      
        if (prod->status == True)
        {
            contador_busca++;
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
        getchar();
    }
    else
    {
       
        remove("arq_cardapio_temp.dat");
        printf("\nErro: Produto não encontrado durante a atualização.\n");
        getchar();

    }

    printf("\nPressione Enter para continuar...");
    getchar();
}

void tela_deletar_produto(void)
{
    FILE *arq_cardapio;
    Produto *prod;
    prod = (Produto*) malloc(sizeof(Produto));

    
    char resposta;
    int encontrado = False;
    
    int contador = 1; // Para a listagem
    int escolha = 0;  // Para a seleção do usuário

    system("clear");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///                   = = = = = Sig - Burguer = = = = =                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                         Deletar Produto                                 ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n\n");

   
    arq_cardapio = fopen("arq_cardapio.dat", "r+b"); 
    if (arq_cardapio == NULL)
    {
        printf("Erro ao abrir o arquivo de cardápio.\n");
        getchar();
        free(prod); 
        return;
    }

    printf("--- Produtos Disponíveis para Excluir ---\n\n");
    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        if (prod->status == True)
        {
            printf("  %d. %s\n", contador, prod->nome);
            contador++;
        }
    }

    
    if (contador == 1)
    {
        printf("\nNenhum produto ativo cadastrado para excluir.\n");
        fclose(arq_cardapio);
        free(prod);
        printf("\nPressione Enter para continuar...");
        getchar();
        return;
    }

     
    
    printf("\nDigite o número do produto que deseja excluir (ou 0 para cancelar): ");
    scanf("%d", &escolha);

 
    while (getchar() != '\n'); 

    arq_cardapio = fopen("arq_cardapio.dat", "r+b");
    
    if (escolha <= 0 || escolha >= contador)
    {
        printf("\nCancelando ou opção inválida...\n");
        free(prod);
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    
    if (arq_cardapio == NULL)
    {
        printf("Erro ao reabrir o arquivo para exclusão.\n");
        getchar();
        free(prod);
        return;
    }

    int contador_busca = 1; 

    while (fread(prod, sizeof(Produto), 1, arq_cardapio))
    {
        // Procura apenas entre os produtos ativos
        if (prod->status == True)
        {
            
            if (contador_busca == escolha)
            {
                encontrado = True;
                printf("\nProduto selecionado:\n");
                
                printf("Nome: %s\nPreço: R$ %s\nIngredientes: %s\n", prod->nome, prod->preco, prod->ingredientes);
                
                printf("\nDeseja realmente excluir esse produto? (S/N): ");
                scanf(" %c", &resposta);
                while (getchar() != '\n'); // Limpa o buffer
                resposta = toupper(resposta);

                if (resposta == 'S')
                {
                    
                    prod->status = False;
                    
                    
                    fseek(arq_cardapio, (-1) * sizeof(Produto), SEEK_CUR);
                    
                   
                    fwrite(prod, sizeof(Produto), 1, arq_cardapio);
                    
                    printf("\nProduto excluído com sucesso!\n");
                }
                else
                {
                    printf("\nOperação cancelada.\n");
                }
                break;
            }
            
            contador_busca++;
        }
    }

    fclose(arq_cardapio);
    free(prod);

    if (!encontrado)
    {
        printf("\nErro: Produto selecionado não foi encontrado na segunda verificação.\n");
    }

    printf("\nPressione Enter para continuar...");
    getchar();
}