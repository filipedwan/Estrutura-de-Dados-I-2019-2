#include<stdio.h>
#include<stdlib.h>
#include"lista.h"

int main() {
    List *L = create_list();
    list_insert(L, 20);
    list_insert(L, 30);
    list_insert(L, 40);
    list_remove(L, 30);
    list_remove(L, 10);

    list_print(L);

    Nodo *aux = search(L, 20);
    if (aux!=NULL)
        printf("Element found: %d\n", aux->info);
    

    list_destroy(L);
}