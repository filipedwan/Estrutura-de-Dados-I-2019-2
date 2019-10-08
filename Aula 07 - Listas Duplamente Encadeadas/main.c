#include<stdio.h>
#include<stdlib.h>
#include"doubly_linked_list.h"

int main(){
    DoublyList *L = create_list();

    list_insert_begin(L, 5);
    
    list_insert_end(L, 10);
    list_insert_end(L, 20);
    list_insert_end(L, 30);
    list_insert_end(L, 40);
    list_insert_end(L, 50);
    list_insert_end(L, 60);

    list_insert_begin(L, 2);

    printf("----BEFORE REMOVE ELEMENTS----\n");
    list_print(L);

    list_remove(L, 2);
    list_remove(L, 5);
    list_remove(L, 60);
    list_remove(L, 30);

    printf("----AFTER REMOVE ELEMENTS----\n");
    list_print(L);
    
    list_destroy(L);
    return 0;
}