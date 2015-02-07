//---------------------------------------------------------------------------

#ifndef NumerikaH
#define NumerikaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LbSpeedButton.hpp"
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TNumMat : public TForm
{
__published:	// IDE-managed Components
  TGroupBox *GroupBox1;
  TLbSpeedButton *LbSpeedButton1;
  TLabeledEdit *EditResult;
  TLabel *Label1;
  TLabeledEdit *EditPoc;
  TLabeledEdit *EditKon;
  TColorDialog *ColorDialog1;
  TPanel *Panel1;
  TLbSpeedButton *LbSpeedButton2;
  TLabeledEdit *EditStep;
  TLbSpeedButton *LbSpeedButton3;
  TLbSpeedButton *LbSpeedButton4;
  TCheckBox *CheckEXCEL;
  void __fastcall LbSpeedButton1Click(TObject *Sender);
  void __fastcall LbSpeedButton2Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
  void __fastcall LbSpeedButton3Click(TObject *Sender);
  void __fastcall LbSpeedButton4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TNumMat(TComponent* Owner);
  double Lichobeznikova(double start, double stop, double step);
  double Obdelnikova(double start, double stop, double step);
  double myFunkce(double t);
  double Simpsonova(double start, double stop, double step);
  
};
//---------------------------------------------------------------------------
extern PACKAGE TNumMat *NumMat;
//---------------------------------------------------------------------------
#endif
