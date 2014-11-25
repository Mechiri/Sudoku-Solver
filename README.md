Sudoku-Solver
=============

CONTENTS
--------
Project Description
Project Output
How to execute and check the output
My Details

Project Description
-------------------
I think everybody knows Sudoku. This is small and simple project which takes incomplete sudoku matrix and gives one or more complete sudoku matrix. In addition it provides number of complete sudoku generated and time taken to solve the sudoku. This sudoku solver solves the sudoku almost like human i.e.,first it identifies and fills empty spaces which have only one possible values and it repeats untill it doesn't contain empty spaces which have only one possible values. Then it fills empty spaces which have more than one possible values increasingly. Below shows sample project output.

Project Output
--------------
The output is written in the file output.txt, which is located in "sudoku input & output" folder.
The path is:  ./sudoku\ input\ \&\ output/output.txt"

THE ENTERED SUDOKU IS:

The sudoku input:
	 0 8 0 0 0 9 7 4 3
	 0 5 0 0 0 8 0 1 0
	 0 1 0 0 0 0 0 0 0
	 8 0 0 0 0 5 0 0 0
	 0 0 0 8 0 4 0 0 0
	 0 0 0 3 0 0 0 0 6
	 0 0 0 0 0 0 0 7 0
	 0 3 0 5 0 0 0 8 0
	 9 7 2 4 0 0 0 5 0


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 4 7 6 8 9 1 2
	 7 1 9 2 4 3 5 6 8
	 8 2 3 6 1 5 4 9 7
	 6 9 7 8 2 4 1 3 5
	 1 4 5 3 9 7 8 2 6
	 5 6 8 9 3 1 2 7 4
	 4 3 1 5 7 2 6 8 9
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 7 6 4 8 9 1 2
	 4 1 9 7 3 2 5 6 8
	 8 9 1 2 6 5 4 3 7
	 6 2 3 8 7 4 1 9 5
	 7 4 5 3 9 1 8 2 6
	 5 6 8 9 1 3 2 7 4
	 1 3 4 5 2 7 6 8 9
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 4 5 7 6 3 8 9 1 2
	 3 1 9 7 4 2 5 6 8
	 8 9 1 2 6 5 4 3 7
	 6 2 3 8 7 4 1 9 5
	 7 4 5 3 9 1 8 2 6
	 5 6 8 9 1 3 2 7 4
	 1 3 4 5 2 7 6 8 9
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 4 7 6 8 9 1 2
	 7 1 9 2 4 3 5 6 8
	 8 9 3 6 1 5 4 2 7
	 6 2 7 8 9 4 1 3 5
	 1 4 5 3 7 2 8 9 6
	 5 6 8 9 3 1 2 7 4
	 4 3 1 5 2 7 6 8 9
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 4 7 6 8 9 1 2
	 7 1 9 2 4 3 5 6 8
	 8 9 3 6 1 5 4 2 7
	 6 2 7 8 9 4 1 3 5
	 1 4 5 3 2 7 8 9 6
	 5 6 8 9 3 1 2 7 4
	 4 3 1 5 7 2 6 8 9
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 7 6 4 8 2 1 9
	 4 1 9 7 3 2 5 6 8
	 8 2 1 9 6 5 4 3 7
	 6 9 3 8 7 4 1 2 5
	 7 4 5 3 2 1 8 9 6
	 5 6 8 2 1 3 9 7 4
	 1 3 4 5 9 7 6 8 2
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 4 5 7 6 3 8 2 1 9
	 3 1 9 7 4 2 5 6 8
	 8 2 1 9 6 5 4 3 7
	 6 9 3 8 7 4 1 2 5
	 7 4 5 3 2 1 8 9 6
	 5 6 8 2 1 3 9 7 4
	 1 3 4 5 9 7 6 8 2
	 9 7 2 4 8 6 3 5 1


The complete sudoku output:
	 2 8 6 1 5 9 7 4 3
	 3 5 7 6 4 8 2 1 9
	 4 1 9 7 2 3 5 6 8
	 8 2 1 9 6 5 4 3 7
	 6 9 3 8 7 4 1 2 5
	 7 4 5 3 1 2 8 9 6
	 5 6 8 2 3 1 9 7 4
	 1 3 4 5 9 7 6 8 2
	 9 7 2 4 8 6 3 5 1


The time taken to solve the sudoko is: 0.170094sec (0.000170094 ms)

The number of sudoku results generated are: 8

                                                  BYE TAKE CARE :)                       						

How to Execute and Check the Output
-----------------------------------

Requirements
------------
 -Linux Operating System
 -vim or gedit tools
 -g++ Compiler
 -make build tool

Execution
---------

 Before Running make. Open the file input.txt loacted in folder "sudoku input & output". And write sudoku incomplete matrix in input.txt file as sample shown in Project Output. Then run make command. Now, you will see complete sudoku matrix in output.txt located in folder "sudoku input & output".

My Details
----------
If you have any Questions. Please email to me.

Name: Mechiri Vinod Kumar
-----
Email: mvk046@gmail.com
------
