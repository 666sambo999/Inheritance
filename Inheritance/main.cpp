#include<iostream>
#include <windows.h>
using namespace std;

enum Color // enum - перечисление 
{
	console_default = 0x07, // 0x - перфекс на 16-ую систему 
	console_blue = 0x99,
	console_green = 0xAA,
	console_red = 0xCC,
	console_yellow = 0xEE,
	console_white = 0xFF,
};

class Shape // класс фигуры 
{
	Color color;
public:
	Color get_color()const
	{
		return color;
	}
	virtual double get_area()const = 0;
	virtual double get_perimetr()const = 0;
	virtual void draw()const = 0;

	Shape(Color color) :color(color) {}
	virtual~Shape() {}
};

class Square :public Shape
{
	double side;
public:
	double get_side(double side)
	{
		return side;
	}
	void set_side(double side)
	{
		if (side < 3)side = 3;
		if (side < 15)side = 15;
		this->side = side;
	}
	double get_side()const
	{
		return side;
	}
	double get_area()const override
	{
		return side * side;
	}
	double get_perimetr()const override
	{
		return side * 4;
	}
	void draw()const override
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl; 
		}
	}
	Square(double side, Color color) :Shape(color)
	{
		set_side(side);
	}
};

void main()
{
	setlocale(LC_ALL, "");
	Square squqre(5, Color::console_red);
	cout << "длина стороны квадрата:" << squqre.get_side() << endl;
	cout << "Площадь квадрата: " << squqre.get_area() << endl;
	cout << "Перимерт кважрата: " << squqre.get_perimetr() << endl;
	squqre.draw();
}