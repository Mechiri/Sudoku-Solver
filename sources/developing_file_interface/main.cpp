#include"inputfile.h"
#include"outputfile.h"
#include<iostream>
#include<exception>
#include"sudoku_error.h"

using namespace std;

void display(int m[9][9])
{
	cout<<"The matrix contains:"<<endl;
	
	for(int i=0; i<9; i++)
	{
		cout<<endl;
		for(int j=0; j<9; j++)
			cout<<*(*(m+i)+j)<<" ";
	}
}

int main(int argc, char* argv[])
{
	set_terminate(sudoku_terminate);
	int matrix[9][9];
	
	inputfile input;
	
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			matrix[i][j] = input.get_integer();

	outputfile output;
	output.write_sudoku_input(matrix);
	output.write_sudoku_result(matrix);
	display(matrix);
	cout<<endl;
}