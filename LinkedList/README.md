# Listas encadeadas

Uma lista encadeada é uma representação de uma sequência de objetos, todos do mesmo tipo, na memória RAM (= random access memory) do computador. Cada elemento da sequência é armazenado em uma célula da lista: o primeiro elemento na primeira célula, o segundo na segunda, e assim por diante.

## Estrutura de uma lista encadeada

Uma lista encadeada  (= linked list = lista ligada)  é uma sequência de células; cada célula contém um objeto (todos os objetos são do mesmo tipo) e o endereço da célula seguinte.  Neste capítulo, suporemos que os objetos armazenados nas células são do tipo int.  Cada célula é um registro que pode ser definido assim:

```c
struct reg {
    int         conteudo; 
    struct reg *prox;
};

typedef struct reg celula;  
```

# Referência

[Projeto de Algoritmos](https://www.ime.usp.br/~pf/algoritmos/aulas/lista.html)