#include <stdio.h>

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
    Produto estoque[3] = {
        {101, 29.90f},
        {102, 49.50f},
        {103, 15.00f}
    };

    imprimir_produtos(estoque, 3);

    aplicar_desconto(estoque + 1, 20.0f);

    printf("\nApos desconto de 20%% no produto ID 102:\n");
    imprimir_produtos(estoque, 3);

    return 0;
}
