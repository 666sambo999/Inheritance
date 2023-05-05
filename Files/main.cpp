#include <iostream>
#include <fstream> 
using namespace std;

#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
	
	//1) создаем потов вывода (записи в файл)
	ofstream fout;
	//2) открываем поток, открыть нужно чтобы показать, в какой конкретно файл мы пишем
	fout.open("File.txt",std::ios_base::app); // ‘лаг, позвол€ет добавл€ть содржимое в файл
	//3) выводим (записываем) информацию в файл
	fout << "Hello Files!" << endl;
	//4)  ѕотоки об€зательно нужно закрывать, нельз€ оставл€ть открытыми,тк может привести к непредвиденным последстви€м
	fout.close();

	system("notepad File.txt");
}