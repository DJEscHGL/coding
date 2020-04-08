#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	int q = 1;
	bool temp = false;
	string s;
	ifstream input("input.txt");
	ofstream output("output.txt");
	while (!input.eof())
	{
		getline(input, s);
		if (s.find('/') != -1)
			temp = true;
		if (temp)
			output << q;
		q++;
	}
	input.close();
	output.close();
}