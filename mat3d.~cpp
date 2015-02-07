//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

//#include "main.h"
#include "mat3d.h"
#include <math.h>
#include "jpeg.hpp"
#include "Unit1.h"
#include "Unit2.h"
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "EditExp"
#pragma link "LbSpeedButton"
#pragma resource "*.dfm"
TForm3D *Form3D;
BYTE *textura1;
BYTE *textura2;
int sirka, vyska;

BOOL bSetupPixelFormat(HDC hDC)
{
static PIXELFORMATDESCRIPTOR pfd = {
	sizeof(PIXELFORMATDESCRIPTOR),
	1,
	PFD_DRAW_TO_WINDOW |
	PFD_SUPPORT_OPENGL |
    PFD_DOUBLEBUFFER,		// double buffer !!!!
	PFD_TYPE_RGBA,			// RGBA
	24,
	0, 0, 0, 0, 0, 0,
	0,
	0,
	0,
	0, 0, 0, 0,
	32,
	0,
	0,
	PFD_MAIN_PLANE,
	0,
	0, 0, 0
};
int pixelformat;


if ( (pixelformat = ChoosePixelFormat(hDC, &pfd)) == 0 )
    {
        MessageBox(NULL, "ChoosePixelFormat failed", "Error", MB_OK);
        return FALSE;
    }

    if (SetPixelFormat(hDC, pixelformat, &pfd) == FALSE)
    {
        MessageBox(NULL, "SetPixelFormat failed", "Error", MB_OK);
        return FALSE;
    }

return TRUE;
}


//---------------------------------------------------------------------------
__fastcall TForm3D::TForm3D(TComponent* Owner)
  : TForm(Owner)
{
  TColor Barva;
  TJPEGImage *Nic1;
  Nic1 = new TJPEGImage();
  Nic1->LoadFromFile("crate.jpg");

  sirka = Nic1->Bitmap->Width;
  vyska = Nic1->Bitmap->Height;

  textura1 = new BYTE[3*Nic1->Bitmap->Width*Nic1->Bitmap->Height];
  for (int y = 0; y < Nic1->Bitmap->Height; y++) {
    for (int x = 0; x < Nic1->Bitmap->Width; x++) {
      Barva = Nic1->Bitmap->Canvas->Pixels[x][y];
      *(textura1 +3*y*Nic1->Bitmap->Height+3*x) = GetRValue(Barva);
      *(textura1 +3*y*Nic1->Bitmap->Height+3*x+1) = GetGValue(Barva);
      *(textura1 +3*y*Nic1->Bitmap->Height+3*x+2) = GetGValue(Barva);

      //CopyMemory(texture1+3*y*Nic1->Bitmap->Height+3*x, &Barva, 3);
    }
  }




}
//---------------------------------------------------------------------------
void __fastcall TForm3D::FormPaint(TObject *Sender)
{
 DrawScene();
}
//---------------------------------------------------------------------------
void TForm3D::InitGL(void)
{
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.5f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

  glBindTexture(GL_TEXTURE_2D, 0);
  glTexImage2D(GL_TEXTURE_2D, 0, 3, sirka, vyska, 0, GL_RGB, GL_UNSIGNED_BYTE, textura1);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glEnable(GL_TEXTURE_2D);

	return;
}

void TForm3D::DrawScene(void)
{
  ClearMatrix(true);
  DrawFunction();
  SwapBuffers(hDC);
 	return;
}
void __fastcall TForm3D::FormCreate(TObject *Sender)
{
    hDC = GetDC(Handle);
    bSetupPixelFormat(hDC);
    hRC = wglCreateContext(hDC);
    wglMakeCurrent(hDC, hRC);
    //Angle = 0.0;
    InitGL();

}
//---------------------------------------------------------------------------
void __fastcall TForm3D::FormDestroy(TObject *Sender)
{
    // zrušení formuláøe
    wglMakeCurrent(0, 0);
    wglDeleteContext(hRC);
    ReleaseDC(Handle, hDC);

    delete textura1;
}
//---------------------------------------------------------------------------
void __fastcall TForm3D::FormResize(TObject *Sender)
{
 GLdouble gldAspect;

 gldAspect = (double) (ClientWidth-Panel1->Left-Panel1->Width)/ (double)ClientHeight;

 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluPerspective(45.0,
                gldAspect,
                0.1,         // nejbližší vzdálenost
                100.0);       // nejvzdálenìjší vzdálenost
 glViewport(Panel1->Width, 0, (ClientWidth-Panel1->Width), ClientHeight);

 glMatrixMode(GL_MODELVIEW);

 Invalidate();
}
//---------------------------------------------------------------------------

void __fastcall TForm3D::Splitter1CanResize(TObject *Sender, int &NewSize,
      bool &Accept)
{
FormResize(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm3D::Timer1Timer(TObject *Sender)
{
rot++;
DrawScene();
}
//---------------------------------------------------------------------------


void TForm3D::ClearMatrix(bool range)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearDepth(1.0f);
	glLoadIdentity();

  glTranslatef(-12.0f,11.0f,-30.0f);
  glRotatef(rot, 1, 0, 0);
	// nastavi barvu textu
	// nastavi pozici textu
  glColor4f(1,1,1, 0);
  glBegin(GL_POLYGON);
  glTexCoord2f(0.0f, 0.0f); glVertex3f(-1,-1, 0);
  glTexCoord2f(1.0f, 0.0f); glVertex3f(1,-1, 0);
  glTexCoord2f(1.0f, 1.0f); glVertex3f(1,1, 0);
  glTexCoord2f(0.0f, 1.0f); glVertex3f(-1,1, 0);
  glEnd();

    // nakreslit obdelnik pro rozsah

  glLoadIdentity();
  glTranslatef(0.0f,0.0f,-7.0f);
  glRotatef(25, 0, 1, 0);
  glRotatef(rot, 0, 1, 0);
  glRotatef(90, -1, 0, 0);

  glColor4f(0,0,0, 0);

		// Front Face
  glBegin(GL_LINE_LOOP);
    glVertex3f(1.0f*x1, 1.0f*y1,  1.0f*z2);
    glVertex3f( 1.0f*x2, 1.0f*y1,  1.0f*z2);
    glVertex3f( 1.0f*x2, 1.0f*y2,  1.0f*z2);
    glVertex3f(1.0f*x1, 1.0f*y2,  1.0f*z2);
 	glEnd();
		// Back Face
  glBegin(GL_LINE_LOOP);
    glVertex3f(1.0f*x1, 1.0f*y1,  1.0f*z1);
    glVertex3f( 1.0f*x2, 1.0f*y1,  1.0f*z1);
    glVertex3f( 1.0f*x2, 1.0f*y2,  1.0f*z1);
    glVertex3f(1.0f*x1, 1.0f*y2,  1.0f*z1);
 	glEnd();


		// Top Face
  glBegin(GL_LINE_LOOP);
    glVertex3f(1.0f*x1,  1.0f*y2, 1.0f*z1);
    glVertex3f(1.0f*x1,  1.0f*y2, 1.0f*z2);
    glVertex3f( 1.0f*x2,  1.0f*y2, 1.0f*z2);
    glVertex3f( 1.0f*x2,  1.0f*y2, 1.0f*z1);
  glEnd();

  glBegin(GL_LINE_LOOP);
    glVertex3f(1.0f*x1,  1.0f*y1, 1.0f*z1);
    glVertex3f(1.0f*x1,  1.0f*y1,  1.0f*z2);
    glVertex3f( 1.0f*x2,  1.0f*y1,  1.0f*z2);
    glVertex3f( 1.0f*x2,  1.0f*y1, 1.0f*z1);
  glEnd();

  //SwapBuffers(hDC);


}
void TForm3D::DrawFunction(void)
{
  double z = 0;
  double q = 1;
  int status = 0;
  int funkce = 3;

   // dosadit do promene hodnotu
 EditExp1->VarGrid = Form1->StringGrid1;
 EditExp1->UseVar  = true;
 Form1->StringGrid1->Cells[1][1] = "X";
 Form1->StringGrid1->Cells[1][2] = "Y";
 Form1->StringGrid1->Cells[2][1] = 0;
 Form1->StringGrid1->Cells[2][2] = 0;

	glBegin(GL_POINTS);
    for (double y = y1; y < y2; y += step) {
      q = 0;
      for (double x = x1; x < x2; x += step) {
        q+=0.001;
        glColor3f(z-0.3,0.1f, 0.4);
        AnsiString Cislo = (AnsiString) (x);
        int pocet = 0;

        if ((pocet = Cislo.LastDelimiter(",")) != NULL)
          Cislo[pocet] = '.';
        Form1->StringGrid1->Cells[2][1] = Cislo;
        Cislo = (AnsiString) (y);
        pocet = 0;
        if ((pocet = Cislo.LastDelimiter(",")) != NULL)
          Cislo[pocet] = '.';
        Form1->StringGrid1->Cells[2][2] = Cislo;
        z = EditExp1->Value;
        //z = sin(x*y);
   	    glVertex3f(x , y, z);			// Top Of Triangle (Front)
      }
    }
	glEnd();

}
void __fastcall TForm3D::FormShow(TObject *Sender)
{
  step = EditKROK->Text.ToDouble();
  x1 = Edit1->Text.ToDouble();
  x2 = Edit3->Text.ToDouble();
  y1 = Edit2->Text.ToDouble();
  y2 = Edit4->Text.ToDouble();
  z1 = Edit5->Text.ToDouble();
  z2 = Edit6->Text.ToDouble();
}
//---------------------------------------------------------------------------

void __fastcall TForm3D::LbSpeedButton2Click(TObject *Sender)
{
  step = EditKROK->Text.ToDouble();
  x1 = Edit1->Text.ToDouble();
  x2 = Edit3->Text.ToDouble();
  y1 = Edit2->Text.ToDouble();
  y2 = Edit4->Text.ToDouble();
  z1 = Edit5->Text.ToDouble();
  z2 = Edit6->Text.ToDouble();
}
//---------------------------------------------------------------------------

