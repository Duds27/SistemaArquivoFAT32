//---------------------------------------------------------------------------

#ifndef untNomeDiretorioH
#define untNomeDiretorioH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TfrmNomeDiretorio : public TForm
{
__published:	// IDE-managed Components
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *lblTamanhoMaximo;
	TLabel *Label3;
	TLabel *lblTamanhoRestante;
	TTimer *Timer1;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TfrmNomeDiretorio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmNomeDiretorio *frmNomeDiretorio;
//---------------------------------------------------------------------------
#endif
