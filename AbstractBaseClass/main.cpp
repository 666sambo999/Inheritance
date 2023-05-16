#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
	int capacity;
public:
	virtual void move() = 0;
};

class AirTransport : public Vehicle
{
	int height;
public:
	virtual void tace_off() = 0;
	virtual void land() = 0;
};

class Helicopter : public AirTransport
{
public: 
	void move()
	{
		cout << "������ �� �����" << endl; 
	}
	void tace_off()
	{
		cout << "�������� � �����" << endl; 
	}
	void land()
	{
		cout << "��� ������, ��� � ����" << endl; 
	}
};

class AirPlain : public AirTransport
{
public:
	void tace_off()
	{
		cout << "��� ������ ����� ������, � ��� ������� ����� ������" << endl;
	}
	void land()
	{
		cout << "������� ����������� �� ������� ��������, � ������ ����� ������" << endl; 
	}
	void move()
	{
		cout << "������ �� ������� ��������" << endl; 
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v;
	//AirTransport av;
	Helicopter apache; 
	apache.tace_off();
	apache.move();
	apache.land();

	AirPlain boing;
	boing.tace_off();
	boing.move();
	boing.land();

}