//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Numerika.h"
//#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LbSpeedButton"
#pragma resource "*.dfm"
TNumMat *NumMat;

double TNumMat::myFunkce(double t) {
	//double a = sin(t*3.14/180);
  Form1->EditExp1->VarGrid = Form1->StringGrid1;
  Form1->EditExp1->UseVar  = true;
  AnsiString exp = Form1->EditExp1->Exp;
  Form1->StringGrid1->Cells[1][1] = "X";
  Form1->StringGrid1->Cells[2][1] = (AnsiString) t;

  AnsiString Cislo = (AnsiString) (t);
  int pocet = 0;

  if ((pocet = Cislo.LastDelimiter(",")) != NULL)
    Cislo[pocet] = '.';

  //Caption = Cislo;

  Form1->StringGrid1->Cells[2][1] = Cislo;

  return Form1->EditExp1->Value;
	//return (5+sin(t*3.14/180));
	//return (5+t);
}
double TNumMat::Obdelnikova(double start, double stop, double step) {
	double t = start;
	double plocha = 0;
  int line=1;

  Variant Sheet;
  Variant Excel;
  if (CheckEXCEL->Checked == true) {

    Excel = Variant::CreateObject("Excel.Application");

    Excel.OlePropertySet("Visible", true);
    Excel.OlePropertyGet("ActiveWorkBook");
    Excel.OlePropertyGet("WorkBooks").OleFunction("Add");

    Sheet=Excel.OlePropertyGet("ActiveSheet");
  }

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
     line++;
     if ((t+step) > stop)
        step = stop-t;
    	plocha += step*fabs(myFunkce(t));
      if (CheckEXCEL->Checked == true) {
        Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
        Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", plocha);
      }
      // nakreslit obdelnik
      Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
      t += step;
	}
	return plocha;
}
double TNumMat::Lichobeznikova(double start, double stop, double step) {
	double t = start;
	double plocha = 0;
  int line = 1;

    Variant Sheet;
  Variant Excel;
  if (CheckEXCEL->Checked == true) {

    Excel = Variant::CreateObject("Excel.Application");

    Excel.OlePropertySet("Visible", true);
    Excel.OlePropertyGet("ActiveWorkBook");
    Excel.OlePropertyGet("WorkBooks").OleFunction("Add");

    Sheet=Excel.OlePropertyGet("ActiveSheet");
  }


	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");

        HDC hdc = Form1->Image1->Canvas->Handle;
        SetBkMode(hdc,OPAQUE);

        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(start), Form1->y_absolut(0));
        Form1->Image1->Canvas->Brush->Color = clBlack;
        Form1->Image1->Canvas->Brush->Style = bsDiagCross;
        if (BeginPath(hdc) == false)
            ShowMessage("AAAA");

	while (t < stop) {
    line++;
		//plocha += step*fabsf(myFunkce(t+step)-myFunkce(t)/step);

    if ((t+step) > stop)
      step = stop-t;
		plocha += step*fabs(myFunkce(t))+(myFunkce(t+step)-myFunkce(t))*step;
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", plocha);
    }
    // nakreslit obdelnik
    Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(myFunkce(t)));
    Form1->Image1->Canvas->LineTo(Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t+step)));
    Form1->Image1->Canvas->Pen->Color = clBlack;
    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(t),3,3);
    /////////////////////
		t += step;
	}
  Form1->Image1->Canvas->LineTo(Form1->x_absolut(stop), Form1->y_absolut(0));
  //Form1->Image1->Canvas->Brush->Style = bsBDiagonal;
  if (EndPath(hdc) == false)
   ShowMessage("BBBB");
  if (FillPath(hdc) == false)
    ShowMessage("CCCC");

  StrokePath(hdc);

  Form1->Image1->Canvas->Brush->Color = clWhite;
  Form1->Image1->Canvas->Brush->Style = bsClear;

	return plocha;
}

/*
int main(int argc, char* argv[])
{
	double S;
	printf("\nNUMERICKA INTEGRACE:");
	S = Obdelnikova(0, 1, 0.0005);
	printf("\nPlocha: %f", S);
	getch();
	return 0;
}
*/

//---------------------------------------------------------------------------
__fastcall TNumMat::TNumMat(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TNumMat::LbSpeedButton1Click(TObject *Sender)
{
  double S;
	//printf("\nNUMERICKA INTEGRACE:");
  Form1->Image1->Canvas->Pen->Color = ColorDialog1->Color;
  //Form1->Image1->Canvas->Pen->Mode = psDash;
  //Form1->Image1->Canvas->Brush->Style = bsBDiagonal;

  S = Obdelnikova(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
  AnsiString Vysledek;
  Vysledek = "S = " + (AnsiString) S;
  Form1->Image1->Canvas->Font->Size = 10;
  Form1->Image1->Canvas->TextOut(Form1->x_absolut(EditPoc->Text.ToDouble())+2,Form1->y_absolut(1), Vysledek);
  EditResult->Text = S;
	//printf("\nPlocha: %f", S);
	//getch();
	//return 0;

}
//---------------------------------------------------------------------------

void __fastcall TNumMat::LbSpeedButton2Click(TObject *Sender)
{
if (ColorDialog1->Execute() == false)
  return;

Panel1->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TNumMat::FormShow(TObject *Sender)
{

 Panel1->Color = ColorDialog1->Color;
}
//---------------------------------------------------------------------------

void __fastcall TNumMat::LbSpeedButton3Click(TObject *Sender)
{
  double S;

	//printf("\nNUMERICKA INTEGRACE:");
  Form1->Image1->Canvas->Pen->Color = ColorDialog1->Color;
  //Form1->Image1->Canvas->Pen->Mode = psDash;
  //Form1->Image1->Canvas->Brush->Style = bsBDiagonal;

	S = Lichobeznikova(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
  AnsiString Vysledek;
  Vysledek = "S = " + (AnsiString) S;
  Form1->Image1->Canvas->Font->Size = 10;
  Form1->Image1->Canvas->Brush->Color = clWhite;
  Form1->Image1->Canvas->TextOut(Form1->x_absolut(EditPoc->Text.ToDouble())+2,Form1->y_absolut(1), Vysledek);
  EditResult->Text = S;
}
//---------------------------------------------------------------------------


double TNumMat::Simpsonova(double start, double stop, double step)
{
  double t = start;
	//double plocha = 0;
  double suma = 0;
  bool licha = false;

  Variant Sheet;
  Variant Excel;
  if (CheckEXCEL->Checked == true) {

    Excel = Variant::CreateObject("Excel.Application");

    Excel.OlePropertySet("Visible", true);
    Excel.OlePropertyGet("ActiveWorkBook");
    Excel.OlePropertyGet("WorkBooks").OleFunction("Add");

    Sheet=Excel.OlePropertyGet("ActiveSheet");
  }

	if (start >= stop) {
		Application->MessageBox("\nSTART nemuze byt veci jako STOP", "POZOR", MB_OK);
    return 0;
  }
  int pocet = (stop-start)/step;

  for (int i = 0; i <= pocet; i++) {
    if (i == 0) {
      suma += fabs(myFunkce(t));
      if (CheckEXCEL->Checked == true) {
        Sheet.OlePropertyGet("Cells",i+1,1).OlePropertySet("Value", t+i*step);
        Sheet.OlePropertyGet("Cells",i+1,2).OlePropertySet("Value", (step/3)*suma);
      }
      continue;
    }
    if (i == pocet) {
      suma += fabs(myFunkce(t+pocet*step));
      if (CheckEXCEL->Checked == true) {
        Sheet.OlePropertyGet("Cells",i+1,1).OlePropertySet("Value", t+i*step);
        Sheet.OlePropertyGet("Cells",i+1,2).OlePropertySet("Value", (step/3)*suma);
      }
      continue;
    }
    if (licha == true)
      suma += fabs(4*myFunkce(t+i*step));
    else
      suma += fabs(2*myFunkce(t+i*step));

    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",i+1,1).OlePropertySet("Value", t+i*step);
      Sheet.OlePropertyGet("Cells",i+1,2).OlePropertySet("Value", (step/3)*suma);
    }
    licha += -1;
  }

	return (step/3)*suma;
}
void __fastcall TNumMat::LbSpeedButton4Click(TObject *Sender)
{
  double S;

	S = Simpsonova(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
  AnsiString Vysledek;
  Vysledek = "S = " + (AnsiString) S;
  EditResult->Text = S;
}
//---------------------------------------------------------------------------

