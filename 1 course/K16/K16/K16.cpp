#include <iostream>

using namespace std;

bool check(int q)
{
	if (q >= 10 && q <= 15)
		return true;
	while (q > 15)
	{
		if (q % 16 >= 10)
			return true;
		q /= 16;
	}
	return false;
}

int main()
{
	setlocale(0, "");
	int q;
	cin >> q;
	if (check(q))
		cout << "Буквы есть";
	else
		cout << "Букв нет";
}