//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Namereno.h"
#include "Unit1.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LbSpeedButton"
#pragma resource "*.dfm"
TFormData *FormData;


//---------------------------------------------------------------------------
__fastcall TFormData::TFormData(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormData::LbSpeedButton2Click(TObject *Sender)
{
StringGrid1->RowCount = EditCount->Text.ToInt();


}
//---------------------------------------------------------------------------


void __fastcall TFormData::FormClose(TObject *Sender, TCloseAction &Action)
{
//Excel.OleFunction ("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFormData::LbSpeedButton3Click(TObject *Sender)
{
if (OpenDialog1->Execute() == false)
  return;

FILE *fr;
int result;
float x, y;

fr = fopen(OpenDialog1->FileName.c_str(), "r");
if (fr == NULL) {
  Application->MessageBox("Soubor se nepodarilo otevrit?", "Chyba", MB_OK);
  return;
}

int counter = 0;
while (fscanf(fr, "%f;%f", &x, &y) != EOF) {
  StringGrid1->Cells[0][counter] = x;
  StringGrid1->Cells[1][counter] = y;
  counter++;
  StringGrid1->RowCount = counter;
}

}
//---------------------------------------------------------------------------

void __fastcall TFormData::LbSpeedButton1Click(TObject *Sender)
{
Form1->Image1->Canvas->Font->Size = 6;

double xp = -10, hx = 0;
int citac = 0;
double A0, A1 , B0, B1;

// automaticky nastavit rozsah hodnot
Form1->x1 = StringGrid1->Cells[0][0].ToDouble();
Form1->y1 = StringGrid1->Cells[1][0].ToDouble();
Form1->x2=  StringGrid1->Cells[0][StringGrid1->RowCount-1].ToDouble();
Form1->y2 = StringGrid1->Cells[1][StringGrid1->RowCount-1].ToDouble();
Form1->SpeedButton1Click(Sender);
Form1->Image1->Invalidate();


// kdys help tak vse smaz
if (Form1->about == true) {
 Form1->SpeedButton1Click(Sender);
 Form1->about = false;
}


// inic. hodnoty pocitadla

//hx = (x2-x1)/Form2->Edit11->Text.ToInt(); // prirustek na ose X
hx = 0.1;
xp = StringGrid1->Cells[0][0].ToDouble();
A0 = xp;

A1 = StringGrid1->Cells[1][0].ToDouble();
for (int i = 0; i < StringGrid1->RowCount; i++) {
	B0 = StringGrid1->Cells[0][i].ToDouble();

  AnsiString Cislo = (AnsiString) (xp);
  int pocet = 0;

  if ((pocet = Cislo.LastDelimiter(",")) != NULL)
    Cislo[pocet] = '.';

  //Caption = Cislo;
  B1 = StringGrid1->Cells[1][i].ToDouble();
  //
 Form1->Image1->Canvas->MoveTo(Form1->x_absolut(A0), Form1->y_absolut(A1));
 Form1->Image1->Canvas->LineTo(Form1->x_absolut(B0), Form1->y_absolut(B1));


  A0=B0, A1=B1;

  xp = (double) (-1000 + citac)/100;
  citac++;
}

}
//---------------------------------------------------------------------------

