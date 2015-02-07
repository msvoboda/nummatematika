//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <vcl\printers.hpp> // nutne pro tisk
//---------------------------------------------------------------------------
#pragma link "LbSpeedButton"
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------//---------------------------------------------------------------------------5
void __fastcall TForm2::Button2Click(TObject *Sender)
{
// nejdrive smazat
TRect Orez;
Orez = Form1->Image1->Canvas->ClipRect;
Form1->Image1->Canvas->FillRect(Orez);

Form1->Image1->Canvas->Pen->Color = clBlack;
// kvuli interakci
Form1->x1 = Edit1->Text.ToInt();
Form1->x2 = Edit3->Text.ToInt();
Form1->y1 = Edit2->Text.ToInt();
Form1->y2 = Edit4->Text.ToInt();
Unit_X = Form1->Image1->Width/(Form1->x2-Form1->x1);
Unit_Y = Form1->Image1->Height/(Form1->y2-Form1->y1);
O[0] = -Form1->x1*Unit_X;
O[1] = Form1->y2*Unit_Y;

Form1->Image1->Canvas->MoveTo(0, O[1]);
Form1->Image1->Canvas->LineTo(Form1->Image1->Width, O[1]);
Form1->Image1->Canvas->TextOut(Form1->Image1->Width-10, O[1]-14, "X");
Form1->Image1->Canvas->MoveTo(O[0], 0);
Form1->Image1->Canvas->LineTo(O[0], Form1->Image1->Height);
Form1->Image1->Canvas->TextOut(O[0]+4, 2, "Y");
// Canvas - Font
if (CheckBox1->Checked == TRUE) {
Form1->Image1->Canvas->Font->Color = clBlack;
Form1->Image1->Canvas->Font->Size = 6;
Form1->Image1->Canvas->Font->Name = "Arial";
for (int linex = (Edit1->Text.ToInt()); linex <= (Edit3->Text.ToInt()); linex++) {
	Form1->Image1->Canvas->MoveTo(Form1->x_absolut(linex), O[1]-3);
   	Form1->Image1->Canvas->LineTo(Form1->x_absolut(linex), O[1]+3);
    Form1->Image1->Canvas->TextOut(Form1->x_absolut(linex)+1,O[1]+4, (AnsiString) linex);
}
for (int liney = (Edit2->Text.ToInt()); liney <= (Edit4->Text.ToInt()); liney++) {
    if (liney == 0) continue;
	Form1->Image1->Canvas->MoveTo(O[0]-3, Form1->y_absolut(liney));
   	Form1->Image1->Canvas->LineTo(O[0]+3, Form1->y_absolut(liney));
    Form1->Image1->Canvas->TextOut(O[0]-16,Form1->y_absolut(liney)+1, (AnsiString) liney);
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckSecondOsaClick(TObject *Sender)
{
 if (((TCheckBox *)Sender)->Checked == true) {
    EditSec->Enabled = true;
 }
 else {
     EditSec->Enabled = false;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::LbSpeedButton1Click(TObject *Sender)
{
if (ColorDialog1->Execute() == false)
  return;

Form1->Image1->Canvas->Pen->Color = ColorDialog1->Color;
Panel1->Color = Form1->Image1->Canvas->Pen->Color;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormShow(TObject *Sender)
{
Panel1->Color = Form1->Image1->Canvas->Pen->Color;  
}
//---------------------------------------------------------------------------

