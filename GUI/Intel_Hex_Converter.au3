#include <ButtonConstants.au3>
#include <EditConstants.au3>
#include <GUIConstantsEx.au3>
#include <StaticConstants.au3>
#include <WindowsConstants.au3>
#Region ### START Koda GUI section ### Form=c:\users\elliot\google drive\c\intel hex converter\gui\intel_hex_generator.kxf
$IntelHexGenerator = GUICreate("IntelHexGenerator", 622, 406, 191, 181)
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
$Output_Box = GUICtrlCreateEdit("", 8, 224, 601, 169, BitOR($ES_AUTOVSCROLL,$ES_AUTOHSCROLL,$ES_WANTRETURN,$WS_VSCROLL))
GUISetState(@SW_SHOW)
#EndRegion ### END Koda GUI section ###

#include <Core_Utils.au3>
#include <FileConstants.au3>
#include <MsgBoxConstants.au3>



$input_file = ""
$output_file = ""


While 1
	$nMsg = GUIGetMsg()
	Switch $nMsg
		Case $GUI_EVENT_CLOSE
			Exit
		 Case $Browse_Input_Button
			$input_file = FileOpenDialog("Select an input file", "", "All (*.*)", $FD_FILEMUSTEXIST)
			GUICtrlSetData($Input_File_Box, $input_file)
			Common_WriteLine("Using input file " & $input_file, $Output_Box)
		 Case $Browse_Output_Button
			$output_file = FileSaveDialog("Save as", "", "Hex (.hex)", $FD_PATHMUSTEXIST, "Output")
			GUICtrlSetData($Output_File_Box, $output_file)
			Common_WriteLine("Using output file " & $output_file, $Output_Box)
		Case $Generate_Button
		Case $Clear_Button
		   $input_file = ""
		   $output_file = ""
		   GUICtrlSetData($Input_File_Box, "")
		   GUICtrlSetData($Output_File_Box, "")
		   GUICtrlSetData($Output_Box, "")
	EndSwitch
 WEnd


 Func execute()
   $SendString = "

EndFunc
