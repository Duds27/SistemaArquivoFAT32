object Form1: TForm1
  Left = 0
  Top = 0
  AutoSize = True
  Caption = 'Gerenciador de Arquivos Facens - V1.0'
  ClientHeight = 763
  ClientWidth = 1306
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
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 290
    Top = 615
    Width = 1016
    Height = 126
    Caption = 'Propriedades do Arquivo'
    Color = clGradientActiveCaption
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
    Top = 744
    Width = 1306
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
    Left = 290
    Top = 1
    Width = 1016
    Height = 41
    Color = clSkyBlue
    ParentBackground = False
    ParentColor = False
    TabOrder = 2
    object edtPathname: TEdit
      Left = 5
      Top = 7
      Width = 1003
      Height = 21
      TabOrder = 0
    end
  end
  object TreeView1: TTreeView
    Left = 3
    Top = 0
    Width = 286
    Height = 741
    Color = clWhite
    Indent = 19
    TabOrder = 3
    OnMouseDown = TreeView1MouseDown
  end
  object StringGrid1: TStringGrid
    Left = 290
    Top = 43
    Width = 1016
    Height = 570
    ColCount = 2
    DefaultColWidth = 100
    FixedColor = clGradientActiveCaption
    FixedCols = 0
    FixedRows = 0
    GridLineWidth = 0
    TabOrder = 4
    OnMouseDown = StringGrid1MouseDown
  end
  object Button1: TButton
    Left = 600
    Top = 384
    Width = 75
    Height = 25
    Caption = 'gera Tree'
    TabOrder = 5
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 736
    Top = 272
    Width = 75
    Height = 25
    Caption = 'ler nodes'
    TabOrder = 6
    OnClick = Button2Click
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
    Enabled = False
    OnTimer = Timer1Timer
    Left = 1152
    Top = 328
  end
  object OpenDialog1: TOpenDialog
    Left = 344
    Top = 504
  end
  object PopupMenuGrid: TPopupMenu
    MenuAnimation = [maRightToLeft]
    Left = 112
    Top = 8
    object Criar1: TMenuItem
      Caption = 'Criar'
      OnClick = Criar1Click
    end
    object Alterar1: TMenuItem
      Caption = 'Alterar'
    end
    object Deletar1: TMenuItem
      Caption = 'Deletar'
    end
  end
  object PopupTreeView: TPopupMenu
    Left = 112
    Top = 72
    object Criardiretorio1: TMenuItem
      Caption = 'Criar diret'#243'rio'
      OnClick = Criardiretorio1Click
    end
    object Criararquivo1: TMenuItem
      Caption = 'Criar arquivo'
    end
  end
end
