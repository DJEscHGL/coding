#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

struct Polygons {
	struct Vertex {
		double x, y;
	};
	int NumOfVertex = 0;
	Vertex* Points = new Vertex[NumOfVertex];
	double perimetr = 0;
	bool IsKTerm = 0;
};

void Output(Polygons* Poly, int numOfPolygons)
{
	system("cls");
	cout << "#\t" << "Number of vertexes\t" << "Perimeter\t" << "In K Term" << endl;
	cout << "======================================================================" << endl;
	for (int i = 0; i < numOfPolygons; i++)
	{
		cout << i + 1 << '\t' << Poly[i].NumOfVertex << '\t' << Poly[i].perimetr << "\t" << Poly[i].IsKTerm << endl;
	}
}

int main()
{
	int temp = 0, InKTerm = 0, allPoints, k, numOfPolygons, buff;
	bool stupid = true;
	double side;
	cout << "k = ";
	cin >> k;
	cout << "Number of polygons = ";
	cin >> numOfPolygons;
	Polygons* Poly;
	Poly = new Polygons[numOfPolygons];
	for (int i = 0; i < numOfPolygons; i++)
	{
		cout << i + 1 << " polygon";
		cout << "Number of vertexes ";
		cin >> Poly[i].NumOfVertex;
		while (stupid)
		{
			if (Poly[i].NumOfVertex < 3)
			{
				cout << "\nNum of vertexes must be more or equal 3: ";
				cin >> Poly[i].NumOfVertex;
			}
			else
				stupid = false;
		}
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			cout << "x[" << j + 1 << "] = ";
			cin >> Poly[i].Points[j].x;
			cout << "y[" << j + 1 << "] = ";
			cin >> Poly[i].Points[j].y;
			cin.get();
		}
	}
	for (int i = 0; i < numOfPolygons; i++)
	{
		for (int j = 0; j < Poly[i].NumOfVertex - 1; j++)
		{
			side =
				sqrt((Poly[i].Points[j].x - Poly[i].Points[j + 1].x)
					* (Poly[i].Points[j].x - Poly[i].Points[j + 1].x)
					+ (Poly[i].Points[j].y - Poly[i].Points[j + 1].y)
					* (Poly[i].Points[j].y - Poly[i].Points[j + 1].y));
			Poly[i].perimetr += side;
			buff = j + 1;
		}
		Poly[i].perimetr +=
			sqrt((Poly[i].Points[0].x - Poly[i].Points[buff].x)
				* (Poly[i].Points[0].x - Poly[i].Points[buff].x)
				+ (Poly[i].Points[0].y - Poly[i].Points[buff].y)
				* (Poly[i].Points[0].y - Poly[i].Points[buff].y));
	}
	for (int i = 0; i < numOfPolygons; i++)
	{
		allPoints = Poly[i].NumOfVertex * 2;
		// Проверка первой четверти
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			if (Poly[i].Points[j].x >= 0 && Poly[i].Points[j].y >= 0)
				temp++;
			else
				break;
		}
		if (temp == allPoints)
		{
			if (k == 1)
			{
				Poly[i].IsKTerm = true;
				InKTerm++;
				continue;
			}
			else
				Poly[i].IsKTerm = false;
		}
		// Проверка второй четверти
		temp = 0;
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			if (Poly[i].Points[j].x <= 0 && Poly[i].Points[j].y >= 0)
				temp++;
			else
				break;
		}
		if (temp == allPoints)
		{
			if (k == 2)
			{
				Poly[i].IsKTerm = true;
				InKTerm++;
				continue;
			}
			else
				Poly[i].IsKTerm = false;
		}
		// Проверка третьей четверти
		temp = 0;
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			if (Poly[i].Points[j].x <= 0 && Poly[i].Points[j].y <= 0)
				temp++;
			else
				break;
		}
		if (temp == allPoints)
		{
			if (k == 3)
			{
				Poly[i].IsKTerm = true;
				InKTerm++;
				continue;
			}
			else
				Poly[i].IsKTerm = false;
		}
		// Проверка четвёртой четверти
		temp = 0;
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			if (Poly[i].Points[j].x >= 0 && Poly[i].Points[j].y <= 0)
				temp++;
			else
				break;
		}
		if (temp == allPoints)
		{
			if (k == 4)
			{
				Poly[i].IsKTerm = true;
				InKTerm++;
				continue;
			}
			else
				Poly[i].IsKTerm = false;
		}
	}
	for (int i = 0; i < numOfPolygons - 1; i++)
	{
		for (int j = 0; j < numOfPolygons - i - 1; j++)
		{
			if (Poly[j].IsKTerm > Poly[j + 1].IsKTerm)
			{
				swap(Poly[j].NumOfVertex, Poly[j + 1].NumOfVertex);
				swap(Poly[j].perimetr, Poly[j + 1].perimetr);
				swap(Poly[j].IsKTerm, Poly[j + 1].IsKTerm);
			}
		}
	}
	for (int i = 0; i < InKTerm - 1; i++)
	{
		for (int j = 0; j < InKTerm - i - 1; j++)
		{
			if (Poly[j].perimetr > Poly[j + 1].perimetr)
			{
				swap(Poly[j].NumOfVertex, Poly[j + 1].NumOfVertex);
				swap(Poly[j].perimetr, Poly[j + 1].perimetr);
				swap(Poly[j].IsKTerm, Poly[j + 1].IsKTerm);
			}
		}
	}
	Output(Poly, numOfPolygons);
	for (int i = 0; i < Poly[i].NumOfVertex; i++)
	{
		delete[] Poly[i].Points;
	}
	delete[] Poly;
}