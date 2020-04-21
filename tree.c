#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define AAA
#ifdef AAA

typedef int Data;

struct Node {
	Data val;            // данные в узле
	struct Node * left;  // левый ребенок
	struct Node * right; // правый ребенок
};

struct Node * tree_add(struct Node * tree, Data x);

void tree_print(struct Node * tree);

void tree_destroy (struct Node * tree);

int main ()
{
	struct Node * tree=NULL;
	tree = tree_add(tree, 7);
	tree = tree_add(tree, 3);
	tree = tree_add(tree, 2);
	tree = tree_add(tree, 1);
	tree = tree_add(tree, 9);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 7);
	tree = tree_add(tree, 6);
	tree = tree_add(tree, 8);
	tree_print(tree); // напечатает 1 2 3  5 6 7 8 9
	
	tree_destroy(tree);
	
	//free(tree);
	printf("\n");
	return 0;
}

#endif

struct Node * tree_add(struct Node * tree, Data x) {
	if (tree == NULL) {               // Если дерева нет, то формируем корень
		tree = (struct Node *)malloc(sizeof(struct Node));              // память под узел
		tree->val = x;                // поле данных
		tree->left =  NULL;
		tree->right = NULL;           // ветви инициализируем пустотой
	}
	else
		if (x < tree->val)            // условие добавление левого потомка
			tree->left = tree_add(tree->left, x);
		else                          // условие добавление правого потомка
			tree->right = tree_add(tree->right, x);
	return(tree);
}

void tree_print(struct Node * tree) {
	if (tree != NULL) {             //Пока не встретится пустой узел
		tree_print(tree->left);     //Рекурсивная функция для левого поддерева
		printf("%d ", tree->val);     //Отображаем корень дерева
		tree_print(tree->right);   //Рекурсивная функция для правого поддерева
	}
	else
		return;
}

void tree_destroy(struct Node * tree) {
	if (tree != NULL) {
		tree_destroy(tree->left);
		tree_destroy(tree->right);
		free(tree);
	}
}
