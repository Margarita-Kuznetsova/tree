#include <stdio.h>
#include <stdlib.h>

typedef int Data;

struct Node {
	Data data;
	struct Node * next;
	struct Node * prev;
};

void list_init(struct Node * list);

int main()
{
	struct Node x[10];
	struct Node * a = malloc(sizeof(struct Node));
	struct Node * b = malloc(sizeof(struct Node));
	
	
	list_init(a);
	list_init(b);

	return 0;
}


void list_init(struct Node * list) {
	list -> next = list;
	list -> prev = list;
}
