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

using namespace std;

int main()
{
	sudoku sudoku1;
	clock_t time;

	cout<<"THE ENTERED SUDOKU IS:\n";
	sudoku1.display();	
	
	if(sudoku1.total_empty_spaces)
	{
		time=clock();
		sudoku1.solve();
		time=clock()-time;
		cout<<"The time taken to solve the sudoko is: "<< ((float)time)/CLOCKS_PER_SEC << "sec ("<<((float)time)/CLOCKS_PER_SEC/1000<<" ms)"<<endl;
	}
	else
	{
		cout<<"Great thanks to you because you entered solved sudoku\n";
		sudoku1.display();
	}
	
	sudoku1.display_thenumber();
	cout<<endl;
}
