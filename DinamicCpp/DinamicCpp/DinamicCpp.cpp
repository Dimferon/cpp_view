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

//TODO: Задание 1. Оптимизировать функцию
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

//TODO: Здание 2. Дописать функцию так, чтобы она выводила номер искомого элемента
//Поиск элемента в однонаправленном списке
bool Find_Item_Single_List(Single_List* Head, int DataItem) {
	Single_List* Current = Head; //вспомогательным указатель
	while (Current != NULL) {//пока не конец списка
		if (DataItem == Current->Data) return true;
		else Current = Current->Next;
	}
	return false;
}

//TODO: Задание 3. Сделать функцию очищающую список после N-ного элемента
//Delete_Single_List(Single_List* Head, int Number=1);
/*освобождение памяти, выделенной под однонаправленный список*/
void Delete_Single_List(Single_List* Head)
{
	if (Head != NULL)
	{
		Delete_Single_List(Head->Next);
		delete Head;
	}
}

struct Stack
{
	Single_List* Top = NULL;
};

//добавление элемента в вершину стека
void Push_Stack(int NewElem, Stack* Top_Stack) {
	Top_Stack->Top = Insert_Item_Single_List(Top_Stack->Top, NewElem, 1);
}

//извлечение элемента из вершины стека
int Pop_Stack(Stack* Top_Stack) {
	int NewElem = NULL;
	if (Top_Stack->Top != NULL) {
		NewElem = Top_Stack->Top->Data;
		Top_Stack->Top = Delete_Item_Single_List(Top_Stack->Top, 0);
		//удаляем вершину
	}
	return NewElem;
}


//Заполнение стека
void Make_Stack(int n, Stack* Top_Stack) {
	if (n > 0) {
		int tmp;//вспомогательная переменная
		cout << "Введите значение ";
		cin >> tmp; //вводим значение информационного поля
		Push_Stack(tmp, Top_Stack);
		Make_Stack(n - 1, Top_Stack);
	}
}
//печать стека
void Print_Stack(Stack* Top_Stack) {
	Print_Single_List(Top_Stack->Top);
}



int main()
{
	Stack stack1;
	Make_Stack(5, &stack1);
	setlocale(LC_ALL, "rus");
	Make_Single_List(10, &Head);
	cout << "1) Вывод списка:";
	Print_Single_List(Head);
	
	Current = ((Head->Next)->Next)->Next;
	((Head->Next)->Next)->Next = NULL;

	Delete_Single_List(Current);
	cout << "1) Вывод списка:";
	Print_Single_List(Head);
	Current = Head;
	int i = 0;
}

