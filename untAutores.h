//---------------------------------------------------------------------------

#ifndef untAutoresH
#define untAutoresH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TfrmAutores : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
private:	// User declarations
public:		// User declarations
	__fastcall TfrmAutores(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAutores *frmAutores;
//---------------------------------------------------------------------------
#endif
