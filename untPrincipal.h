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
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TGroupBox *GroupBox1;
	TStatusBar *StatusBar1;
	TGroupBox *GroupBox3;
    TEdit *edtPathname;
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
	TOpenDialog *OpenDialog1;
	TButton *Button1;
	TPopupMenu *PopupMenuGrid;
	TMenuItem *Criar1;
	TMenuItem *Alterar1;
	TMenuItem *Deletar1;
	TPopupMenu *PopupTreeView;
	TMenuItem *Criardiretorio1;
	TMenuItem *Criararquivo1;
	TButton *Button2;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Autores1Click(TObject *Sender);
	void __fastcall TreeView2MouseLeave(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall StringGrid1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Criar1Click(TObject *Sender);
	void __fastcall TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y);
	void __fastcall Button2Click(TObject *Sender);

	void __fastcall Criardiretorio1Click(TObject *Sender);
	void __fastcall criarTree();
	void __fastcall exibirNode(TTreeNode *node, int count);
	void __fastcall limparChar(char *p, int tam);
	void __fastcall GerarNodesTreeView();
	void __fastcall ExibirNodesTreeView();
	void __fastcall GerarPathNodesTreeView(UnicodeString nomeDiretorio);
	void __fastcall GravarPathNoArquivo(UnicodeString path);

private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
