/**
 * Invente um jeito de remover uma célula de uma lista encadeada sem cabeça. 
 * (Será preciso tomar algumas decisões de projeto antes de começar a programar.) 
 * 
 * @author Rodrigo Andrade
 * */

#include <stdlib.h>

#define DEFAULT_VALUE 0

struct NodeList
{
    int content;
    struct NodeList *next;
};

typedef struct NodeList Node;

Node *newNode();
Node *addBeginList(Node *head, int element);
Node *search(int element);
void remove(Node *node);

/**
 * Cria a lista.
 * @return Node - espaco alocado para manter a lista.
 * */
Node *newNode()
{
    Node *node = (Node *)malloc(sizeof(struct NodeList));

    if (node != NULL)
    {
        node->content = DEFAULT_VALUE;
        node->next = NULL;
    }

    return node;
}

/**
 * Adiciona um elemento no inicio da lista.
 * 
 * @param head Node
 * @param element int
 * @return Node head
 * */
Node *addBeginList(Node *list, int element)
{
    Node *node = newNode();
    node->content = element;

    if (list == NULL)
        list = node;
    else
    {
        node->next = list->next;
        list->next = node;
    }

    return list;
}

/**
 * Busca um elemeneto em determinada lista.
 * 
 * @param head Node
 * @param element int
 * 
 * @return node
 * */
Node *search(Node *list, int element)
{
    Node *temp = list;

    while (temp != NULL && temp->content != element)
        temp = temp->next;

    if (temp != NULL && temp->content == element)
        return temp;

    return NULL;
}

/**
 * Remove um elemento da lista.
 * @param list Node
 * @param node Node
 * */
void remove(Node *list, Node *node)
{
    Node *prev = NULL;
    Node *temp = list;

    while(temp != node) {
        prev = temp;
        temp = temp->next;
    }

    // Remove no incio da lista
    if(prev == NULL) {

    } else { // Remove no meio ou fim

    }
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
