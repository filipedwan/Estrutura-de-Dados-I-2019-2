#include<stdio.h>
#include<stdlib.h>
#include"ordered_list.h"

int main() {
    List *L = create_list();
    list_insert(L, 30);
    list_insert(L, 20);
    list_insert(L, 50);
    list_insert(L, 10);
    list_insert(L, 60);



    list_print(L);
    
    list_destroy(L);
}