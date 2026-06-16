# Atividade Somativa Extra - PIF (Ponteiros em C)

Repositório com a resolução das atividades sobre fundamentos de ponteiros, passagem por referência, structs, aritmética de ponteiros e alocação dinâmica de memória.

## Estrutura do projeto

| Arquivo        | Descrição                                              |
|----------------|--------------------------------------------------------|
| `atividade1.c` | Ponteiro básico e modificação direta de um `float`     |
| `atividade2.c` | Função `aplicar_desconto` com passagem por referência  |
| `atividade3.c` | Struct `Produto` e operador `->`                       |
| `atividade4.c` | Array estático e `imprimir_produtos` com aritmética    |
| `atividade5.c` | Alocação dinâmica com `malloc` e `free`                |

## Como compilar e executar

Requer um compilador C (GCC, Clang ou MinGW):

```bash
gcc atividade1.c -o atividade1 && ./atividade1
gcc atividade2.c -o atividade2 && ./atividade2
gcc atividade3.c -o atividade3 && ./atividade3
gcc atividade4.c -o atividade4 && ./atividade4
gcc atividade5.c -o atividade5 && ./atividade5
```

No Windows (PowerShell):

```powershell
gcc atividade1.c -o atividade1.exe; .\atividade1.exe
```

## Resolução por atividade

### Atividade 1 — Fundamentos de Ponteiros

- Variável `preco` inicializada com `100.0`.
- Ponteiro `ptr_preco` aponta para o endereço de `preco`.
- O aumento de 10% é feito **somente** via `*ptr_preco`, sem alterar `preco` diretamente na `main`.
- A impressão final usa a variável original para comprovar a alteração.

### Atividade 2 — Passagem por Referência

- A lógica de alteração sai da `main` e vai para `void aplicar_desconto(float *preco, float percentual)`.
- A função recebe o endereço do preço e modifica o valor na memória original.
- Na `main`, a chamada é `aplicar_desconto(&preco, 10.0f)`.

### Atividade 3 — Ponteiros para Structs

- Criada a struct `Produto` com campos `id` (int) e `preco` (float).
- `aplicar_desconto` passa a receber `Produto *produto`.
- O campo `preco` é acessado e modificado com `produto->preco`.

### Atividade 4 — Aritmética de Ponteiros em Arrays

- Array estático de 3 `Produto` na `main`.
- Função `imprimir_produtos(Produto *ptr, int quantidade)` percorre o vetor usando `(ptr + i)->id` e `(ptr + i)->preco`.
- **Não** é utilizada a sintaxe `ptr[i]`.

### Atividade 5 — Alocação Dinâmica

- O programa pergunta quantos produtos cadastrar.
- `malloc` aloca memória para o array de `Produto`.
- O preenchimento itera com ponteiros (`ptr = estoque; ptr < estoque + quantidade; ptr++`).
- Chama `imprimir_produtos` e libera a memória com `free(estoque)`.

## Autor

Rafael M. M. Dias
