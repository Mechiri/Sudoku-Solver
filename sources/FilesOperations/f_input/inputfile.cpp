/*
	Project: Sudoku
		File: inputfile.cpp
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#include<iostream>
#include"inputfile.h"


using namespace std;

inputfile::inputfile() throw()
{
	ifile.open("./sudoku input & output/input.txt");
	if( !(ifile.is_open()) )
	{
		cerr<<"\nError: In opening the file input.txt\n\tIf input.txt is not exist in sources folder then create manually and write sudoku((9x9) in it. FIll empty space as zero"<<endl;
		
		throw;
	}
		
}

inputfile::~inputfile() throw()
{
	if( ifile.rdstate() )
	{
		cerr<<"The ifstream object is not in good state for closing the file\n"<<endl;
		throw;
	}
	else
		ifile.close();
	if( ifile.fail() )
	{
		cerr<<"Error: In closing the file input.txt";
		throw;
	}
}

int inputfile::get_integer() throw()
{
	char integer;
	
	do
	{
		if( ifile.eof() )
		{
			cerr<<"Error: Write complete 9x9 matrix in input.txt";
			throw;
		}
		else
			ifile.get(integer);
		
		if( ifile.rdstate() )
		{
			cerr<<"Error: While retrieving the charchter from 9x9 matrix in input.txt";
			throw;
		}
		
	
	}while( integer==' ' || integer=='\n' || integer=='\t' );

	
	static int input_numbers = 0;
	if( ++input_numbers == 81 )
		check_file();
	

	if( check_number(integer) )
		return integer-'0';
}

int inputfile::check_number(char& integer) throw()
{
	if( integer >= '0' && integer <= '9' )
		return 1;
	else
	{
		cerr<<"Input charchter should be \'0\' to \'9\' inclusive";
		throw;
	}
}

void inputfile::check_file() throw()
{
	if( ifile.eof() )	
		return;
	else
	{
		char charachter;
		do
		{
			ifile.get(charachter);
			if( ifile.eof() )
			{
				ifile.clear();
				return;
			}
			if( ifile.rdstate() )
			{
				cerr<<"Error: While retrieving the charchter from 9x9 matrix in input.txt\nifile.rdstate()-> "<<ifile.rdstate()<<endl;
				throw;
			}
		
		}while( charachter==' ' || charachter=='\n' || charachter=='\t' );
		if(charachter)
		{
			cerr<<"Error: input should be 81 numbers and it should not be exceeded----------"<<endl;
			throw;
		}
	}
}
