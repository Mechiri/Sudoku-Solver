#if !defined(INPUTFILE_H)
#define INPUTFILE_H
#include<fstream>

using namespace std;

class inputfile
{
	private:
		ifstream ifile;
	
	public:
		inputfile();
		~inputfile();
		
		int get_integer(); //return integer from input.txt file
		int check_number(char& integer) throw(); //check the number should between 0 to 9 inclusive
		void check_file(); //check whether the input exceeds or not
};

#endif
