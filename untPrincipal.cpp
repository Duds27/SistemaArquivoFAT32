//---------------------------------------------------------------------------

#include <vcl.h>
#include <windows.h>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <stdio.h>
#include <iostream>
#pragma hdrstop

#include "untPrincipal.h"
#include "untAutores.h"
#include "untNomeDiretorio.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
#define PATH_MAX 256

//variáveis globais
map<int, UnicodeString> MAP_QTD_NIVEL;
map<int, TTreeNode*> MAP_NODE;
map<int, UnicodeString> MAP_FILE;

#define ROOT "root\\"


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



void __fastcall TForm1::TreeView2MouseLeave(TObject *Sender)
{
	ShowMessage("SAINDO");

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
	/*char result[PATH_MAX];
	UnicodeString exeFile = Application->ExeName;

	UnicodeString path = ExtractFilePath(exeFile) + "root";
	OpenDialog1->InitialDir = path;

	ShowMessage(path);
	OpenDialog1->Execute();    */

	criarTree();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::criarTree()
{
	TTreeNode *World, *Continent, *root;

	//my root node
//	root = TreeView1->Items->Add(NULL, "root");


	// The root node
	TreeView1->Items->Add(NULL, "World");
	World = TreeView1->Items->Item[0];

	// First child of the root
	TreeView1->Items->AddChild(World, "Africa");
	Continent = TreeView1->Items->Item[1];

	// Children of first node
	TreeView1->Items->AddChild(Continent, "Botswana");
	TreeView1->Items->AddChild(Continent, "Benin");

	// Second child of the root
	TreeView1->Items->AddChild(World, "Europe");
	Continent = TreeView1->Items->Item[4];

	// Children of second node
	TreeView1->Items->AddChild(Continent, "Belgium");
	TreeView1->Items->AddChild(Continent, "Denmark");
	TreeView1->Items->AddChild(Continent, "Poland");

	// Third child of the root
	TreeView1->Items->AddChild(World, "America");
	Continent = TreeView1->Items->Item[8];

	// Children of the third node
	TreeView1->Items->AddChild(Continent, "Panama");
	TreeView1->Items->AddChild(Continent->Item[0],"TESTE1");
	TreeView1->Items->AddChild(Continent->Item[0]->Item[0],"HUSHAUHSUAH");
	TreeView1->Items->AddChild(Continent->Item[0],"TESTE2");
	TreeView1->Items->AddChild(Continent, "Colombia");

	// Fourth child of the root
	TreeView1->Items->AddChild(World, "Asia");
	Continent = TreeView1->Items->Item[14];

	TreeView1->Items->AddChild(Continent, "Turkey");
	TreeView1->Items->AddChild(Continent, "Bangladesh");

	//ShowMessage(TreeView1->GetNodeAt(0,1)->Text);
	TTreeNode *parent = TreeView1->Items->GetFirstNode();
	TTreeNode *child;
	TTreeNode *nephew;

	ShowMessage("First Node = " + parent->Text);

	ShowMessage("TreeView's count = " + IntToStr(TreeView1->Items->Count));
	ShowMessage("Root's count = " + IntToStr(parent->Count));
	/*for (int i = 0; i < parent->Count; i++) {

		child = parent->Item[i];
		for (int j = 0; j < child->Count; j++) {

			if (child->HasChildren) {
				nephew = child->Item[j];
				ShowMessage("Node: " + parent->Item[i]->Text + " Child = " + child->Item[j]->Text);
				for (int k = 0; k < nephew->Count; k++) {
					ShowMessage("Node: " + child->Item[j]->Text + " Nephew = " + nephew->Item[k]->Text);
				}
			}
			else
				ShowMessage("Node: " + parent->Item[i]->Text + " Child = " + child->Item[j]->Text);
		}
	}       */

	ShowMessage("Iniciando a recursiva...");
	exibirNode(parent, parent->Count);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::exibirNode(TTreeNode *node, int count)
{
	stack<TTreeNode*> stackNode;
	queue<TTreeNode*> queueNode;


	for (int i = 0; i < TreeView1->Items->Count; i++) {
		if (TreeView1->Items->Item[i]->HasChildren) {
			stackNode.push(TreeView1->Items->Item[i]);
			queueNode.push(TreeView1->Items->Item[i]);
			//MAP_NODE.insert (pair<int,TTreeNode*>(i, TreeView1->Items->Item[i]));
		}
	}

   //	LerNodesTreeView();

	ShowMessage("Pilha...");
	while (!stackNode.empty()) {
		TTreeNode *aux = stackNode.top();
		ShowMessage("Node = " + aux->Text);

		for (int i = 0; i < aux->Count; i++) {
			ShowMessage("Folha = " + aux->Item[i]->Text);
		}

		stackNode.pop();
	}


	ShowMessage("Fila...");
	while (!queueNode.empty()) {
		TTreeNode *aux = queueNode.front();
		ShowMessage("Node = " + aux->Text);

		for (int i = 0; i < aux->Count; i++) {
			ShowMessage("Folha = " + aux->Item[i]->Text);
		}

		queueNode.pop();
	}

}

//---------------------------------------------------------------------------
void __fastcall TForm1::limparChar(char *p, int tam)
{
	for (int i = 0; i < tam; i++) {
		*(p+i) = '\0';
	}
}

//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	TTreeNode *root;
	UnicodeString uni, pathCompleto;
	char path[PATH_MAX];
	char *dir, *file, *aux;
	FILE *fDirs;

	//Exibindo o Path Raiz
	edtPathname->Text = "root";

		  //criarTree();

	//my root node e lendo arquivo de diretorio
	if (fopen ("diretorios.txt", "r") == NULL) {
	   root = TreeView1->Items->Add(NULL, "root");
	   fDirs = fopen("diretorios.txt", "w");
	   fputs ("root\\\n", fDirs);
	   fclose ( fDirs);
	}
	else {
		 /* TODO: ler arquivo de source Tree */
		 fDirs = fopen ("diretorios.txt", "r");
		 if ( fDirs != NULL ) {
			limparChar(path, PATH_MAX);
			while (fgets (path, PATH_MAX, fDirs) != NULL ) {

				int cont = 0;
				pathCompleto = "";

				//O primeiro path sempre será o root
				if ( strcmp (path, "root\\\n") == 0 ) {
					TreeView1->Items->Add(NULL, "root");
					root = TreeView1->Items->Item[0];
					MAP_QTD_NIVEL.insert (pair<int,UnicodeString>(cont, "root"));
				}
				else {

					dir = strtok (path, "\\");
					do {
						if ( dir == NULL) break;

						aux = strstr (dir,".txt");
						if (aux != NULL) {
							ShowMessage(" path completo = " + pathCompleto);
						}
						else {
							ShowMessage (dir);
							MAP_QTD_NIVEL.insert (pair<int,UnicodeString>(cont, dir));
							pathCompleto += dir;
							pathCompleto += "\\";
							cont++;
						}

						dir = strtok (NULL, "\\\n");
					} while (dir != NULL);
				}


			}
		 }
	}

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1MouseDown(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, int X, int Y)
{
	//Simula o evento do botão direito
	if ( Button == mbRight ) {
		//StringGrid1->PopupMenu = mnuContext;
		StringGrid1->PopupMenu = PopupMenuGrid;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Criar1Click(TObject *Sender)
{
	ShowMessage("Delete");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::TreeView1MouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	//Simula o evento do botão direito
	if ( Button == mbRight ) {
		TreeView1->PopupMenu = PopupTreeView;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Criardiretorio1Click(TObject *Sender)
{
	FILE *tmp;
	char nomeArquivo[PATH_MAX];

	ShowMessage("Estou criando diretório...");
	ShowMessage("Absolute Index = " + IntToStr(TreeView1->Selected->AbsoluteIndex));

	frmNomeDiretorio->ShowModal();

	tmp = fopen ("nomeTemp.txt", "r");

	if ( tmp != NULL) {
		limparChar (nomeArquivo, PATH_MAX);
		if ( fgets (nomeArquivo, PATH_MAX , tmp) != NULL) {
			int index = TreeView1->Selected->AbsoluteIndex;
			TreeView1->Items->AddChild(TreeView1->Items->Item[index], nomeArquivo);
			GerarNodesTreeView();
			GerarPathNodesTreeView(nomeArquivo);
		}
	}

	fclose (tmp);

	if( remove( "nomeTemp.txt" ) != 0 )
		ShowMessage("Erro ao deletar arquivo temporário.");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::GerarNodesTreeView()
{
	for (int i = 0; i < TreeView1->Items->Count; i++) {
		if (TreeView1->Items->Item[i]->HasChildren) {
			MAP_NODE.insert (pair<int,TTreeNode*>(i, TreeView1->Items->Item[i]));
		}
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ExibirNodesTreeView()
{
	UnicodeString key, value;
	map<int, TTreeNode*>::iterator it;
	for (it = MAP_NODE.begin(); it != MAP_NODE.end(); ++it) {
		int k = it->first;
		key = IntToStr(k);
		value = it->second->Text;
		ShowMessage ("Key = " + key + "\nValue = " + value);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::GerarPathNodesTreeView(UnicodeString nomeDiretorio)
{
	stack<UnicodeString> path;
	TTreeNode *aux = TreeView1->Selected;
	UnicodeString name = "";
	path.push(nomeDiretorio);
	path.push(aux->Text + "\\");

	aux = aux->GetPrev();
	while (aux->HasChildren) {
		path.push(aux->Text + "\\");
		aux = aux->GetPrev();
	}
	path.push(ROOT);

	name = "";
	while (!path.empty()) {
		name += path.top();
		path.pop();
	}


	ShowMessage("Path Completooo = " + name);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	GerarNodesTreeView();
	ExibirNodesTreeView();
}
//---------------------------------------------------------------------------

