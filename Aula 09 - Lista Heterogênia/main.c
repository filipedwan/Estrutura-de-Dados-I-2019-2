#include<stdio.h>
#include<stdlib.h>
#include"generic_linked_list.h"

int main() {
    GenericList *L =  create_list();
    Node *c = create_circle(2.0);
    Node *t = create_triangle(2.0, 3.0);
    Node *r = create_rectangle(3.0, 4.0);

    list_insert_begin(L, c);
    list_insert_end(L, t);
    list_insert_end(L, r);

    list_print(L);

    list_destroy(L);


   /*
    Node *c = create_circle(2.0);
    Circle *c1 = (Circle*) c->info;
    printf("%.2f\n\n", c1->radio*c1->radio);
*/

    return 0;
}