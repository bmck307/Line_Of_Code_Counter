// LOC_Counter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*
	Hey dumbass, put the files in C:\Users\brayd\source\repos\LOC_Counter for them to run
*/

int javaCounter(string fileName)
{
	string line;
	string comment = "//"; //Any line including a comment is skipped
	string blockComment1 = "/**";
	string blockComment2 = "*"; //This is going to lead to any lines including multiplication to be skipped
	string blockComment3 = "*/";
	string import = "import";

	int counter = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			size_t foundComment = line.find(comment);
			size_t foundBlock1 = line.find(blockComment1);
			size_t foundBlock2 = line.find(blockComment2);
			size_t foundBlock3 = line.find(blockComment3);
			size_t foundImport = line.find(import);
			if (line == "" || line == "{" || line == "}" || foundComment != string::npos || foundBlock1 !=string::npos
				|| foundBlock2 != string::npos || foundBlock3 != string::npos || foundImport != string::npos) {} //Do nothing
			else
			{
				++counter;
			}
		}
	}
	return counter;
}

int cppCounter(string fileName)
{
	string line;
	string comment = "//"; //Any line including a comment is skipped
	string blockComment1 = "/*"; // Middle of block comments is going to be skipped
	string blockComment2 = "*/";
	string include = "include";

	int counter = 0;
	ifstream myfile(fileName);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			size_t foundComment = line.find(comment);
			size_t foundBlock1 = line.find(blockComment1);
			size_t foundBlock2 = line.find(blockComment2);
			size_t foundImport = line.find(include);
			if (line == "" || line == "{" || line == "}" || foundComment != string::npos || foundBlock1 != string::npos
				|| foundBlock2 != string::npos  || foundImport != string::npos) {
			} //Do nothing
			else
			{
				++counter;
			}
		}
	}
	return counter;
}

int main()
{
	ofstream output;
	output.open("lineCount.csv");
	output << "Project, File Name, LOC" << endl;

	while (true)
	{
		string userFile = "";
		int counter = 0;
		cout << "What file would you like counted? \n";
		cin >> userFile;

		size_t foundJava = userFile.find(".java");
		size_t foundCPP = userFile.find(".cpp");
		size_t foundClass = userFile.find(".class");
		size_t foundHeader = userFile.find(".h");

		if (foundJava != string::npos || foundClass != string::npos)
		{
			counter = javaCounter(userFile);
			output << "Java 2," << userFile << "," << counter << endl; //My files are not organized beyond this
		}
		else if (foundCPP != string::npos || foundHeader != string::npos)
		{
			counter = cppCounter(userFile);
			output << "DS," << userFile << "," << counter << endl; //My files are not organized beyond this
		}
		else
		{
			cout << "ERROR \n" << counter;
		}
	}
	
}
