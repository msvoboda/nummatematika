//---------------------------------------------------------------------------
#ifndef Bezier_u1H
#define Bezier_u1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TBezierCurve : public TForm
{
__published:	// IDE-managed Components
    TButton *StartBtn;
    TImage *Img;
  TListBox *ListBox1;
  TButton *Button1;
  TEdit *Edit1;
  TLabel *Label1;
  TLabel *Label2;
  TEdit *Edit2;
  TButton *Button2;
  TButton *Button3;
    void __fastcall ExitBtnClick(TObject *Sender);
    void __fastcall StartBtnClick(TObject *Sender);
  void __fastcall Button1Click(TObject *Sender);
  void __fastcall ImgMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
  void __fastcall Button2Click(TObject *Sender);
  void __fastcall ListBox1Click(TObject *Sender);
  void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TBezierCurve(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBezierCurve *BezierCurve;
//---------------------------------------------------------------------------
#endif
