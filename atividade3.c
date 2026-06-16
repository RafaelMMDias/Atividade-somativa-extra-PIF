#include <stdio.h>

typedef struct {
    int id;
    float preco;
} Produto;

void aplicar_desconto(Produto *produto, float percentual) {
    produto->preco = produto->preco * (1.0f - percentual / 100.0f);
}

int main(void) {
    Produto item = {1, 100.0f};

    printf("Produto %d - Preco original: %.2f\n", item.id, item.preco);

    aplicar_desconto(&item, 10.0f);

    printf("Produto %d - Preco apos desconto de 10%%: %.2f\n", item.id, item.preco);

    return 0;
}
