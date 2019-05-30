// ---------------------------------------------------------------------------

#ifndef treeH
#define treeH
#include <vcl.h>
// ---------------------------------------------------------------------------
#endif

// Класс для описания узла
class TNode {
public:
	TNode() {
	}

	TNode(int k, String n) : key(k), name(n) {
	}

	int key;
	String name;

	TNode* Left = NULL;
	TNode* Right = NULL;
};

typedef TNode *PTNode;

// Класс для описания дерева
class TTree {
public:
	TTree() : Root(NULL) {
	}

	~TTree() {
		delete_tree(Root);
	}

	PTNode Root;

	PTNode add_node(PTNode, int, String);
	// Прямой обход дерева
	void print_pr(PTNode, TStringList*);
	// Обратный обход дерева
	void print_ob(PTNode, TStringList*);
	// Симметричный обход дерева (для вывода ключей в порядке возрастания)
	void print_sim(PTNode, TStringList*);
	// Демонстрация структуры в компоненте TreeView1
	void show(PTNode, TTreeView*, TTreeNode*);
	// Поиск элемента по ключу
	PTNode search_elem(PTNode, int);
	// Удаление элемента по ключу
	PTNode delete_elem(PTNode, int);
	// Удаление элемента с максимальным ключом в левой ветке
	TStringList* delete_max_left_elem();

private:
	// Освобождение памяти
	void delete_tree(PTNode);
	// Поиск элемента с минимальным ключом
	PTNode min(PTNode);
	// Поиск элемента с максимальным ключом
	PTNode max(PTNode);
};
