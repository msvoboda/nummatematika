object NumMat: TNumMat
  Left = 125
  Top = 136
  BorderStyle = bsToolWindow
  Caption = 'Numerick'#225' matematika'
  ClientHeight = 331
  ClientWidth = 152
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object LbSpeedButton2: TLbSpeedButton
    Left = 36
    Top = 288
    Width = 81
    Height = 23
    Alignment = taCenter
    Caption = 'Barva'
    Style = bsModern
    OnClick = LbSpeedButton2Click
  end
  object GroupBox1: TGroupBox
    Left = 1
    Top = 0
    Width = 148
    Height = 281
    Caption = 'Metody integrace'
    TabOrder = 0
    object LbSpeedButton1: TLbSpeedButton
      Left = 9
      Top = 20
      Width = 123
      Height = 23
      Alignment = taCenter
      Caption = 'Obdeln'#237'kov'#225' metoda'
      ShadowColor = clInfoText
      Style = bsModern
      OnClick = LbSpeedButton1Click
    end
    object Label1: TLabel
      Left = 15
      Top = 85
      Width = 3
      Height = 13
    end
    object LbSpeedButton3: TLbSpeedButton
      Left = 9
      Top = 46
      Width = 124
      Height = 23
      Alignment = taCenter
      Caption = 'Lichob'#283#382'n'#237'kov'#225' metoda'
      Style = bsModern
      OnClick = LbSpeedButton3Click
    end
    object LbSpeedButton4: TLbSpeedButton
      Left = 9
      Top = 72
      Width = 123
      Height = 23
      Alignment = taCenter
      Caption = 'Simpsonova metoda'
      Style = bsModern
      OnClick = LbSpeedButton4Click
    end
    object EditResult: TLabeledEdit
      Left = 8
      Top = 252
      Width = 124
      Height = 21
      EditLabel.Width = 43
      EditLabel.Height = 13
      EditLabel.Caption = 'V'#253'sledek'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 0
    end
    object EditPoc: TLabeledEdit
      Left = 6
      Top = 128
      Width = 124
      Height = 21
      EditLabel.Width = 40
      EditLabel.Height = 13
      EditLabel.Caption = 'Po'#269#225'tek'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 1
      Text = '0'
    end
    object EditKon: TLabeledEdit
      Left = 7
      Top = 168
      Width = 124
      Height = 21
      EditLabel.Width = 31
      EditLabel.Height = 13
      EditLabel.Caption = 'Konec'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 2
      Text = '5'
    end
    object EditStep: TLabeledEdit
      Left = 6
      Top = 209
      Width = 124
      Height = 21
      EditLabel.Width = 22
      EditLabel.Height = 13
      EditLabel.Caption = 'Krok'
      LabelPosition = lpAbove
      LabelSpacing = 3
      TabOrder = 3
      Text = '0,2'
    end
  end
  object Panel1: TPanel
    Left = 2
    Top = 291
    Width = 26
    Height = 21
    TabOrder = 1
  end
  object CheckEXCEL: TCheckBox
    Left = 5
    Top = 315
    Width = 97
    Height = 17
    Caption = 'data do EXCELU'
    TabOrder = 2
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 112
    Top = 6
  end
end
