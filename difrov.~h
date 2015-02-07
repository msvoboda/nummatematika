//---------------------------------------------------------------------------

#ifndef difrovH
#define difrovH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "LbSpeedButton.hpp"
#include <Dialogs.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFormDR : public TForm
{
__published:	// IDE-managed Components
  TLabel *Label1;
  TEdit *EditT1;
  TLabel *Label2;
  TEdit *EditT2;
  TLabel *Label3;
  TEdit *EditK;
  TLabel *Label4;
  TEdit *EditStep;
  TLabel *Label5;
  TLabel *Label6;
  TEdit *EditU;
  TLabel *Label7;
  TEdit *EditY0;
  TLabel *Label8;
  TEdit *EditZ0;
  TLbSpeedButton *LbSpeedButton1;
  TLbSpeedButton *LbSpeedButton2;
  TLbSpeedButton *LbSpeedButton3;
  TEdit *EditAlfa;
  TPanel *Panel1;
  TPanel *Panel2;
  TColorDialog *ColorDialog1;
  TLabel *Label9;
  TEdit *EditKROK;
  TLbSpeedButton *LbSpeedButton4;
  TLbSpeedButton *LbSpeedButton5;
  TLbSpeedButton *LbSpeedButton6;
  void __fastcall LbSpeedButton1Click(TObject *Sender);
  void __fastcall Panel1Click(TObject *Sender);
  void __fastcall Panel2Click(TObject *Sender);
  void __fastcall LbSpeedButton3Click(TObject *Sender);
  void __fastcall LbSpeedButton4Click(TObject *Sender);
  void __fastcall LbSpeedButton5Click(TObject *Sender);
  void __fastcall LbSpeedButton2Click(TObject *Sender);
  void __fastcall LbSpeedButton6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TFormDR(TComponent* Owner);
  zFunkce(double y0, double z0, double u, double T1, double T2, double K, double step);
  void RK2Funkce(double y0, double z0, double u, double T1, double T2, double K, double step, double alfa);
  void RK4Funkce(double y0, double z0, double u, double T1, double T2, double K, double step);
  void Heunova(double y0, double z0, double u, double T1, double T2, double K, double step);
  void Nystrom(double y0, double z0, double u, double T1, double T2, double K, double step);
  void PredKor(double y0, double z0, double u, double T1, double T2, double K, double h, double alfa);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormDR *FormDR;
//---------------------------------------------------------------------------
#endif
