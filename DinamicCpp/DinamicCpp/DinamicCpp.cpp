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

/*вставка элемента с заданным номером в однонаправленный список*/
Single_List* Insert_Item_Single_List(Single_List* Head,
	int DataItem, int Number = 1) {
	Number--;
	Single_List* NewItem = new(Single_List);
	NewItem->Data = DataItem;
	NewItem->Next = NULL;
	if (Head == NULL) {//список пуст
		Head = NewItem;//создаем первый элемент списка
	}
	else
	{//список не пуст
		Single_List* Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;

		if (Number == 0) {
			//вставляем новый элемент на первое место
			NewItem->Next = Head;
			Head = NewItem;
		}
		else {//вставляем новый элемент на непервое место
			if (Current->Next != NULL)
				NewItem->Next = Current->Next;
			Current->Next = NewItem;
		}
	}
	return Head;
}

/*удаление элемента с заданным номером из однонаправленного списка*/
Single_List* Delete_Item_Single_List(Single_List* Head,
	int Number = 1)
{
	if (Number < 1)throw std::exception("Выход за границу списка");
	Single_List* ptr;//вспомогательный указатель
	Single_List* Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) //проверка на корректность
	{
		if (Current == Head)//удаляем первый элемент
		{
			Head = Head->Next;
			delete(Current);
			Current = Head;
		}
		else //удаляем непервый элемент
		{
			ptr = Head;
			while (ptr->Next != Current)
				ptr = ptr->Next;
			ptr->Next = Current->Next;
			delete(Current);
			Current = ptr;
		}
	}
	return Head;
}



int main()
{
	setlocale(LC_ALL, "rus");
	Make_Single_List(10, &Head);
	cout << "1) Вывод списка:" << endl;
	Print_Single_List(Head);

	Delete_Item_Single_List(Head, 5);

	Current = Head;
	int i = 0;
	cout << "2) Вывод списка:" << endl;
	Print_Single_List(Head);
}

