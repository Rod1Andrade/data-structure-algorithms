# Questão 8

Alocação de células.  É uma boa ideia alocar as células de uma lista encadeada uma-a-uma?  

__Resposta__: Por a célula ser um elemento único que se encaixa no contexto da lista e faz
com que ela cresça dinamicamente, sim, é uma boa ideia aloca-los um a um e redirecionar os ponteiros para manter o fluxo esperado da lista. Mesmo que ao alocar elementos pequenos acaba-se alocando mais espaço do que o requerido, este fato ocorre porque a função ``malloc`` necessita de dados extras para operar perfeitamente com a função ``free``.

### Proposta de alternativa

```c
#define DEFAULT_VALUE = 0;

struct NodeList
{
    int content;
    struct NodeList *next;
};

typedef struct NodeList *Node;

/**
 * Cria a lista.
 * @return Node - espaco alocado para manter a lista.
 * */
Node *newNode()
{
    Node *node = (Node*) malloc(sizeof(struct NodeList));
    
    if(node != NULL) {
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
Node *addBeginList(Node *head, int element)
{
    if(head == NULL) return NULL;

    Node node = newNode();
    node->content = element;

    if(head->next == NULL)
        head->next = node;
    else {
        node->next = head->next->next;
        head->next = node;
    }

    return head;
}

//... funcoes para desalocar a memoria usada

```