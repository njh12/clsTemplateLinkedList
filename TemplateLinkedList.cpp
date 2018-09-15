
#include "stdafx.h" //For MVS
#include "clsTlinkedlist.h"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{

	string line;
	clslinkedlst<string> thelist;
	ifstream datastream("text.txt");
	//string test
	if (datastream.is_open())
	{

		while (!datastream.eof())
		{
			getline(datastream, line);
			thelist.insertEnd(line);
		};
		datastream.close();
	};

	thelist.lstprint();
	clslinkedlst<int> thelist2;
	//int test
	for (int x = 0; x < 100; x++)
		thelist2.insValByPos(x);

	thelist2.lstprint();
	return 0;
}



