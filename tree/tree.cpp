// ---------------------------------------------------------------------------

#pragma hdrstop

#include "tree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

PTNode TTree::add_node(PTNode Node, int k, String n) {
	if (!Node)
		return new TNode(k, n);
	if (k < Node->key)
		Node->Left = add_node(Node->Left, k, n);
	if (k > Node->key)
		Node->Right = add_node(Node->Right, k, n);
	return Node;
}

void TTree::delete_tree(PTNode Node) {
	if (Node) {
		delete_tree(Node->Left);
		delete_tree(Node->Right);
		delete Node;
	}
}

void TTree::print_pr(PTNode Node, TStringList * List) {
	if (Node) {
		List->Add(Node->key);
		print_pr(Node->Left, List);
		print_pr(Node->Right, List);
	}
}

void TTree::print_ob(PTNode Node, TStringList * List) {
	if (Node) {
		print_ob(Node->Left, List);
		print_ob(Node->Right, List);
		List->Add(Node->key);
	}
}

void TTree::print_sim(PTNode Node, TStringList * List) {
	if (Node) {
		print_sim(Node->Left, List);
		List->Add(Node->key);
		print_sim(Node->Right, List);
	}
}

void TTree::show(PTNode Node, TTreeView * TreeView, TTreeNode * TreeNode) {
	if (!Node)
		return;
	TreeNode = TreeView->Items->AddChild(TreeNode, Node->key);
	show(Node->Left, TreeView, TreeNode);
	show(Node->Right, TreeView, TreeNode);
}

PTNode TTree::search_elem(PTNode Node, int k) {
	if (!Node || k == Node->key)
		return Node;
	if (k < Node->key)
		return search_elem(Node->Left, k);
	else
		return search_elem(Node->Right, k);
}

PTNode TTree::delete_elem(PTNode Node, int k) {
	if (!Node)
		return Node;
	if (k < Node->key)
		Node->Left = delete_elem(Node->Left, k);
	else if (k > Node->key)
		Node->Right = delete_elem(Node->Right, k);
	else if (Node->Left && Node->Right) {
		Node->key = (min(Node->Right))->key;
		Node->Right = delete_elem(Node->Right, Node->key);
	}
	else {
		if (Node->Left)
			Node = Node->Left;
		else
			Node = Node->Right;
	}
	return Node;
}

TStringList* TTree::delete_max_left_elem() {
	TStringList* List = new TStringList;
	PTNode M = max(Root->Left);
	List->Add("Максимальный ключ в левой ветке: " + String(M->key) + ".");
	List->Add("Удаленный элемент:");
	List->Add(M->name + " +" + String(M->key));
	delete_elem(Root, M->key);
	return List;
}

PTNode TTree::min(PTNode Node) {
	if (!Node->Left)
		return Node;
	return min(Node->Left);
}

PTNode TTree::max(PTNode Node) {
	if (!Node->Right)
		return Node;
	return max(Node->Right);
}
