/* синтаксис объявления двумерного массива
*тип данных* *имя массива*[*количество строк*][*количество столбцов*];*/

// Типов данных куча, но взял только те, что в одно слово пишутся

/*
 0    1    2    3    4  
* *  *[*  *]*  *[*  *]*
32 - space
91 - [
93 - ]
*/

#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	int symbol[5];
	bool flag = false;
	string str, type;
	ifstream input("input.txt");
	ofstream output("output.txt");
	while (!input.eof()) {
		getline(input, str);
		symbol[0] = str.find(32);
		symbol[1] = str.find_first_of(91);
		symbol[2] = str.find_first_of(93);
		symbol[3] = str.find_last_of(91);
		symbol[4] = str.find_last_of(93);
		type = str.substr(0, symbol[0]);
		if (type == "int" || type == "double" || type == "float" || type == "char" || type == "bool" || type == "short" || type == "long") {
			flag = true;
		}
		else
			flag = false;
		if (flag) {
			if (str[symbol[0] + 1] >= 48 && str[symbol[0] + 1] <= 57)
				flag = false;
		}
		if (flag) {
			for (int i = symbol[0] + 1; i < symbol[1]; i++) {
				for (int j = 32; j < 48; j++) {
					if (str[i] == j) {
						flag = false;
						break;
					}
				}
				if (!flag)
					break;
			}
		}
		if (flag) {
			if (symbol[2] - symbol[1] == 1)
				flag = false;
			if (symbol[4] - symbol[3] == 1)
				flag = false;
		}
		if (str[str.length() - 1] != 59)
			flag = false;
		if (flag)
			output << "True" << endl;
		else
			output << "False" << endl;
	}
	input.close();
	output.close();
}