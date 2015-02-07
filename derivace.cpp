//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "derivace.h"
#include <stdio.h>
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "LbSpeedButton"
#pragma resource "*.dfm"
TNumDeriv *NumDeriv;
//---------------------------------------------------------------------------
__fastcall TNumDeriv::TNumDeriv(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TNumDeriv::Deriv2Point(double start, double stop, double step)
{
  double t = start;
	double deriv = 0;
  bool first = true;
  int line = 1;

  Variant Sheet;
  Variant Excel;
  if (CheckEXCEL->Checked == true) {

    Excel = Variant::CreateObject("Excel.Application");
    //Excel.OleFunction("Open","C:\\1.xls");
    Excel.OlePropertySet("Visible", true);
    Excel.OlePropertyGet("ActiveWorkBook");
    Excel.OlePropertyGet("WorkBooks").OleFunction("Add");

    Sheet=Excel.OlePropertyGet("ActiveSheet");
    //Sheet.OleFunction("Open","C:\\1.xls");
    //Excel.OleFunction ("Quit");
  }

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (myFunkce(t+step)-myFunkce(t))/step;
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}


double TNumDeriv::myFunkce(double t)
{
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
void __fastcall TNumDeriv::LbSpeedButton1Click(TObject *Sender)
{
Deriv2Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------


void TNumDeriv::Deriv3Point(double start, double stop, double step)
{
 double t = start;
	double deriv = 0;
  bool first = true;
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

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (-3*myFunkce(t)+4*myFunkce(t+step)-myFunkce(t+2*step))/(2*step);
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}
void __fastcall TNumDeriv::LbSpeedButton2Click(TObject *Sender)
{
Deriv3Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------


void TNumDeriv::Deriv4Point(double start, double stop, double step)
{
 double t = start;
	double deriv = 0;
  bool first = true;
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

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (-2*myFunkce(t-step)-3*myFunkce(t)+6*myFunkce(t+step)-myFunkce(t+2*step))/(6*step);
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}
void __fastcall TNumDeriv::LbSpeedButton3Click(TObject *Sender)
{
Deriv4Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------


void TNumDeriv::Deriv5Point(double start, double stop, double step)
{
 double t = start;
	double deriv = 0;
  bool first = true;
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

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (-3*myFunkce(t-step)-10*myFunkce(t)+18*myFunkce(t+step)-6*myFunkce(t+2*step)+myFunkce(t+3*step))/(12*step);
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}
void __fastcall TNumDeriv::LbSpeedButton4Click(TObject *Sender)
{
Deriv5Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------


void TNumDeriv::SecDeriv3Point(double start, double stop, double step)
{
 double t = start;
	double deriv = 0;
  bool first = true;
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

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (myFunkce(t-step)-2*myFunkce(t)+myFunkce(t+step))/(step*step);
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}
void __fastcall TNumDeriv::LbSpeedButton5Click(TObject *Sender)
{
SecDeriv3Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------


void TNumDeriv::SecDeriv4Point(double start, double stop, double step)
{
 double t = start;
	double deriv = 0;
  bool first = true;
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

  //Sheet.OleFunction("SaveAs","C:\\MujOleExcel.xls");
  //Excel.OleFunction ("Quit");

	if (start >= stop)
		printf("\nSTART nemuze byt veci jako STOP");
	while (t < stop) {
    if ((t+step) > stop)
       step = stop-t;

  	deriv = (2*myFunkce(t)-5*myFunkce(t+step)+4*myFunkce(t+2*step)-myFunkce(t+3*step))/(step*step);
    if (CheckEXCEL->Checked == true) {
      Sheet.OlePropertyGet("Cells",line,1).OlePropertySet("Value", t);
      Sheet.OlePropertyGet("Cells",line,2).OlePropertySet("Value", deriv);
    }
    // nakreslit obdelnik
    if (first == true) {
        Form1->Image1->Canvas->MoveTo(Form1->x_absolut(t), Form1->y_absolut(deriv));
        first = false;
    }
    else
        Form1->Image1->Canvas->LineTo(Form1->x_absolut(t), Form1->y_absolut(deriv));

    //Form1->Image1->Canvas->RoundRect(Form1->x_absolut(t), Form1->y_absolut(0), Form1->x_absolut(t+step), Form1->y_absolut(myFunkce(t)),3,3);
    t += step;
    line++;
	}
	return;
}
void __fastcall TNumDeriv::LbSpeedButton6Click(TObject *Sender)
{
SecDeriv4Point(EditPoc->Text.ToDouble(), EditKon->Text.ToDouble(), EditStep->Text.ToDouble());
}
//---------------------------------------------------------------------------

void __fastcall TNumDeriv::FormShow(TObject *Sender)
{
 Panel1->Color = ColorDialog1->Color;  
}
//---------------------------------------------------------------------------

void __fastcall TNumDeriv::LbSpeedButton7Click(TObject *Sender)
{
if (ColorDialog1->Execute() == false)
  return;

Panel1->Color = ColorDialog1->Color;
  
}
//---------------------------------------------------------------------------

