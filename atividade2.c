#include <stdio.h>

void aplicar_desconto(float *preco, float percentual) {
    *preco = *preco * (1.0f - percentual / 100.0f);
}

int main(void) {
    float preco = 100.0f;

    printf("Preco original: %.2f\n", preco);

    aplicar_desconto(&preco, 10.0f);

    printf("Preco apos desconto de 10%%: %.2f\n", preco);

    return 0;
}
