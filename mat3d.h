//---------------------------------------------------------------------------
#ifndef mat3dH
#define mat3dH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "EditExp.hpp"
#include "LbSpeedButton.hpp"
//---------------------------------------------------------------------------
class TForm3D : public TForm
{
__published:	// IDE-managed Components
  TPanel *Panel1;
  TSplitter *Splitter1;
  TEditExp *EditExp1;
  TLabel *Label1;
  TLbSpeedButton *LbSpeedButton1;
  TTimer *Timer1;
  TEdit *Edit1;
  TEdit *Edit2;
  TEdit *Edit3;
  TEdit *Edit4;
  TEdit *Edit5;
  TEdit *Edit6;
  TLbSpeedButton *LbSpeedButton2;
  TLabel *Label2;
  TEdit *EditKROK;
  TStaticText *StaticText1;
  TLabel *Label3;
  TLabel *Label4;
  TLabel *Label5;
  TLabel *Label6;
  TLabel *Label7;
  TLabel *Label8;
  TComboBox *ComboBox1;
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall Splitter1CanResize(TObject *Sender, int &NewSize,
          bool &Accept);
  void __fastcall Timer1Timer(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall LbSpeedButton2Click(TObject *Sender);
private:	// User declarations
    HDC hDC;
    HGLRC hRC;
public:		// User declarations
  __fastcall TForm3D(TComponent* Owner);
  void TForm3D::DrawScene(void);
  void TForm3D::InitGL(void);
  int rot;
  void ClearMatrix(bool range);
  void DrawFunction(void);

  float x1, x2, y1, y2, z1, z2;
  float step;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3D *Form3D;
//---------------------------------------------------------------------------
#endif
