//---------------------------------------------------------------------------

#ifndef derivaceH
#define derivaceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LbSpeedButton.hpp"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TNumDeriv : public TForm
{
__published:	// IDE-managed Components
        TLbSpeedButton *LbSpeedButton1;
  TLabeledEdit *EditPoc;
  TLabeledEdit *EditKon;
  TLabeledEdit *EditStep;
  TLabeledEdit *EditResult;
  TLabel *Label1;
  TCheckBox *CheckEXCEL;
  TLbSpeedButton *LbSpeedButton2;
  TLbSpeedButton *LbSpeedButton3;
  TLbSpeedButton *LbSpeedButton4;
  TLabel *Label2;
  TLbSpeedButton *LbSpeedButton5;
  TLbSpeedButton *LbSpeedButton6;
  TPanel *Panel1;
  TLbSpeedButton *LbSpeedButton7;
  TColorDialog *ColorDialog1;
  void __fastcall LbSpeedButton1Click(TObject *Sender);
  void __fastcall LbSpeedButton2Click(TObject *Sender);
  void __fastcall LbSpeedButton3Click(TObject *Sender);
  void __fastcall LbSpeedButton4Click(TObject *Sender);
  void __fastcall LbSpeedButton5Click(TObject *Sender);
  void __fastcall LbSpeedButton6Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall LbSpeedButton7Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TNumDeriv(TComponent* Owner);
  void Deriv2Point(double start, double stop, double step);
  double myFunkce(double t);
  void Deriv3Point(double start, double stop, double step);
  void Deriv4Point(double start, double stop, double step);
  void Deriv5Point(double start, double stop, double step);
  void SecDeriv3Point(double start, double stop, double step);
  void SecDeriv4Point(double start, double stop, double step);
};
//---------------------------------------------------------------------------
extern PACKAGE TNumDeriv *NumDeriv;
//---------------------------------------------------------------------------
#endif
