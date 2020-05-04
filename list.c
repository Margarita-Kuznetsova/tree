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

void list_print (struct Node * list);



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
	
	list_insert_before(a, &x[0]);
	list_print(a);
	list_insert(a, &x[9]);
	list_print(a);
	list_insert(&x[6], &x[5]);
	list_print(a);
	

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


void list_print(struct Node * list) {
	for(struct Node * p  = list -> next; p != list; p = p -> next)
		printf("%d ", p -> data);
	printf("\n");
}
