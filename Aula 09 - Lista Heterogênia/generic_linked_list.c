#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"generic_linked_list.h"

GenericList* create_list() {
    GenericList *L = (GenericList*) malloc(sizeof(GenericList));
    L->head = L->last = NULL;
    L->len = 0;
    return L;
}

int is_empty(GenericList *L) {
    return (L->len == 0);
}

void list_destroy(GenericList *L) {
	Node *p = L->head;
    Node *aux;
	while (p != NULL) {
		aux = p;
        p = p->next;
		free(aux);
	}
	free(L);
}

void list_insert_begin(GenericList *L, Node *new_form) {
    if (is_empty(L))
        L->last = new_form;
    new_form->next = L->head;
    L->head = new_form;
    L->len++;
}

void list_insert_end(GenericList *L, Node *new_form) {
    new_form->next = NULL;//as it is a queue, the node is always inserted in the end.
    if (is_empty(L))
        L->head = new_form;
    else
       L->last->next = new_form;
    L->last = new_form;//update the end with the new node
    L->len++;
}

void form(Node* e, char* str) {
	switch (e->type) {
		case RET:
			 strcpy(str, "RETANGULO");
		     break;
		case TRI:
			 strcpy(str, "TRIANGULO");
		     break;
		case CIR:
			 strcpy(str, "CIRCULO");
		     break;
    }
}

float area(Node* e) {
	float a;
	switch (e->type) {
		case RET:
			a = rectangle_area(e->info);
		    break;
		case TRI:
			a = triangle_area(e->info);
		    break;
		case CIR:
			a = circle_area(e->info);
		    break;
    }
	return a;
}

void list_print(GenericList *L) {
	char *str = (char* ) malloc(20*sizeof(char));
	for (Node *p = L->head; p != NULL; p = p->next) {		
		form(p, str);
		printf("%s (Area = %.3f)--> ", str, area(p));
	}
	free(str);
	printf("\n");
}

float list_area(GenericList *L) {
	float area_total = 0;
	for (Node *p = L->head; p != NULL; p = p->next) {
		area_total = area_total + area(p);
	}
	return area_total;
}

Node* create_rectangle(float height, float width) {    
    Node* p = (Node*) malloc(sizeof(Node));
	Rectangle* r = (Rectangle*) malloc(sizeof(Rectangle));
	r->height = height;
	r->width = width;
	p->type = RET;
	p->info = r;
	p->next = NULL;
	return p;
}

Node* create_triangle(float height, float base) {
    Node* p = (Node*) malloc(sizeof(Node));
	Triangle* t = (Triangle*) malloc(sizeof(Triangle));
	t->height = height;
	t->base = base;
	p->type = TRI;
	p->info = t;
	p->next = NULL;
	return p;
}

Node* create_circle(float radio) {
    Node* p = (Node*) malloc(sizeof(Node));
	Circle* c = (Circle*) malloc(sizeof(Circle));
	c->radio = radio;
	p->type = CIR;
	p->info = c;
	p->next = NULL;
	return p;
}

float rectangle_area(Rectangle *r) {
    return (r->height*r->width);
}

float triangle_area(Triangle *t) {
    return (t->base*t->height)/2;
}

float circle_area(Circle *c) {
    return PI*(c->radio*c->radio);
}