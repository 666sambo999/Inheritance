#include <iostream>
#include <fstream> 
using namespace std;

#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
	
	//1) ������� ����� ������ (������ � ����)
	ofstream fout;
	//2) ��������� �����, ������� ����� ����� ��������, � ����� ��������� ���� �� �����
	fout.open("File.txt",std::ios_base::app); // ����, ��������� ��������� ��������� � ����
	//3) ������� (����������) ���������� � ����
	fout << "Hello Files!" << endl;
	//4)  ������ ����������� ����� ���������, ������ ��������� ���������,�� ����� �������� � �������������� ������������
	fout.close();

	system("notepad File.txt");
}