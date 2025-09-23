
# SIG BURGUER

**Um Sistema de Gestão de uma Hamburgueria**

---

##  Descrição do Projeto

Este projeto é uma atividade de avaliação do curso de **Bacharelado em Sistemas de Informação da UFRN - Campus Caicó**.
O sistema tem como objetivo auxiliar na **gestão de uma hamburgueria**, oferecendo funcionalidades organizadas em módulos.

---

##  Estrutura e Modularização

O sistema será dividido em módulos, cada um responsável por uma parte do projeto.
Essa abordagem facilita:

* Entendimento
* Manutenção
* Desenvolvimento

---

##  Tecnologias Utilizadas

* **Linguagem:** C
* **IDE:** Visual Studio Code (VS Code)

---

##  Como Rodar

### 🔹 Pré-requisitos

Antes de começar, instale no seu computador:

1. **Visual Studio Code (VS Code)** → [Download aqui](https://code.visualstudio.com/)
2. **GCC (compilador C)**

   * Windows: instale o pacote **MinGW**
   * Linux/Mac: geralmente já vem instalado
3. **Extensão "C/C++" da Microsoft no VS Code**

   * Instale pela aba de extensões (`Ctrl + Shift + X`)

---

### 🔹 Passo a Passo

1. **Abrir o projeto no VS Code**

   * Vá em **File > Open Folder** e selecione a pasta onde está o arquivo `sig_bar`.

2. **Abrir o Terminal no VS Code**

   * Menu: **Terminal > Novo Terminal**
   * Atalho: `Ctrl + '` (crase)

3. **Compilar o programa**
   No terminal, execute:

   ```bash
   gcc main.c cardapio.c historico.c funcionario.c geral.c cliente.c -o sig_burger
   ```

   Isso gera o executável `sig_burger`.

4. **Rodar o programa**

   * **Windows:**

     ```bash
     ./sig_burger.exe
     ```

   * **Linux/Mac:**

     ```bash
     ./sig_burger
     ```

---

## ⚠ Problemas Comuns

| Problema                                 | Solução                                                                         |
| ---------------------------------------- | ------------------------------------------------------------------------------- |
| `'gcc' não é reconhecido`                | GCC não instalado ou variável de ambiente não configurada. Instale o **MinGW**. |
| `Permissão negada ao rodar ./sig_burger` | No Linux/Mac, rode: `chmod +x sig_burger`.                                      |
| Saída incorreta                          | Verifique se os arquivos foram salvos (`Ctrl + S`) antes de compilar.           |

---

### Equipe de desenvolvimentp

| Integrante                       | E-mail                                                                              |
| -------------------------------- | ----------------------------------------------------------------------------------- |
| Renan Medeiros Nogueira          | [renan.medeiros.nogueira.150@ufrn.edu.br](mailto:infobasicifrn2017marcusv@gmailcom) |
| Luis Felipe Linhares Pereira     | [luis.felipe.linhares.701@ufrn.edu.br](mailto:luis.felipe.linhares.701@ufrn.edu.br) |
|      | [](mailto:) |
