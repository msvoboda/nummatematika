//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Bezier_u1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TBezierCurve *BezierCurve;

TCanvas *g;

float t;
int mx, my;

int nv=-1;

float vrcholy[20][2];


int faktorial(int n)
{
	int s=1;
	for(int i=n;i>0;i--) {
	   s=s*i;
	}
	return s;
}

float mocnina(float x,int n)
{
	float s1=1;
	for(int i=0;i<n;i++) {
	  s1=s1*x;
	}
	return s1;
}

float berstain(float t, int n, int i)
{
	return (faktorial(n)/(faktorial(i)*faktorial(n-i)))*mocnina(t,i)*mocnina(1-t,n-i);
}


//---------------------------------------------------------------------------
__fastcall TBezierCurve::TBezierCurve(TComponent* Owner): TForm(Owner)
{
    g = Img->Canvas;

    g->Pen->Color = clBlack;
    g->Brush->Color = clSilver;
    g->Brush->Style = bsSolid;
    g->Rectangle(0,0,Img->Width,Img->Height);

   g->Pen->Color = clGray;
   for(int i=0; i< nv; i++)  {
     g->MoveTo(vrcholy[i][0],vrcholy[i][1]);
     g->LineTo(vrcholy[i+1][0],vrcholy[i+1][1]);
   }


}
//---------------------------------------------------------------------------

void __fastcall TBezierCurve::ExitBtnClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TBezierCurve::StartBtnClick(TObject *Sender)
{
   float x1 = vrcholy[0][0],
         y1 = vrcholy[0][1];

   float y=0,x=0;

   g->Pen->Color = clBlack;
   x = 0;
   y = 0;
   x1 = vrcholy[0][0];
   y1 = vrcholy[0][1];
   for(int j=0; j<100; j++) {
     t = j;
     t=(float)(t/100);
     x = 0;
     y = 0;
     for(int i=0; i< ListBox1->Items->Count; i++) {
       x=x+vrcholy[i][0]*berstain(t,nv,i);
	     y=y+vrcholy[i][1]*berstain(t,nv,i);
     }
     g->MoveTo(x1,y1);
     g->LineTo(x,y);
     x1=x;y1=y;
   }
}
//---------------------------------------------------------------------------
void __fastcall TBezierCurve::Button1Click(TObject *Sender)
{

  nv++;
  vrcholy[nv][0] = mx;
  vrcholy[nv][1] = my;

  ListBox1->Items->Add("Vrchol " + (AnsiString)(nv+1));

    g = Img->Canvas;

    g->Pen->Color = clBlack;
    g->Brush->Color = clSilver;
    g->Brush->Style = bsSolid;
    g->Rectangle(0,0,Img->Width,Img->Height);

   g->Pen->Color = clGray;
   for(int i=0; i < nv; i++)  {
     g->MoveTo(vrcholy[i][0],vrcholy[i][1]);
     g->LineTo(vrcholy[i+1][0],vrcholy[i+1][1]);
   }
}
//---------------------------------------------------------------------------


void __fastcall TBezierCurve::ImgMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
  mx = X;
  my = Y;
  Edit1->Text = X;
  Edit2->Text = Y;
}
//---------------------------------------------------------------------------


void __fastcall TBezierCurve::Button2Click(TObject *Sender)
{
int polozek;

for (polozek = 0; polozek < ListBox1->Items->Count; polozek++) {
      if (ListBox1->Selected[polozek] == true) {
            break;
      }
}
vrcholy[polozek][0] = Edit1->Text.ToDouble();
vrcholy[polozek][1] = Edit2->Text.ToDouble();

    g = Img->Canvas;

    g->Pen->Color = clBlack;
    g->Brush->Color = clSilver;
    g->Brush->Style = bsSolid;
    g->Rectangle(0,0,Img->Width,Img->Height);

   g->Pen->Color = clGray;
   for(int i=0; i < nv; i++)  {
     g->MoveTo(vrcholy[i][0],vrcholy[i][1]);
     g->LineTo(vrcholy[i+1][0],vrcholy[i+1][1]);
   }
}
//---------------------------------------------------------------------------

void __fastcall TBezierCurve::ListBox1Click(TObject *Sender)
{
int polozek;

for (polozek = 0; polozek < ListBox1->Items->Count; polozek++) {
      if (ListBox1->Selected[polozek] == true) {
            break;
      }
}
Edit1->Text = vrcholy[polozek][0];
Edit2->Text = vrcholy[polozek][1];
}
//---------------------------------------------------------------------------

void __fastcall TBezierCurve::Button3Click(TObject *Sender)
{
ListBox1->Clear();
nv = -1;
    g->Pen->Color = clBlack;
    g->Brush->Color = clSilver;
    g->Brush->Style = bsSolid;
    g->Rectangle(0,0,Img->Width,Img->Height);
}
//---------------------------------------------------------------------------

