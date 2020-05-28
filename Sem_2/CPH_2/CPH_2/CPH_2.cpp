#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>

using namespace std;
//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

int main()
{
	//SetConsoleTextAttribute(hConsole, 2);
	int q = 1; 
	int c1, c2, c3;
	bool temp = false, flag = false;
	string code, indentificator;
	ifstream input("input.txt");
	ofstream output("output.txt");
	getline(input, indentificator);
	while (!input.eof())
	{
		getline(input, code);
		q++;
		if (temp == false)
		{
			c1 = code.find(indentificator);
			c2 = code.find("//");
			if (c2 != -1)
			{
				if (c1 != -1)
				{
					if (c1 < c2)
						flag = true;
				}
			}
			else
			{
				c2 = code.find("/*");
				c3 = code.find("*/");
				if (c2 != -1 && c3 != -1 && c1 != -1)
				{
					if (c1 > c3 || c1 < c2)
						flag = true;
					if (c1 < c3 && c1 > c2)
						flag = false;
				}
			}
			if (flag == true)
			{
				if (code.find(indentificator) != -1)
					output << q << " ";
			}
			continue;
		}
		if (code.find("*/") != -1)
			temp = false;
		if (code.find("/*") != -1)
			temp = true;
		if (temp == true)
			continue;
		else
		{
			if (code.find(indentificator) != -1)
				output << q << " ";
		}
	}
	input.close();
	output.close();
	//SetConsoleTextAttribute(hConsole, 7);
}