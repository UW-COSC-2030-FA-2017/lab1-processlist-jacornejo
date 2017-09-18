//Lab0.cpp
//Jesse Cornejo
//Cosc


#include<iostream>
#include<fstream>
#include<string>

using namespace std;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::get;





int main()
{
	int count = 0;
	string file;
	ifstream inFile;
	double ints[4];
	//Prompt user to enter a filname
	cout << "Please enter a filname to read first and last two numbers" << endl;
	
	getline(cin, file);
	inFile.open(file);

	while (!inFile) //Error handling in case there are not integers or the the file contains spaces. 
	{
		cout << "Could not open file." << endl;
		inFile.close();
		inFile.clear();

		cout << "Please enter a filname to read first and last two numbers" << endl;
		getline(cin, file);
		inFile.open(file);
	}
	//Storing the first two integers
	inFile >> ints[0];
	inFile >> ints[1];
	

	inFile.seekg(0, ios::beg);//Rewinding to the beginning of the file
	
	while (!inFile.eof() && !inFile.fail())//Counting number of integers in the file. 
	{
		int number;
		inFile >> number;
		count++;
	}

	inFile.seekg(0, ios::beg);//Rewinding to the beginning of the file again

	for (int i = 0; i < count - 2; i++) //using count to find the last two integers in the file 
	{
		int temp;
		inFile >> temp;
	}
	//Storing the last two integers in the file
	inFile >> ints[2];
	inFile >> ints[3];
	

	cout << "The first two and last two numbers are: " << endl;
	for (int i = 0; i < 4; i++)//Using i to call out each individual integer stored in the array
	{
		cout << ints[i] << endl;
	}
	
	cout << "There are " << count << " numbers in the file" << endl;
	inFile.close();//closing the file when done.
	
	return 0;
}


