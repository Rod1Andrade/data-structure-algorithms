/**
 * Profundidade. A profundidade de uma célula c em uma lista encadeada é o número de
 * passos do único caminho que vai da primeira célula da lista até c.  
 * 
 * Escreva uma função que calcule a profundidade de uma dada célula
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
 * Calcula de forma iterativa a profundidade de um dado elemento da lista.
 * @param head Node
 * @param node Node
 * @return int profundidade
 * */
int depth(Node *head, Node *node)
{
    Node *temp = head;
    int count = 0;

    while (temp != node)
    {
        count++;
        temp = temp->next;
    }

    return count;
}

/**
 * Calcula de forma recursiva a profundidade de um dado elemento da lista.
 * 
 * [Importante] - Tomar cuidado para nao alterar o ponteiro da cabeca da lisata,
 * recomendo usar um valor temporario para fazer referencia ao primeiro elemento, 
 * semelhante a forma recursiva.
 * 
 * @param head Node
 * @param node Node
 * @return int profundidade
 * */
int rdepth(Node *head, Node *node)
{
    if (head == node)
        return 0;
    return 1 + rdepth(head->next, node);
}
