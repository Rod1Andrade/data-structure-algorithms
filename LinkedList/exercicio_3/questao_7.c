/**
 * Ponto médio.  Escreva uma função que receba uma lista encadeada e devolva
 * o endereço de uma célula que esteja o mais próximo possível do meio da lista.
 * 
 * Faça isso sem contar explicitamente o número de células da lista.
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

Node *middlePoint(Node *head, Node *node);

int height(Node *node);
int rheight(Node *node);
int depth(Node *head, Node *node);
int rdepth(Node *head, Node *node);

/**
 * Devolva o endereço de uma célula que esteja o mais próximo possível do meio da lista.
 * @param head Node
 * @param node Node
 * @return Node who is the middle point of a list.
 * */
Node *middlePoint(Node *head, Node *node)
{
    Node *temp = node;
    while(rdepth(head, temp) < rheight(temp)) {
        temp = temp->next;
    }

    return temp;
}

/**
 * Funcao iterativa para saber a altura de um dado elemento na lista.
 * A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista.
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
 * A altura de uma célula c em uma lista encadeada é a distância entre c e o fim da lista.
 * @param node Node
 * @return the height of gived node.
 * */
int rheight(Node *node)
{
    if (node == NULL)
        return 0;
    return 1 + rheight(node->next);
}


/**
 * Calcula de forma iterativa a profundidade de um dado elemento da lista.
 * A profundidade de uma célula c em uma lista encadeada é o número de passos
 * do único caminho que vai da primeira célula da lista até c
 * @param head Node
 * @param node Node
 * @return int depth of give node
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
 * A profundidade de uma célula c em uma lista encadeada é o número de passos 
 * do único caminho que vai da primeira célula da lista até c.
 * 
 * [Importante] - Tomar cuidado para nao alterar o ponteiro da cabeca da lisata,
 * recomendo usar um valor temporario para fazer referencia ao primeiro elemento, 
 * semelhante a forma recursiva.
 * 
 * @param head Node
 * @param node Node
 * @return int depth of a give node
 * */
int rdepth(Node *head, Node *node)
{
    if (head == node)
        return 0;
    return 1 + rdepth(head->next, node);
}
