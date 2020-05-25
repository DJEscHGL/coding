#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	int first, last;
	string str, str2;
	ifstream input("input.txt");
	ofstream output("output.txt");
	while (!input.eof())
	{
		getline(input, str, '.');
		first = str.find_first_of(32);
		last = str.find_last_of(32);
		if (first < 0 || last < 0)
			output << str;
		else {
			str2 += str.substr(last + 1, str.length() - last);
			str2 += str.substr(first, last - first + 1);
			str2 += str.substr(0, first);
			output << str2;
			str2 = 32;
		}
	}
	input.close();
	output.close();
}