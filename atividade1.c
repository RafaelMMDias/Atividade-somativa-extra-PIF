#include <stdio.h>

int main(void) {
    float preco = 100.0f;
    float *ptr_preco = &preco;

    *ptr_preco = *ptr_preco * 1.10f;

    printf("Preco apos aumento de 10%%: %.2f\n", preco);

    return 0;
}
