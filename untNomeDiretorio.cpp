//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "untNomeDiretorio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmNomeDiretorio *frmNomeDiretorio;
//---------------------------------------------------------------------------
__fastcall TfrmNomeDiretorio::TfrmNomeDiretorio(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmNomeDiretorio::Timer1Timer(TObject *Sender)
{
	int tam = StrToInt (lblTamanhoMaximo->Caption) - Edit1->Text.Length();
	while (tam > 0)
		lblTamanhoRestante->Caption = IntToStr (tam);

	if (tam == 0) {
		ShowMessage("Por favor, diminua o tamanho do nome do diretório.");
	}

}
//---------------------------------------------------------------------------
void __fastcall TfrmNomeDiretorio::Button1Click(TObject *Sender)
{
	FILE *tmp;
	char aux[256];

	for (int i = 0; i < 256; i++)
		*(aux+i) = '\0';

	tmp = fopen ("nomeTemp.txt", "w");

	if (tmp != NULL) {
		// first convert to AnsiString instead of Unicode.
		AnsiString ansiB(Edit1->Text);

		// allocate enough memory for your char array (and the null terminator)
		char* str = new char[ansiB.Length()+1];

		// copy the contents of the AnsiString into your char array
		strcpy(str, ansiB.c_str());

		fputs (str, tmp);
		// remember to delete your char array when done
		delete[] str;
	}
	fclose (tmp);
	frmNomeDiretorio->Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmNomeDiretorio::FormCreate(TObject *Sender)
{
	Edit1->Text = "";
}
//---------------------------------------------------------------------------

