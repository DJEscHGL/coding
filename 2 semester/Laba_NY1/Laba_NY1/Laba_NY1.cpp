#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

struct Vertex {
	double x, y;
};

struct Polygons {
	int NumOfVertex = 0;
	Vertex* Points = nullptr;
	double area = 0;
	bool InFirstTerm = 0;
};

void Output(Polygons* Polyg, int numOfPolygons)
{
	system("cls");
	cout << "#\t" << "Number of vertexes\t" << "Area\t\t" << "In1Term" << endl;
	cout << "=======================================================" << endl;
	for (int i = 0; i < numOfPolygons; i++)
	{
		cout << i + 1 << "\t\t" << Polyg[i].NumOfVertex << "\t\t" << Polyg[i].area << "\t\t" << Polyg[i].InFirstTerm << endl;
	}
	delete Polyg;
}

int main()
{
	int inTerm = 0, numOfPolygons;
	Polygons* Poly;
	cout << "Number of polygons = ";
	cin >> numOfPolygons;
	Poly = new Polygons[numOfPolygons];
	for (int i = 0; i < numOfPolygons; i++)
	{
		cout << i + 1 << " polygon" << endl;
		cout << "Number of vertexes = ";
		cin >> Poly[i].NumOfVertex;
		Poly[i].Points = new Vertex[Poly[i].NumOfVertex];
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
		for (int j = 0; j < Poly[i].NumOfVertex; j++)
		{
			if (Poly[i].Points[j].x >= 0 && Poly[i].Points[j].y >= 0)
				Poly[i].InFirstTerm = true;
			else
			{
				Poly[i].InFirstTerm = false;
				break;
			}
		}
		if (Poly[i].InFirstTerm)
			inTerm++;
	}
	for (int i = 0; i < numOfPolygons; i++)
	{
		double first = 0, second = 0;
		for (int j = 0; j < Poly[i].NumOfVertex - 1; j++)
		{
			first += Poly[i].Points[j].x * Poly[i].Points[j + 1].y;
			second += Poly[i].Points[j + 1].x * Poly[i].Points[j].y;
		}
		first += Poly[i].Points[Poly[i].NumOfVertex - 1].x * Poly[i].Points[0].y;
		second += Poly[i].Points[0].x * Poly[i].Points[Poly[i].NumOfVertex - 1].y;
		Poly[i].area = abs(first - second) * 0.5;
	}
	for (int i = 0; i < numOfPolygons - 1; i++)
	{
		for (int j = 0; j < numOfPolygons - i - 1; j++)
		{
			if (Poly[j].InFirstTerm < Poly[j + 1].InFirstTerm)
			{
				swap(Poly[j], Poly[j + 1]);
			}
		}
	}
	for (int i = 0; i < inTerm - 1; i++)
	{
		for (int j = 0; j < inTerm - i - 1; j++)
		{
			if (Poly[j].area > Poly[j + 1].area)
			{
				swap(Poly[j], Poly[j + 1]);
			}
		}
	}
	Output(Poly, numOfPolygons);
	for (int i = 0; i < numOfPolygons; i++)
	{
		delete[] Poly[i].Points;
		Poly[i].Points = NULL;
	}
	delete[] Poly;
	Poly = NULL;
}