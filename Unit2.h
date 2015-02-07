//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include "LbSpeedButton.hpp"
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TEdit *Edit1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TButton *Button2;
	TCheckBox *CheckBox1;
	TBevel *Bevel1;
	TBevel *Bevel2;
	TLabel *Label5;
  TButton *Button1;
  TEdit *EditSec;
  TCheckBox *CheckSecondOsa;
  TLbSpeedButton *LbSpeedButton1;
  TColorDialog *ColorDialog1;
  TPanel *Panel1;
  TStaticText *StaticText1;
  TLabel *Label6;
  TLabel *Label7;
  TEdit *EditX;
  TEdit *EditY;
	
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
  void __fastcall CheckSecondOsaClick(TObject *Sender);
  void __fastcall LbSpeedButton1Click(TObject *Sender);
  void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	virtual __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TForm2 *Form2;
//extern BOOL POPISEK;
//---------------------------------------------------------------------------
#endif
