object frmNomeDiretorio: TfrmNomeDiretorio
  Left = 0
  Top = 0
  Caption = 'Nome do Diret'#243'rio'
  ClientHeight = 174
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 128
    Width = 87
    Height = 13
    Caption = 'Tamanho M'#225'ximo:'
  end
  object Label2: TLabel
    Left = 96
    Top = 8
    Width = 471
    Height = 35
    Caption = 'Digite um nome para o diret'#243'rio'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold]
    ParentFont = False
  end
  object lblTamanhoMaximo: TLabel
    Left = 112
    Top = 128
    Width = 3
    Height = 13
  end
  object Label3: TLabel
    Left = 256
    Top = 128
    Width = 95
    Height = 13
    Caption = 'Tamanho restante: '
  end
  object lblTamanhoRestante: TLabel
    Left = 357
    Top = 128
    Width = 3
    Height = 13
  end
  object Edit1: TEdit
    Left = 8
    Top = 59
    Width = 619
    Height = 21
    TabOrder = 0
  end
  object Button1: TButton
    Left = 8
    Top = 86
    Width = 619
    Height = 25
    Caption = 'Criar diret'#243'rio'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Timer1: TTimer
    Enabled = False
    OnTimer = Timer1Timer
    Left = 504
    Top = 128
  end
end
