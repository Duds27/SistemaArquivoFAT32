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
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

using namespace std;
#define PATH_MAX 256

//variáveis globais
map<int, UnicodeString> MAP_QTD_NIVEL;
map<int, UnicodeString> MAP_FILE;


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

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//	TreeView2->Items->Add(TreeView2, "Facens");
ShowMessage("skahsagsj");
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
			MAP_QTD_NIVEL.insert (pair<int,UnicodeString>(i, TreeView1->Items->Item[i]->Text));
			ShowMessage("ToString = " + TreeView1->Items->Item[i]->ToString());
			//ShowMessage(TreeView1->Items->Item[i]->Text);
		}
	}

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
	TPopupMenu *mnuContext = new TPopupMenu(this);
	TMenuItem *mnuFileNew = new TMenuItem(this);
	TMenuItem *mnuFileOpen = new TMenuItem(this);

	mnuFileNew->Caption = L"New";
	mnuContext->Items->Add(mnuFileNew);
	mnuFileOpen->Caption = L"Open";
	mnuContext->Items->Add(mnuFileOpen);

	//Simula o evento do botão direito
	if ( Button == mbRight ) {
		//StringGrid1->PopupMenu = mnuContext;
		StringGrid1->PopupMenu = PopupMenuGrid;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mnuFileNewClick(TObject *Sender)
{
	ShowMessage("New");
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

		ShowMessage(TreeView1->Selected->Index);
		ShowMessage(TreeView1->Selected->GetPrev()->Text);


	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
	map<UnicodeString,UnicodeString> mymap;
	set<int> myset;
	set<int>::iterator it;
	pair<set<int>::iterator,bool> ret;

	mymap.insert (pair<UnicodeString,UnicodeString>("1", "Correa"));
	mymap.insert (pair<UnicodeString,UnicodeString>("0", "Eduardo"));
	mymap.insert (pair<UnicodeString,UnicodeString>("3", "Encarnação"));
	mymap.insert (pair<UnicodeString,UnicodeString>("0", "Eduardo"));


	map<UnicodeString,UnicodeString>::iterator iterator = mymap.begin();
	for (iterator = mymap.begin(); iterator != mymap.end(); ++iterator) {
		ShowMessage ("Key = " + iterator->first + " Value = " + iterator->second );
	}


  // set some initial values:
  for (int i=1; i<=5; ++i) myset.insert(i*10);    // set: 10 20 30 40 50

  ret = myset.insert(20);               // no new element inserted

  if (ret.second==false) it=ret.first;  // "it" now points to element 20

  myset.insert (it,25);                 // max efficiency inserting
  myset.insert (it,24);                 // max efficiency inserting
  myset.insert (it,26);                 // no max efficiency inserting

  int myints[]= {5,10,15};              // 10 already in set, not inserted
  myset.insert (myints,myints+3);

  ShowMessage("myset contains:");
  for (it=myset.begin(); it!=myset.end(); ++it)
	cout << ' ' << *it;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	map<int, UnicodeString>::iterator it;
	for (it = MAP_QTD_NIVEL.begin(); it != MAP_QTD_NIVEL.end(); ++it) {
		int k = it->first;
		ShowMessage ("Key = " + IntToStr(k));
		ShowMessage ("Value = " + it->second);
	}
}
//---------------------------------------------------------------------------

