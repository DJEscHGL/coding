#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	setlocale(0, "");
	int lineLenght;
	string line;
	ifstream input("input.txt");
	ofstream output("output.txt");
	while (!input.eof())
	{
		getline(input, line);
		lineLenght = line.length();
		for (int i = 1; i < lineLenght; i += 3)
			output << line[i];
		for (int i = 2; i < lineLenght; i += 3)
			output << line[i];
		for (int i = 3; i < lineLenght; i += 3)
			output << line[i];
		output << endl;
	}
	input.close();
	output.close();
}