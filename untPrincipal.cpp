//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "untPrincipal.h"
#include "untAutores.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	StatusBar1->Panels->Items[0]->Text = Date();
	StatusBar1->Panels->Items[2]->Text = Time();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Autores1Click(TObject *Sender)
{
	frmAutores->ShowModal();
}
//---------------------------------------------------------------------------

