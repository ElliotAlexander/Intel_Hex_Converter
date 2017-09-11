#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#Region ### START Koda GUI section ### Form=c:\users\elliot\google drive\c\intel hex converter\gui\intel_hex_generator.kxf
$IntelHexGenerator = GUICreate("IntelHexGenerator", 622, 456, 191, 181)
$Intel_Hex_Generator_Title = GUICtrlCreateLabel("Intel Hex Generator", 8, 8, 282, 49)
GUICtrlSetFont(-1, 24, 400, 0, "Segoe UI")
$Input_File_Box = GUICtrlCreateInput("", 8, 96, 489, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Browse_Input_Button = GUICtrlCreateButton("Browse", 512, 96, 97, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Input_File_Label = GUICtrlCreateLabel("Input File:", 8, 72, 59, 21)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Output_File_Label = GUICtrlCreateLabel("Output File:", 8, 128, 70, 21)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Output_File_Box = GUICtrlCreateInput("", 8, 152, 489, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Browse_Output_Button = GUICtrlCreateButton("Browse", 512, 152, 97, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Generate_Button = GUICtrlCreateButton("Generate", 512, 192, 97, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Clear_Button = GUICtrlCreateButton("Clear", 400, 192, 97, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Output_Box = GUICtrlCreateEdit("", 8, 272, 601, 169, BitOR($ES_AUTOVSCROLL,$ES_AUTOHSCROLL,$ES_WANTRETURN,$WS_VSCROLL))
$Arguments_Box = GUICtrlCreateInput("", 8, 232, 601, 25)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
$Arguments_Label = GUICtrlCreateLabel("Arguments:", 8, 200, 70, 21)
GUICtrlSetFont(-1, 10, 400, 0, "Segoe UI")
GUISetState(@SW_SHOW)
#EndRegion ### END Koda GUI section ###

#include <Core_Utils.au3>
#include <FileConstants.au3>
#include <MsgBoxConstants.au3>


Const $exe_path = "Intel_Hex_Converter.exe"

$input_file = "";
$output_file = "";

While 1
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			Exit
		 Case $Browse_Input_Button
			$input_file = FileOpenDialog("Open", "", "All (*.*)", $FD_FILEMUSTEXIST)
			GUICtrlSetData($Input_File_Box, $input_file)
		 Case $Browse_Output_Button
			$output_file = FileSaveDialog("Save as", "", "Hex (.hex) || All (*.*)", $FD_PATHMUSTEXIST, "Output")
			GUICtrlSetData($Output_File_Box, $output_file)
		 Case $Generate_Button
			run_exe();
		Case $Clear_Button
		   $input_file = ""
		   $output_file = ""
		   GUICtrlSetData($Input_File_Box, "")
		   GUICtrlSetData($Output_File_Box, "")
		   GUICtrlSetData($Output_Box, "")
		 Default
	  EndSwitch
	  GUICtrlSetData($Arguments_Box, generate_arguments())
 WEnd


Func run_exe()
   $SendString = $exe_path & generate_arguments();
   Common_Run_Program($SendString, $Output_Box)
EndFunc


Func generate_arguments()
   $ArgString = ""
   if($output_file <> "") Then
	  $ArgString = $ArgString & " -O " & $output_file
   EndIf

   If($input_file <> "") Then
	  $ArgString = $ArgString & " -F " & $input_file
   EndIf

   Return $ArgString
EndFunc
