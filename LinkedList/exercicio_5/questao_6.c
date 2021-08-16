/**
 * Escreva uma função que troque de posição duas células de uma mesma lista encadeada.
 * @author Rodrigo Andrade
 * */
#include <stdlib.h>

struct NodeList
{
    int content;
    struct NodeList *next;
};

typedef struct NodeList Node;

Node *getPrev(Node *head, Node *node);
void trade(Node *head, Node *node1, Node *node2);

/**
 * Troca os elementos. Node2 deve ser um elemento que esta a frente do elemento node1.
 * @param head Node
 * @param node1 Node
 * @param node2 Node
 * */
void trade(Node *head, Node *node1, Node *node2)
{
    // É necessário saber qual é o elemento anterior
    // de cada nó que sera trocado na lista, para poder manter a sequência.
    Node *prev1 = getPrev(head, node1);
    Node *prev2 = getPrev(head, node2);

    // Casos possiveis:

    //1) elementos em sequencia: nesse caso, se node1 e node2 forem sequencia, o prev de node2
    // sera igual a node1. Entao somente o prev de node1 que vai apontar para o node2.
    if (prev2 == node1)
    {
        // Troca os ponteiros
        node1->next = node2->next;
        node2->next = node1;

        // 1.1) Sequencia e prev de node1 igual a nulo, indicando inicio da lista
        if (prev1 == NULL)
            head = node2;
        else // 1.2) Caso de sequencia comum.
            prev1->next = node2;

        return;
    }

    
    Node *temp = node1;
    node1->next = node2->next;

    prev2->next = node1;
    node2->next = temp->next;
    //2) prev1 null: nesse caso, o prev1 que faz referencia ao node1 poder vir a ser nulo,
    // indicando que node1 é o primeiro elemento da lista.
    if (prev1 == NULL)
        head = node2;
    else
        prev1->next = node2;
}

/**
 * Retorna o nó anterior de um dado nó.
 * 
 * @param head Node
 * @param node Node
 * 
 * @return prev* Node
 * */
Node *getPrev(Node *head, Node *node)
{
    Node *prev = head;
    while (prev->next != node)
        prev = prev->next;

    if (prev == head)
        return NULL;

    return prev;
}
