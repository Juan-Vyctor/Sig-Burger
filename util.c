#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "./include/validacoes.h"

// função do código: https://github.com/Thiago-braga7/Sig-DietPlan.git
char confirmar_acao(char valor)
{
    valor = toupper(valor);

    if (valor == 'S' || valor == 'N')
    {
        return valor;
    }

    return 0;
}

// Funções criadas com a extensão da gemini no próprio vscode (Gemini Code Assist 2.55.0)
void ler_nome(char *nome)
{
    int valido = 0;
    do
    {
        printf("Digite o nome: ");
        scanf(" %[^\n]", nome);
        valido = valida_nome(nome);
        if (!valido)
        {
            printf(":\nNome inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_cpf(char *cpf)
{
    int valido = 0;
    do
    {
        printf("Digite o CPF (apenas números): ");
        scanf(" %s", cpf);
        valido = valida_cpf(cpf);
        if (!valido)
        {
            printf("CPF inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_numero(char *numero)
{
    int valido = 0;
    do
    {
        printf("Digite o número (apenas números): ");
        scanf(" %11s", numero);
        valido = valida_numero(numero);
        if (!valido)
        {
            printf("Número inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_cargo(char *cargo)
{
    int valido = 0;
    do
    {
        printf("Digite o cargo: ");
        scanf(" %[^\n]", cargo);
        valido = valida_cargo(cargo);
        if (!valido)
        {
            printf("Cargo inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_rua(char *rua)
{
    int valido = 0;
    do
    {
        printf("Digite a rua: ");
        scanf(" %[^\n]", rua);
        valido = valida_nome(rua);
        if (!valido)
        {
            printf("Rua inválida! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_bairro(char *bairro)
{
    int valido = 0;
    do
    {
        printf("Digite o bairro: ");
        scanf(" %[^\n]", bairro);
        valido = valida_nome(bairro);
        if (!valido)
        {
            printf("Bairro inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_num_casa(char *num_casa)
{
    int valido = 0;
    do
    {
        printf("Digite o número da casa: ");
        scanf("%4s", num_casa);
        valido = valida_num_casa(num_casa);
        if (!valido)
        {
            printf("Número inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_preco(char *preco)
{
    int valido = 0;
    do
    {
        printf("Digite o preço: ");
        scanf("%s", preco);
        valido = valida_preco(preco);
        if (!valido)
        {
            printf("Preço inválido! Digite novamente.\n");
        }
    } while (!valido);
}

void ler_ingredientes(char *ingredientes)
{
    int valido = 0;
    do
    {
        printf("Digite os ingredientes (separe por vírgulas): ");
        scanf(" %[^\n]", ingredientes);
        valido = valida_ingredientes(ingredientes);
        if (!valido)
        {
            printf("Ingredientes inválidos! Digite novamente.\n");
        }
    } while (!valido);
}