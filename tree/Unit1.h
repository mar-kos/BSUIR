//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TStringGrid *StringGrid1;
	TTreeView *TreeView1;
	TButton *Button2;
	TEdit *Edit1;
	TButton *Button3;
	TButton *Button4;
	TLabel *Label1;
	TLabel *Label2;
	TMemo *Memo1;
	TLabel *Label3;
	TButton *Button6;
	TButton *Button1;
	TButton *Button5;
	TButton *Button7;
	TLabel *Label4;
	TEdit *Edit2;
	TEdit *Edit3;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
