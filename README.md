INTRODUCTION
------------
	
	This project is of an interactive command line utility that provides the ability to modify and 
	examine the memory and also provides basic memory test functionality.

PROJECT FOLDER
--------------

	Interactive Memory Utility
		|
		|- utils
		....|- include
		........|- help.h
		........|- memalloc.h
		........|- memDisplay.h
		........|- memwrite.h
		........|- xorinvert.h
		........|- writepattern.h
		........|- verifypattern.h
		........|- exit.h
		........|- global.h
		....|- src
		........|- help.c
		........|- memalloc.c
		........|- memDisplay.c
		........|- memwrite.c
		........|- xorinvert.c
		........|- writepattern.c
		........|- verifypattern.c
		........|- exit.c
		........|- global.c
		|- UnitTests
		....|- util_test.c
		....|- Makefile
		|- main.c
		|- Makefile
		|- test.txt
		|- README.md


BUILD and RUN STEPS
-------------------

	This project only supports Linux development environment. The following section covers in detail on 
	how to build and run the program

	Note:- The build system for this project uses GNU MAKE utility.


	PROJECT BUILD STEPS  
	===================
	1.) Go to the project folder, cd [FolderName]/  
	2.) Run make (This command compiles the code and generates an respective executable)
	3.) Run make test (This command compiles the code,  generates the executabtable and runs the code using the test script)

	RUN STEPS  
	=========  
	1.) ./main

	UNIT TEST RUN STEPS
	===================
	1.) First install all the Unit-test dependency using the command - sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
	2.) Go to the UnitTests folder using the command - cd UnitTests
	3.) Run make
	4.) ./unittest

LIST OF MEMORY MANIPULATION COMMANDS
------------------------------------

	The following section illustrates in detail how the main program works on each user command.

	The supported used commands include:

	Note :- All the input and output data to the utility command should be in hexadecimal format

	allocate [N blocks] - This command is used to dynamically allocate memory according to the user entered number of blocks.

	free - Frees the dynamically allocated memory.

	read [flag] [arg] [N block size] - This command is used to read data starting from a user specified address until the user specified block size.

	write [flag] [arg] [data] - This command is used to write data at a user specified memory address.

	invert [flag] [arg] [N block size] - This command is used to invert the memory contents starting from the user specified address until the user specified number of blocks.

	wpattern [flag] [arg] [N block size] [seed] - This command is used to write pseudo random numbers starting at the user specified address until the user specified block size.

	vpattern [flag] [arg] [N block size] [seed] - This command is used to verify the pseudo random numbers starting at the user specified address until the user specified block size.

	exit - Close the program

	[flag] --> '-a- to specify address and '-b' to specify offset
	[arg] --> Address if '-a' is flag and Offset value if '-b' is flag
