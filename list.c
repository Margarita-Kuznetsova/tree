#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
	Data data;
	struct Node * next;
	struct Node * prev;
};

void list_init(struct Node * list);

void list_insert(struct Node * list, struct Node * t);

void list_insert_before(struct Node * list, struct Node * t);

void list_remove(struct Node * t);

struct Node * list_push_front(struct Node * list, Data d);

struct Node * list_push_back(struct Node * list, Data d);

Data list_pop_front(struct Node * list);

Data list_pop_back(struct Node * list);

Data list_delete(struct Node * t);

void list_print (struct Node * list);

int list_is_empty(struct Node * list);

void list_clear(struct Node * list);




int main()
{
	struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));
	
	int i = 0;
	
	list_init(a);
	list_init(b);
	
	for(i = 0; i < 10; i++) {
		x[i].data = i;
		list_insert(a, &x[i]);
	}
	list_print(a);   // 9 8 7 6 5 4 3 2 1 0
	
	list_remove(&x[5]);
	list_print(a);
	list_remove(&x[0]);
	list_print(a);
	list_remove(&x[9]);
	list_print(a);
	
	
	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	
	
	while(!list_is_empty(a))
		list_remove(a->next);
		

	for(i = 0; i < 10; i++)
		list_push_back(a, i);
	list_print(a);
	
	
	for(i = 0; i < 10; i++)
		list_push_front(b, list_pop_back(a));
	list_print(b);
	

	for(i = 0; i < 10; i++) {
		list_push_front(a, i);
		list_pop_front(b);
	}
	list_print(a);
	

	for(i = 0; i < 10; i++)
		list_push_back(b, list_pop_front(a));
	list_print(b);
	
	
	list_clear(a);
	list_clear(b);

	return 0;
}


void list_init(struct Node * list) {
	list -> next = list;
	list -> prev = list;
}


void list_insert(struct Node * list, struct Node * t) {
	struct Node * q = list -> next;
	t -> prev = list;
	t -> next = q;
	list -> next = t;
	q -> prev = t;
}


void list_insert_before(struct Node * list, struct Node * t) {
	struct Node * p = list -> prev;
	list_insert(p, t);
}


void list_remove(struct Node * t) {
	struct Node * p = t -> prev;
	struct Node * q = t -> next;
	p -> next = q;
	q -> prev = p;
}


struct Node * list_push_front(struct Node * list, Data d) {
	struct Node * p = NULL;
	p = malloc(sizeof(struct Node));
	p -> data = d;
	list_insert(list, p);
	return p;
}


struct Node * list_push_back(struct Node * list, Data d) {
	struct Node * w = NULL;
	w = malloc(sizeof(struct Node));
	w -> data = d;
	list_insert_before(list, w);
	return w;
}


Data list_pop_front(struct Node * list) {
	return list_delete(list -> next);
}


Data list_pop_back(struct Node * list) {
	return list_delete(list -> prev);
}


Data list_delete(struct Node * t) {
	Data res = t -> data;
	list_remove(t);
	free(t);
	return res;
}


void list_print(struct Node * list) {
	for(struct Node * p  = list -> next; p != list; p = p -> next)
		printf("%d ", p -> data);
	printf("\n");
}


int list_is_empty(struct Node * list) {
	if (list -> prev == list && list -> next == list)
		return 1;
	else
		return 0;
}

void list_clear(struct Node * list) {
	while (!list_is_empty(list))
		list_pop_front(list);
}
