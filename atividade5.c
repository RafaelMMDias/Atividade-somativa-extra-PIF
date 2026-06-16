
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

void imprimir_produtos(Produto *ptr, int quantidade) {
    int i;

    printf("\n--- Estoque de Produtos ---\n");
    for (i = 0; i < quantidade; i++) {
        printf("ID: %d | Preco: R$ %.2f\n", (ptr + i)->id, (ptr + i)->preco);
    }
    printf("---------------------------\n");
}

int main(void) {
    int quantidade;
    Produto *estoque;
    Produto *ptr;
    int i;

    printf("Quantos produtos deseja cadastrar? ");
    if (scanf("%d", &quantidade) != 1 || quantidade <= 0) {
        printf("Quantidade invalida.\n");
        return 1;
    }

    estoque = (Produto *)malloc((size_t)quantidade * sizeof(Produto));
    if (estoque == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (ptr = estoque, i = 0; ptr < estoque + quantidade; ptr++, i++) {
        printf("\nProduto %d:\n", i + 1);
        printf("  ID: ");
        scanf("%d", &ptr->id);
        printf("  Preco: R$ ");
        scanf("%f", &ptr->preco);
    }

    imprimir_produtos(estoque, quantidade);

    printf("\nAplicar desconto de 10%% em todos os produtos? (s/n): ");
    char resposta;
    scanf(" %c", &resposta);
    if (resposta == 's' || resposta == 'S') {
        for (ptr = estoque; ptr < estoque + quantidade; ptr++) {
            aplicar_desconto(ptr, 10.0f);
        }
        printf("\nEstoque apos desconto:\n");
        imprimir_produtos(estoque, quantidade);
    }

    free(estoque);

    return 0;
}
