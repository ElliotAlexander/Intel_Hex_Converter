## Intel Hex Generator ##


----------
.exe for generating Intel Hex Formatted files from input rows formatted as
	

    <address> [tab] <ascii text>

Only supports 16 bit addressing. Support for longer addresses (extended linear address rows) may be added in the future, but probably subject to personal need. 

<h4>Usage</h4>

    -F <input file.xxx>
    -O <outputfile.xxx>

Pass in input and output arguments. 

<h5>Additional options</h5>

    -A    // Append to end of output file. Overwrites existing files by default.


    -T    // Terminate the file with an EOF record.


    -H    // Print help text (basically this document).
