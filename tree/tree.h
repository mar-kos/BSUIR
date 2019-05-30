// ---------------------------------------------------------------------------

#ifndef treeH
#define treeH
#include <vcl.h>
// ---------------------------------------------------------------------------
#endif

// ����� ��� �������� ����
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

// ����� ��� �������� ������
class TTree {
public:
	TTree() : Root(NULL) {
	}

	~TTree() {
		delete_tree(Root);
	}

	PTNode Root;

	PTNode add_node(PTNode, int, String);
	// ������ ����� ������
	void print_pr(PTNode, TStringList*);
	// �������� ����� ������
	void print_ob(PTNode, TStringList*);
	// ������������ ����� ������ (��� ������ ������ � ������� �����������)
	void print_sim(PTNode, TStringList*);
	// ������������ ��������� � ���������� TreeView1
	void show(PTNode, TTreeView*, TTreeNode*);
	// ����� �������� �� �����
	PTNode search_elem(PTNode, int);
	// �������� �������� �� �����
	PTNode delete_elem(PTNode, int);
	// �������� �������� � ������������ ������ � ����� �����
	TStringList* delete_max_left_elem();

private:
	// ������������ ������
	void delete_tree(PTNode);
	// ����� �������� � ����������� ������
	PTNode min(PTNode);
	// ����� �������� � ������������ ������
	PTNode max(PTNode);
};
