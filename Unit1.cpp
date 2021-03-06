//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#include <vcl\clipbrd.hpp>

#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "derivace.h"
#include "Numerika.h"
#include "Namereno.h"
#include "Bezier_u1.h"
#include <stdlib.h>
#include "difrov.h"
#include "mat3d.h"

#include <math.h>
//---------------------------------------------------------------------------
#pragma link "colorgrd"
#pragma link "LbSpeedButton"
#pragma link "EditExp"
#pragma resource "*.dfm"
TForm1 *Form1;
float x1,x2, y1, y2;
float Unit_X = 1, Unit_Y = 1;
float O[2];
AnsiString Syntax; // syntaxe
double vysledek;
long pocitadlo = 0;
AnsiString Title = "A";

// vrati absolutni souradnici x
float TForm1::x_absolut(float realx) {
	return(O[0]+Unit_X*realx);
}
// vrati absolutni souradnici y
float TForm1::y_absolut(float realy) {
	return(O[1]-Unit_Y*realy);
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
  about = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
TStringList * Listing;
Listing = new TStringList();
TStringList * Nespojitost;
Nespojitost = new TStringList();

Form1->Image1->Canvas->Font->Size = 6;

double xp = -10, hx = 0;
int citac = 1;
double A0, A1 , B0, B1;


// kdys help tak vse smaz
if (about == true) {
 TForm1::SpeedButton1Click(Sender);
 about = false;
}


// inic. hodnoty pocitadla
pocitadlo = 0;
//natahnout vzorec do pameti
EditExp1->Text = Edit12->Text;

//hx = (x2-x1)/Form2->Edit11->Text.ToInt(); // prirustek na ose X
hx = 0.1;
xp = x1;
A0 = xp;
 // dosadit do promene hodnotu
 EditExp1->VarGrid = StringGrid1;
 EditExp1->UseVar  = true;
 StringGrid1->Cells[1][1] = "X";
 StringGrid1->Cells[2][1] = (AnsiString) xp;

A1 = EditExp1->Value;
do {
	B0 = xp;

  AnsiString Cislo = (AnsiString) (xp);
  int pocet = 0;

  if ((pocet = Cislo.LastDelimiter(",")) != NULL)
    Cislo[pocet] = '.';

  //Caption = Cislo;

  StringGrid1->Cells[2][1] = Cislo;
  B1 = EditExp1->Value;
  Label3->Caption = EditExp1->GetError();
  if (EditExp1->GetError() != " No error ") {
    Listing->Add(EditExp1->GetError());
    Listing->Add("X = " + (AnsiString) B0);
    Nespojitost->Add(B0);
    TForm1::Button2Click(Sender);
  }


  if (EditExp1->GetError() == " No error ") {
    Image1->Canvas->MoveTo(x_absolut(A0), y_absolut(A1));
	  Image1->Canvas->LineTo(x_absolut(B0), y_absolut(B1));
  }

  A0=B0, A1=B1;

    xp = (double) (-1000 + citac)/100;
    citac++;
    pocitadlo = 0; // dulezite
} while (xp < x2);

ListBox1->Clear();
for (int i = 0; i < Nespojitost->Count; i++) {
  Edit1->Text = (AnsiString) (Nespojitost->Strings[i].ToInt());
  ListBox1->Items->Add(AnsiString (i+1) + ") X = " + Edit1->Text);
  TForm1::Button2Click(Sender);
}
Listing->SaveToFile("Error");

delete Listing;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
Image1->Canvas->Pen->Color = clRed;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
Image1->Canvas->Pen->Color = clBlack;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
Image1->Canvas->Pen->Color = clGreen;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Form2->ShowModal();
// kvuli interakci
x1 = Form2->Edit1->Text.ToDouble();
x2 = Form2->Edit3->Text.ToDouble();
y1 = Form2->Edit2->Text.ToDouble();
y2 = Form2->Edit4->Text.ToDouble();
SpeedButton1Click(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{

x1 = Form2->Edit1->Text.ToInt();
x2 = Form2->Edit3->Text.ToInt();
y1 = Form2->Edit2->Text.ToInt();
y2 = Form2->Edit4->Text.ToInt();


Unit_X = Image1->Width/(x2-x1);
Unit_Y = Image1->Height/(y2-y1);
O[0] = -x1*Unit_X;
O[1] = y2*Unit_Y;

//smazat
TRect Orez;
Orez = Image1->Canvas->ClipRect;
Image1->Canvas->FillRect(Orez);

Form1->Image1->Canvas->MoveTo(0, O[1]);
Form1->Image1->Canvas->LineTo(Form1->Image1->Width, O[1]);
Form1->Image1->Canvas->TextOut(Form1->Image1->Width-10, O[1]-14, "X");
Form1->Image1->Canvas->MoveTo(O[0], 0);
Form1->Image1->Canvas->LineTo(O[0], Form1->Image1->Height);
Form1->Image1->Canvas->TextOut(O[0]+4, 2, "Y");
// Canvas - Font
if (Form2->CheckBox1->Checked == TRUE) {
Form1->Image1->Canvas->Font->Color = clBlack;
Form1->Image1->Canvas->Font->Size = 6;
Form1->Image1->Canvas->Font->Name = "Arial";
for (int linex = (Form2->Edit1->Text.ToInt()); linex <= (Form2->Edit3->Text.ToInt()); linex++) {
	Form1->Image1->Canvas->MoveTo(x_absolut(linex), O[1]-3);
   	Form1->Image1->Canvas->LineTo(x_absolut(linex), O[1]+3);
    Form1->Image1->Canvas->TextOut(x_absolut(linex)+1,O[1]+4, (AnsiString) linex);
}

for (int liney = (Form2->Edit2->Text.ToInt()); liney <= (Form2->Edit4->Text.ToInt()); liney++) {
    if (liney == 0) continue;
	Form1->Image1->Canvas->MoveTo(O[0]-3, y_absolut(liney));
   	Form1->Image1->Canvas->LineTo(O[0]+3, y_absolut(liney));
    Form1->Image1->Canvas->TextOut(O[0]-16,y_absolut(liney)+1, (AnsiString) liney);
}
}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ComboBox1Change(TObject *Sender)
{
Edit12->Text = ComboBox1->Text;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
// nejdrive smazat
TRect Orez;
Form1->Image1->Canvas->Brush->Style = bsClear;
Form1->Image1->Canvas->Brush->Color = clWhite;
Orez = Form1->Image1->Canvas->ClipRect;
Form1->Image1->Canvas->FillRect(Orez);
Form1->Image1->Canvas->Font->Size = 8;
Form1->Image1->Canvas->Font->Color = clBlack;
Form1->Image1->Canvas->TextOut(15,2, "Numerick� matematika - miskyn@centrum.cz");

Form1->Image1->Canvas->Pen->Color = clBlack;

Unit_X = Form1->Image1->Width/(x2-x1);
Unit_Y = Form1->Image1->Height/(y2-y1);
O[0] = -x1*Unit_X;
O[1] = y2*Unit_Y;

Form1->Image1->Canvas->MoveTo(0, O[1]);
Form1->Image1->Canvas->LineTo(Form1->Image1->Width, O[1]);
Form1->Image1->Canvas->TextOut(Form1->Image1->Width-10, O[1]-14, "X");
Form1->Image1->Canvas->MoveTo(O[0], 0);
Form1->Image1->Canvas->LineTo(O[0], Form1->Image1->Height);
Form1->Image1->Canvas->TextOut(O[0]+4, 2, "Y");
// Canvas - Font
if (Form2->CheckBox1->Checked == TRUE) {
Form1->Image1->Canvas->Font->Color = clBlack;
Form1->Image1->Canvas->Font->Size = 6;
Form1->Image1->Canvas->Font->Name = "Arial";
for (double linex = (Form2->Edit1->Text.ToDouble()); linex <= (Form2->Edit3->Text.ToDouble()); linex += Form2->EditX->Text.ToDouble()) {
	Form1->Image1->Canvas->MoveTo(x_absolut(linex), O[1]-3);
   	Form1->Image1->Canvas->LineTo(x_absolut(linex), O[1]+3);
    Form1->Image1->Canvas->TextOut(x_absolut(linex)+1,O[1]+4, (AnsiString) linex);
}
for (double liney = (Form2->Edit2->Text.ToDouble()); liney <= (Form2->Edit4->Text.ToDouble()); liney += Form2->EditY->Text.ToDouble()) {
    if (liney == 0) continue;
  	Form1->Image1->Canvas->MoveTo(O[0]-3, y_absolut(liney));
   	Form1->Image1->Canvas->LineTo(O[0]+3, y_absolut(liney));
    Form1->Image1->Canvas->TextOut(O[0]-16,y_absolut(liney)+1, (AnsiString) liney);
}
// vedlejsi jednotky
if (Form2->CheckSecondOsa->Checked == true) {
for (double linex = (Form2->Edit1->Text.ToInt()); linex <= (Form2->Edit3->Text.ToInt()); linex += Form2->EditSec->Text.ToDouble()) {
	Form1->Image1->Canvas->MoveTo(x_absolut(linex), O[1]-3);
   	Form1->Image1->Canvas->LineTo(x_absolut(linex), O[1]+3);
    //Form1->Image1->Canvas->TextOut(x_absolut(linex)+1,O[1]+4, (AnsiString) linex);
}

for (double liney = (Form2->Edit2->Text.ToInt()); liney <= (Form2->Edit4->Text.ToInt()); liney += Form2->EditSec->Text.ToDouble()) {
    if (liney == 0) continue;
  	Form1->Image1->Canvas->MoveTo(O[0]-3, y_absolut(liney));
   	Form1->Image1->Canvas->LineTo(O[0]+3, y_absolut(liney));
    //Form1->Image1->Canvas->TextOut(O[0]-16,y_absolut(liney)+1, (AnsiString) liney);
}
}
}
Label3->Caption = "No Error";
ListBox1->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
lbBod->Enabled = FALSE;
Title = InputBox("Jm�no vkl�dan�ho bodu", "", Title);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y)
{
Form1->Image1->Canvas->Pen->Color = clBlack;
if (lbBod->Enabled == FALSE) {
	Image1->Canvas->Ellipse(X-2,Y-2, X+2,Y+2);
  Image1->Canvas->Font->Size = 12;
  Image1->Canvas->TextOut(X+4, Y-10, Title);
}
if (lbLine->Enabled == FALSE) {
  Image1->Canvas->Pen->Style = psDot;
	Image1->Canvas->MoveTo(X, Y);
  Image1->Canvas->LineTo(X, y_absolut(0));
    Image1->Canvas->Pen->Style = psSolid;
}

lbBod->Enabled = TRUE;
lbLine->Enabled = TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Image1->Canvas->Pen->Style = psDot;
Image1->Canvas->MoveTo(x_absolut(Edit1->Text.ToInt()), 0);
Image1->Canvas->LineTo(x_absolut(Edit1->Text.ToInt()), Image1->Height);
Image1->Canvas->Pen->Style = psSolid;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------


void __fastcall TForm1::LbSpeedButton1Click(TObject *Sender)
{
about = true;
// nejdrive smazat
TRect Orez;
Orez = Form1->Image1->Canvas->ClipRect;
Form1->Image1->Canvas->FillRect(Orez);

Form1->Image1->Canvas->Font->Color = clRed;
Form1->Image1->Canvas->Font->Size = 16;
Form1->Image1->Canvas->TextOut(10, 20, "Matematick� funkce 2.0 alfa");
Form1->Image1->Canvas->Font->Color = clNavy;
Form1->Image1->Canvas->Font->Size = 12;
Form1->Image1->Canvas->TextOut(10, 60, "Created by Mi�kyn 2003 (c) (miskyn@centrum.cz)");
Form1->Image1->Canvas->TextOut(10, 75, "sky lights");
Form1->Image1->Canvas->TextOut(10, 100, "Tento software je pro voln� pou�it� (freeware)");
Form1->Image1->Canvas->TextOut(10, 120, "Bugs:");
Form1->Image1->Canvas->TextOut(10, 145, "Nezjist� body nespojitosti funkce tangens, cotangens.");
Form1->Image1->Canvas->TextOut(10, 165, "Nen� ur�en� pro funkce, kde je nut� vysok� p�esnost experiment�ln�ho v�po�tu.");

Form1->Image1->Canvas->Font->Size = 10;
Form1->Image1->Canvas->Font->Color = clRed;
Form1->Image1->Canvas->TextOut(100, 250, "www.mujweb.cz/www/direktsit/");
Form1->Image1->Canvas->TextOut(100, 270, "www.builder.cz  (p��klad)");



}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton2Click(TObject *Sender)
{
NumMat->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Koprovatdoschrnky1Click(TObject *Sender)
{
  int DataHandle;
  HPALETTE APalette;
  unsigned short MyFormat;
  try
  {
    //Bitmap->LoadFromFile("C:\\Program  Files\\Common Files\\Borland Shared\\Images\\Splash\\256color\\factory.bmp ");
    // generate a clipboard format, with data and palette
    //Image1->Picture->Bitmap->SaveToClipboardFormat(MyFormat,DataHandle,APalette);
    Clipboard()->Assign(Image1->Picture->Bitmap);
    // save the data to the clipboard using that format and
    // the generated data
    //Clipboard()->SetAsHandle(MyFormat,DataHandle);
  }
  catch (...)
  {
     ShowMessage("Nelze zkop�rovat do schr�nky!");
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton3Click(TObject *Sender)
{
NumDeriv->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton6Click(TObject *Sender)
{
FormData->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton4Click(TObject *Sender)
{
FormDR->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lbLineClick(TObject *Sender)
{
lbLine->Enabled = FALSE;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton7Click(TObject *Sender)
{
BezierCurve = new TBezierCurve(this);
BezierCurve->ShowModal();
BezierCurve->Free();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::LbSpeedButton5Click(TObject *Sender)
{
Form3D = new TForm3D(this);
Form3D->ShowModal();
Form3D->Free();
}
//---------------------------------------------------------------------------

