/*
	Project: Sudoku
		File: inputfile.h
	
	Author:  Mechiri Vinod Kumar
	Email:   mvk046@gmail.com
	Created: 29-Oct-2014
*/

#if !defined(INPUTFILE_H)
#define INPUTFILE_H
#include<fstream>

using namespace std;

class inputfile
{
	private:
		ifstream ifile;
	
		int check_number(char& integer) throw(); //check the number should between 0 to 9 inclusive
		void check_file() throw(); //check whether the input exceeds or not
	
	public:
		inputfile() throw();
		~inputfile() throw();
		
		int get_integer() throw(); //return integer from input.txt file
};

#endif
