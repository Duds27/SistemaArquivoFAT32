object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  Caption = 'Gerenciador de Arquivos Facens - V1.0'
  ClientHeight = 574
  ClientWidth = 826
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  KeyPreview = True
  Menu = MainMenu1
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 189
    Top = 447
    Width = 636
    Height = 105
    Caption = 'Propriedades do Arquivo'
    Color = clSkyBlue
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
    object Label1: TLabel
      Left = 5
      Top = 26
      Width = 32
      Height = 14
      Caption = 'Nome'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label2: TLabel
      Left = 5
      Top = 46
      Width = 50
      Height = 14
      Caption = 'Tamanho'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 5
      Top = 66
      Width = 84
      Height = 14
      Caption = 'Data de Cria'#231#227'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label4: TLabel
      Left = 5
      Top = 86
      Width = 108
      Height = 14
      Caption = 'Data de Modifica'#231#227'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 555
    Width = 826
    Height = 19
    Color = clDefault
    Panels = <
      item
        Alignment = taCenter
        Width = 100
      end
      item
        Alignment = taCenter
        Text = 'Sistema de Arquivos'
        Width = 600
      end
      item
        Alignment = taCenter
        Width = 100
      end>
  end
  object GroupBox3: TGroupBox
    Left = 189
    Top = 0
    Width = 636
    Height = 35
    Color = clSkyBlue
    ParentBackground = False
    ParentColor = False
    TabOrder = 2
    object Edit1: TEdit
      Left = 5
      Top = 7
      Width = 622
      Height = 21
      TabOrder = 0
    end
  end
  object TreeView1: TTreeView
    Left = 3
    Top = 1
    Width = 182
    Height = 551
    Indent = 19
    TabOrder = 3
  end
  object StringGrid1: TStringGrid
    Left = 189
    Top = 40
    Width = 634
    Height = 401
    ColCount = 2
    DefaultColWidth = 100
    FixedColor = clGradientActiveCaption
    FixedCols = 0
    GridLineWidth = 0
    TabOrder = 4
  end
  object MainMenu1: TMainMenu
    Left = 24
    Top = 8
    object Arquivo1: TMenuItem
      Caption = '&Arquivo'
    end
    object Editar1: TMenuItem
      Caption = '&Editar'
    end
    object Exibir1: TMenuItem
      Caption = 'E&xibir'
    end
    object Ferramentas1: TMenuItem
      Caption = 'Fe&rramentas'
    end
    object Sobre1: TMenuItem
      Caption = 'Sobre'
      object Autores1: TMenuItem
        Caption = 'Au&tores'
        OnClick = Autores1Click
      end
      object Verso1: TMenuItem
        Caption = 'Ver&s'#227'o'
      end
    end
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 784
    Top = 8
  end
end
