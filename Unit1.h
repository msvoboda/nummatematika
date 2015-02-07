//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Buttons.hpp>
#include "LbSpeedButton.hpp"
#include "EditExp.hpp"
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TEdit *Edit12;


	
	TComboBox *ComboBox1;
	TLabel *Label1;
	TEdit *Edit1;
	TButton *Button2;
  TLbSpeedButton *lbGraf;
  TLbSpeedButton *lbClear;
  TLbSpeedButton *lbCont;
  TLbSpeedButton *lbBod;
  TEditExp *EditExp1;
  TStringGrid *StringGrid1;
  TLabel *Label2;
  TLabel *Label3;
  TListBox *ListBox1;
  TLabel *Label4;
  TLbSpeedButton *LbSpeedButton1;
  TLbSpeedButton *LbSpeedButton2;
  TPopupMenu *PopupMenu1;
  TMenuItem *Koprovatdoschrnky1;
  TLbSpeedButton *LbSpeedButton3;
  TStaticText *StaticText1;
  TLbSpeedButton *LbSpeedButton4;
  TLbSpeedButton *LbSpeedButton5;
  TLbSpeedButton *LbSpeedButton6;
  TLbSpeedButton *lbLine;
  TLbSpeedButton *LbSpeedButton7;
  TLbSpeedButton *LbSpeedButton8;
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall SpeedButton1Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

	void __fastcall Image1MouseDown(TObject *Sender, TMouseButton Button,
	TShiftState Shift, int X, int Y);
	void __fastcall Button2Click(TObject *Sender);
  void __fastcall LbSpeedButton1Click(TObject *Sender);
  void __fastcall LbSpeedButton2Click(TObject *Sender);
  void __fastcall Koprovatdoschrnky1Click(TObject *Sender);
  void __fastcall LbSpeedButton3Click(TObject *Sender);
  void __fastcall LbSpeedButton6Click(TObject *Sender);
  void __fastcall LbSpeedButton4Click(TObject *Sender);
  void __fastcall lbLineClick(TObject *Sender);
  void __fastcall LbSpeedButton7Click(TObject *Sender);
  void __fastcall LbSpeedButton5Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	virtual __fastcall TForm1(TComponent* Owner);
  float x_absolut(float realx);
  float y_absolut(float realy);
  bool about;
  float x1,x2, y1, y2;
};
//---------------------------------------------------------------------------
extern TForm1 *Form1;
extern float Unit_X, Unit_Y;
extern float O[2];
extern BOOL POPISEK;

//---------------------------------------------------------------------------


#endif
