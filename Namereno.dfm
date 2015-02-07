object FormData: TFormData
  Left = 157
  Top = 169
  BorderStyle = bsToolWindow
  Caption = 'Nam'#283#345'n'#225' data'
  ClientHeight = 377
  ClientWidth = 137
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 4
    Top = 4
    Width = 32
    Height = 13
    Caption = #344#225'dek'
  end
  object Label2: TLabel
    Left = 3
    Top = 42
    Width = 39
    Height = 13
    Caption = 'Sloupec'
  end
  object Label3: TLabel
    Left = 4
    Top = 80
    Width = 64
    Height = 13
    Caption = 'Po'#269'et hodnot'
  end
  object Label4: TLabel
    Left = 5
    Top = 182
    Width = 57
    Height = 13
    Caption = 'Tabulka dat'
  end
  object LbSpeedButton1: TLbSpeedButton
    Left = 8
    Top = 346
    Width = 100
    Height = 23
    Alignment = taCenter
    Caption = 'GRAF y = f(x)'
    Style = bsModern
    OnClick = LbSpeedButton1Click
  end
  object LbSpeedButton2: TLbSpeedButton
    Left = 7
    Top = 123
    Width = 100
    Height = 23
    Alignment = taCenter
    Caption = 'Import dat'
    Style = bsModern
    OnClick = LbSpeedButton2Click
  end
  object LbSpeedButton3: TLbSpeedButton
    Left = 8
    Top = 153
    Width = 100
    Height = 23
    Alignment = taCenter
    Caption = 'Ze souboru  CVS'
    Style = bsModern
    OnClick = LbSpeedButton3Click
  end
  object StringGrid1: TStringGrid
    Left = 4
    Top = 199
    Width = 131
    Height = 140
    ColCount = 2
    DefaultColWidth = 50
    DefaultRowHeight = 16
    FixedCols = 0
    FixedRows = 0
    TabOrder = 0
  end
  object Edit1: TEdit
    Left = 6
    Top = 18
    Width = 101
    Height = 21
    TabOrder = 1
    Text = '1'
  end
  object Edit2: TEdit
    Left = 6
    Top = 56
    Width = 102
    Height = 21
    TabOrder = 2
    Text = '1'
  end
  object EditCount: TEdit
    Left = 6
    Top = 95
    Width = 102
    Height = 21
    TabOrder = 3
    Text = '50'
  end
  object OpenDialog1: TOpenDialog
    Filter = 'CSV (Excel)|*.csv'
    Left = 80
    Top = 8
  end
end
