// DinamicCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

using namespace std;

//структура данных
struct Single_List
{
	int Data; //информационное поле
	Single_List* Next; //адресное поле
};
//. . . . . . . . . .
//указатель на первый элемент списка
Single_List* Head;
//. . . . . . . . . .
//указатель на текущий элемент списка (при необходимости)
Single_List* Current;

//создание однонаправленного списка (добавления в конец)
void Make_Single_List(int n, Single_List** Head) {
	if (n > 0) {
		(*Head) = new Single_List();
		//выделяем память под новый элемент
		cout << "Введите значение ";
		cin >> (*Head)->Data;
		//вводим значение информационного поля
		(*Head)->Next = NULL;//обнуление адресного поля
		Make_Single_List(n - 1, &((*Head)->Next));
	}
}

//Печать однонаправленного списка
void Print_Single_List(Single_List* Head) {
	if (Head != NULL) {
		cout << Head->Data << "\t";
		Print_Single_List(Head->Next);
		//переход к следующему элементу
	}
	else cout << "\n";
}



int main()
{
	setlocale(LC_ALL, "rus");
	Head = new Single_List();
	Head->Data = 0;
	Make_Single_List(10, &Head->Next);

	Current = Head;
	int i = 0;
	cout << "Вывод списка:" << endl;
	Print_Single_List(Head);
}

