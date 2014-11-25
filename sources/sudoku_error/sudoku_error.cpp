/*
	Project: Sudoku
		File: sudoku_error.cpp
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#include<iostream>
#include<stdlib.h>
#include"sudoku_error.h"

using namespace std;

void sudoku_terminate()
{
	cerr<<"\n\n----------------------PROGAM TERMINATED-----------------------------"<<endl;

	exit(1);
}
