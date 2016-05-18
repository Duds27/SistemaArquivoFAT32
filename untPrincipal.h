//---------------------------------------------------------------------------

#ifndef untPrincipalH
#define untPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox3;
	TEdit *Edit1;
	TTreeView *TreeView1;
	TMainMenu *MainMenu1;
	TMenuItem *Arquivo1;
	TMenuItem *Editar1;
	TMenuItem *Exibir1;
	TMenuItem *Ferramentas1;
	TStringGrid *StringGrid1;
	TTimer *Timer1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *Sobre1;
	TMenuItem *Autores1;
	TMenuItem *Verso1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Autores1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
