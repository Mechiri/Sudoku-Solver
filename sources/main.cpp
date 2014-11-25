/*
	Project: Sudoku
		File: main.cpp
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#include"sudoku.h"
#include<iostream>
#include<time.h>
#include<exception>
#include"sudoku_error.h"


using namespace std;

int main()
{
	set_terminate(sudoku_terminate); // setting global error function
	
	sudoku sudoku1;
	clock_t time;
	float total_time_taken;
	
	if(sudoku1.total_empty_spaces)
	{
		time=clock();
		sudoku1.solve();
		time=clock()-time;
		total_time_taken = ((float)time)/CLOCKS_PER_SEC;
	}
	else
		sudoku1.display();
	
	sudoku1.display_sudoku_details(total_time_taken);
	cout<<"YOUR SUDOKU PROBLEM SOLVED\nYOU CAN SEE INPUT AND OUTPUT IN \"./sudoku input & output\""<<endl;
	return 1;
}
