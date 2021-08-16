/**
 * Altura.  A altura de uma célula c em uma lista encadeada é a distância entre c
 * e o fim da lista. Mais precisamente, a altura de c é o número de passos do caminho
 * que leva de c até a última célula da lista.
 * 
 * Escreva uma função que calcule a altura de uma dada célula.
 * 
 * @author Rodrigo Andrade
 * */

#include <stdlib.h>

struct NodeList
{
    int content;
    struct NodeList *next;
};

typedef struct NodeList Node;

/**
 * Funcao iterativa para saber a altura de um dado elemento na lista.
 * 
 * @param node Node
 * @return the height of gived node.
 * */
int height(Node *node)
{
    int count = 0;
    Node *temp = node;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/**
 * Funcao recursiva para saber a altura de um dado elemento na lista.
 * 
 * @param node Node
 * @return the height of gived node.
 * */
int rheight(Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + rheight(node->next);
}
