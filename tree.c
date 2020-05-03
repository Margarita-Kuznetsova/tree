#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>


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
	struct Node * tree = NULL;
	tree = tree_add(tree, 7);
	tree = tree_add(tree, 3);
	tree = tree_add(tree, 2);
	tree = tree_add(tree, 1);
	tree = tree_add(tree, 9);
	tree = tree_add(tree, 5);
	tree = tree_add(tree, 4);
	tree = tree_add(tree, 6);
	tree = tree_add(tree, 8);
	tree_print(tree); // напечатает 1 2 3 4 5 6 7 8 9
	
	printf("\n");
	return 0;
}


struct Node * tree_add (struct Node * tree, Data x) {
	if (tree == NULL) {                                  // Если дерева нет, то формируем корень
		struct Node * a = malloc(sizeof(struct Node));   // память под узел
		a->val = x;                                      // поле данных
		a->left = a->right = NULL;                       // ветви инициализируем пустотой
		return a;
	}
	if (x < tree->val)                                   // условие добавление левого потомка
		tree->left = tree_add(tree->left, x);
	else if (x > tree->val)
		tree->right = tree_add(tree->right, x);          // условие добавление правого потомка
	return tree;
}


void tree_print (struct Node * tree) {
	if (tree == NULL)                           //Пока не встретится пустой узел
		return;
	tree_print(tree->left);                     //Рекурсивная функция для левого поддерева
	printf("%d ", tree->val);                   //Отображаем корень дерева
	tree_print(tree->right);                    //Рекурсивная функция для правого поддерева
}


void tree_destroy (struct Node * tree) {
	if (tree == NULL)
		return;
	tree_destroy(tree->left);
	tree_destroy(tree->right);
	free(tree);
}

