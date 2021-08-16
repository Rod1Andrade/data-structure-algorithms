/**
 * Tamanho de célula.   Compile e execute o seguinte programa:
 *   int main (void) {
 *      printf ("sizeof (celula) = %d\n", 
 *      sizeof (celula));
 *      return EXIT_SUCCESS;
 *   }
 * @author Rodrigo Andrade
 * */

#include <stdio.h>
#include <stdlib.h>

struct NodeList
{
    int content;
    struct NodeList *next;
};

typedef struct NodeList Node;

int main(int argc, char const *argv[])
{
    printf("sizeof (celula) = %d\n", sizeof(Node));
    return EXIT_SUCCESS;
    return 0;
}
