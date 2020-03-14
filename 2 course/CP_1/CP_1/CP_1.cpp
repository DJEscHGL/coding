#include <iostream>
#include <conio.h>
#include <crtdbg.h>

using namespace std;

class Car
{
private:
	int id;
	float* speed;
	string color;
public:
	Car(int ID, float Speed, string Color)
	{
		id = ID;
		speed = new float(Speed);
		color = Color;
	}
	void SetSpeed(float* newSpeed)
	{
		*speed = *newSpeed;
	}
	void ShowSpeed()
	{
		cout << "Now car's speed is: " << *speed;
	}
	void Details()
	{
		cout << "Car with id = " << id << "\nPainted in " << color << "\nMoves with speed: " << *speed << endl;
	}
	~Car()
	{
		delete speed;
		cout << "\nCar is deleted";
		speed = NULL;
	}
};

void main()	
{
	Car BlueCar(4596, 20, "blue");
	BlueCar.Details();
	float carSpeed = 100;
	BlueCar.SetSpeed(&carSpeed);
	BlueCar.ShowSpeed();
	BlueCar.~Car();
}