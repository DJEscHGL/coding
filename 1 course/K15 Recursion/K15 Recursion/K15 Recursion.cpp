#include <iostream>

using namespace std;

int s = 0;

void recursia(int q)
{
	int p;
	while (q > 1)
	{
		if (q % 2 == 0)
			q /= 2;
		else
		{
			q -= 1;
			q /= 2;
			recursia(q + 1);
		}
	}
	s += 1;
}

int main()
{
	int n;
	cin >> n;
	recursia(n);
	cout << s;
}