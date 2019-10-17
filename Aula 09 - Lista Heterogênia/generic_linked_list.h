#ifndef _GENERIC_LINKED_LIST_H_
#define _GENERIC_LINKED_LIST_H_

#define RET 0
#define TRI 1
#define CIR 2

#define PI 3.14159265

typedef struct rectangle {
	float height;
	float width;
} Rectangle;

typedef struct triangle {
	float height;
	float base;
} Triangle;

typedef struct circle {
	float radio;
} Circle;

typedef struct node {
	int type;
	void* info; //void* = a generic pointer OR a pointer to any data type
	struct node* next;
}Node;

typedef struct generictlist {
    Node *head;
    Node *last;
    int len;
}GenericList;


GenericList* create_list();
int is_empty(GenericList *L);
void list_destroy(GenericList *L);
void list_insert_begin(GenericList *L, Node *new_form);
void list_insert_end(GenericList *L, Node *new_form);
void list_print(GenericList *L);
float list_area(GenericList *L);
//TODO
//GenericList search(GenericList L, Node *new_form);
//TODO
//GenericList list_remove(GenericList L, Node *new_form);
Node* create_rectangle(float height, float width);
Node* create_triangle(float height, float base);
Node* create_circle(float radio);
float rectangle_area(Rectangle *r);
float triangle_area(Triangle *r);
float circle_area(Circle *r);

#endif