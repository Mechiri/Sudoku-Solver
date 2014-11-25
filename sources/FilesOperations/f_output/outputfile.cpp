/*
	Project: Sudoku
		File: outputfile.cpp
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#include<iostream>
#include"outputfile.h"


using namespace std;

outputfile::outputfile() throw()
{
	ofile.open("./sudoku input & output/output.txt");
	if( !ofile.is_open() )
	{
		cerr<<"\nError: In opening the file input.txt\n";
		throw;
	}
}

outputfile::~outputfile() throw()
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
		
void outputfile::write_sudoku_result(const int sudoku_matrix[9][9]) const throw() 
{
	ofile<<("The complete sudoku output:")<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for write_sudoku_result in file\n"<<endl;
		throw;
	}
	write_file(sudoku_matrix);	
}

void outputfile::write_sudoku_input(const int sudoku_matrix[9][9]) const throw() 
{
	ofile<<"THE ENTERED SUDOKU IS:"<<endl<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for write_sudoku_input in file\n"<<endl;
		throw;
	}
	ofile<<"The sudoku input:"<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for write_sudoku_input in file\n"<<endl;
		throw;
	}
	write_file(sudoku_matrix);
}

void outputfile::write_file( const int sudoku_matrix[9][9]) const throw()
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

void outputfile::write_sudoku_details(const int number_of_sudoku_results, const  float total_time) const throw()
{
	ofile<<"The time taken to solve the sudoko is: "<< total_time << "sec ("<<total_time/1000<<" ms)"<<endl<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for writing sudoku time details in file\n"<<endl;
		throw;
	}
	ofile<<"The number of sudoku results generated are: "<<number_of_sudoku_results<<endl<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for writing sudoku generated details in file\n"<<endl;
		throw;
	}
	ofile<<"                                                  BYE TAKE CARE :)                                                   "<<endl;
	if( ofile.rdstate() )
	{
		cerr<<"The ofstream object is not in good state for writing sudoku ending message in file\n"<<endl;
		throw;
	}
}
