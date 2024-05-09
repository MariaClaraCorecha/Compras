#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 10
#define MAX_NOME_LENGTH 50
#define MAX_ESCOLHA 5

typedef struct {
    char nome[20];
    float preco;
} Produto;

int main() {
    Produto produtos[] = {
        {"Biscoito", 2.50},
        {"Macarrão", 3.00},
        {"Arroz", 3.00},
        {"Feijão", 4.00},
        {"Maçã", 2.50},
        {"Banana", 1.50},
        {"Laranja", 2.50},
        {"Uva", 2.50},
        {"Morango", 3.50},
        {"Manga", 2.50}
    };

    char nome[MAX_NOME_LENGTH];
    int dia, mes, ano;
    int escolha[MAX_ESCOLHA] = {0};
    int numProdutos = 0;

    printf("Site de Compras\n\n");
    printf("Coloque suas informações para fazer o login:\n");
    
    fgets(nome, MAX_NOME_LENGTH, stdin);
    
    printf("Data de Nascimento (DD/MM/AAAA): ");
    scanf("%d/%d/%d", &dia, &mes, &ano);

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < MAX_ITEMS; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }

    printf("\nEscolha até 5 itens (Digite zero para parar):\n");
    for (int i = 0; i < MAX_ESCOLHA; i++) {
        printf("Escolha o item #%d: ", i + 1);
        scanf("%d", &escolha[i]);

        if (escolha[i] == 0) {
            break;
        }

        numProdutos++;
        
        if (numProdutos >= MAX_ESCOLHA) {
            printf("Limite de produtos atingido.\n");
            break;
        }
    }

    printf("\nInformações de login:\n");
    printf("\nNome: %s\n", nome);
    printf("Data de Nascimento: %d/%d/%d\n", dia, mes, ano);

    printf("\nItens Escolhidos:\n");
    float total = 0.0;
    for (int i = 0; i < numProdutos; i++) {
        int indice = escolha[i] - 1;
        printf("%s - R$ %.2f\n", produtos[indice].nome, produtos[indice].preco);
        total += produtos[indice].preco;
    }

    printf("\n\nTotal: R$ %.2f\n", total);

    return 0;
}
