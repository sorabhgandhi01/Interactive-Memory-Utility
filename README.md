INTRODUCTION
------------
	
	This project is of an interactive command line utility that provides the ability to modify and 
	examine the memory and also provides basic memory test functionality.

BUILD and RUN STEPS
-------------------

	This project only supports Linux development environment. The following section covers in detail on 
	how to build and run the program

	Note:- The build system for this project uses GNU MAKE utility.


	PROJECT BUILD STEPS  
	===================  
	1.) Go to the project folder, cd [FolderName]/  
	2.) Run make (This command compiles the code and generates an respective executable)

	RUN STEPS  
	=========  
	1.) ./main

LIST OF MEMORY MANIPULATION COMMANDS
------------------------------------

	The following section illustrates in detail how the main program works on each user command.

	The supported used commands include:

	allocate [block_size] - This command is used to dynamically allocate memory according to the user entered number of blocks.

	free - Frees the dynamically allocated memory.

	read [address] [block_size] - This command is used to read data starting from a user specified address until the user specified block size.

	write [address] [data] - This command is used to write data at a user specified memory address.

	invert [address] [block_size] - This command is used to invert the memory contents starting from the user specified address until the user specified number of blocks.

	wpattern [address] [block_size] [seed] - This command is used to write pseudo random numbers starting at the user specified address until the user specified block size.

	vpattern [address] [block_size] [seed] - This command is used to verify the pseudo random numbers starting at the user specified address until the user specified block size.

	exit - Close the program
