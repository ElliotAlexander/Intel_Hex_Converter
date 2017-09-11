Func Common_Run_Program($Input_Script, $Output_Box)
   $Output_Box_Data = GUICtrlRead($Output_Box)
   ;; A null output box is fine.
   if($Input_Script == Null) Then
	  Common_WriteLine("Error - Script name null")
	  Return
   EndIf


   $foo = Run(@ComSpec & " /c dir" + $Input_Stript, "", @SW_HIDE, $STDOUT_CHILD + $STDIN_CHILD);

   While($foo)
	  $Output_Box_Data_Edit = StdoutRead($foo)
	  Common_WriteLine($Output_Box_Data_Edit, $Output_Box)

	  If(@error) Then
		 Common_WriteLine("Error! Problem running script " + $Input_Script, $Output_Box)
		 Break
	  EndIf

   WEnd
EndFunc

Func Common_WriteLine($String, $Output_Box)
   $Output_Box_Data = GUICtrlRead($Output_Box)
   $Output_Box_Data = $Output_Box_Data & $String & @CRLF
   GUICtrlSetData($Output_Box, $Output_Box_Data)
EndFunc