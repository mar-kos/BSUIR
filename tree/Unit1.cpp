// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "tree.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int c = 10;
TTree *Tree = new TTree;
TForm1 *Form1;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
	TStringList *List = new TStringList();
	List->LoadFromFile("data.txt");
	for (int i = 0; i < c; i++) {
		String s = List->Strings[i];
		String country = s.SubString(0, s.Pos(" ") - 1);
		String code = s.SubString(s.Pos("+"), s.Length());
		StringGrid1->Cells[0][i] = country;
		StringGrid1->Cells[1][i] = code;
		Tree->Root = Tree->add_node(Tree->Root, code.ToInt(), country);
	}
	Tree->show(Tree->Root, TreeView1, TreeView1->TopItem);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) {
	Memo1->Clear();
	Memo1->Lines = Tree->delete_max_left_elem();
	TreeView1->Items->Clear();
	Tree->show(Tree->Root, TreeView1, TreeView1->TopItem);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender) {
	if (Edit2->Text.IsEmpty()) {
		ShowMessage("Введите название страны.");
		return;
	}
	if (Edit3->Text.IsEmpty()) {
		ShowMessage("Введите целочисленный ключ.");
		return;
	}
	int k;
	try {
		k = Edit3->Text.ToInt();
	}
	catch (...) {
		ShowMessage("Введите целочисленный ключ.");
		return;
	}
	Tree->Root = Tree->add_node(Tree->Root, k, Edit2->Text);
	TreeView1->Items->Clear();
	Tree->show(Tree->Root, TreeView1, TreeView1->TopItem);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) {
	int k;
	try {
		k = Edit1->Text.ToInt();
	}
	catch (...) {
		ShowMessage("Введите целочисленный ключ.");
		return;
	}
	PTNode Searched = Tree->search_elem(Tree->Root, k);
	Memo1->Clear();
	if (Searched) {
		Memo1->Lines->Add("Найденный элемент:");
		Memo1->Lines->Add(Searched->name + " +" + String(Searched->key));
	}
	else
		Memo1->Lines->Add("Элементы с ключом " + String(k) + " не найдены.");
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender) {
	int k;
	try {
		k = Edit1->Text.ToInt();
	}
	catch (...) {
		ShowMessage("Введите целочисленный ключ.");
		return;
	}
	Tree->delete_elem(Tree->Root, k);
	Memo1->Clear();
	Memo1->Lines->Add("Данные в TreeView1 обновлены.");
	TreeView1->Items->Clear();
	Tree->show(Tree->Root, TreeView1, TreeView1->TopItem);
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender) {
	TStringList *List = new TStringList();
	Tree->print_pr(Tree->Root, List);
	Memo1->Clear();
	Memo1->Lines = List;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender) {
	TStringList *List = new TStringList();
	Tree->print_sim(Tree->Root, List);
	Memo1->Clear();
	Memo1->Lines = List;
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender) {
	TStringList *List = new TStringList();
	Tree->print_ob(Tree->Root, List);
	Memo1->Clear();
	Memo1->Lines = List;
}
