// DinamicCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

struct Double_List //структура данных
{
	int Data; 			//информационное поле
	Double_List* Next, 	//адресное поле
		* Prior;	//адресное поле
};

//указатель на первый элемент списка

Double_List* Head;

//указатель на текущий элемент списка (при необходимости)
Double_List* Current;


int main()
{
    std::cout << "Hello World!\n";
}
