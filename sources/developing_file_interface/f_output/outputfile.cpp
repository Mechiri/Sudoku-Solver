#include<iostream>
#include"outputfile.h"
#include"sudoku_error.h"

using namespace std;

outputfile::outputfile()
{
	ofile.open("output.txt");
	if( !ofile.is_open() )
	{
		cerr<<"\nError: In opening the file input.txt\n";
		throw;
	}
}

outputfile::~outputfile()
{
	if( !(ofile.rdstate()) )
	{
		ofile.close();
		if( ofile.fail() )
		{
			cerr<<"Error: In closing the file input.txt";
			throw;
		}
	}
	else
	{
		cerr<<"The ofstream object is not in good state for closing the file\n"<<endl;
		throw;
	}
}
		
void outputfile::write_sudoku_result(int sudoku_matrix[9][9])
{
	ofile<<"The result of sudoku:"<<endl;
	write_file(sudoku_matrix);	
}

void outputfile::write_sudoku_input(int sudoku_matrix[9][9])
{
	ofile<<"The sudoku input:"<<endl;
	write_file(sudoku_matrix);
}

void outputfile::write_file(int sudoku_matrix[9][9])
{
	for(int row = 0; row < 9; row++)
	{
		ofile<<"\t";
		for(int col = 0; col < 9; col++)
		{
			char str[3];
			str[0] = ' ';
			str[1] = sudoku_matrix[row][col]-0+'0';
			str[2] = '\0';
			
			ofile.write(str,2);
			if(ofile.rdstate())
			{
				cerr<<"Error: In writng the charchter in output.txt";
				throw;
			}
		}
		ofile<<endl;
	}
	ofile<<endl<<endl;
}
