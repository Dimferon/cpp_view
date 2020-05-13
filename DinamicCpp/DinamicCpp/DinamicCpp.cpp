// DinamicCpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <iostream>
using namespace std;

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

//создание двунаправленного списка (добавления в конец)
void Make_Double_List(int n, Double_List** Head, Double_List* Prior)
{
	if (n > 0)
	{
		(*Head) = new Double_List();
		//выделяем память под новый элемент
		cout << "Введите значение ";
		cin >> (*Head)->Data;
		//вводим значение информационного поля
		(*Head)->Prior = Prior;
		(*Head)->Next = NULL;//обнуление адресного поля
		Make_Double_List(n - 1, &((*Head)->Next), (*Head));
	}
	else (*Head) = NULL;
}

//печать двунаправленного списка
void Print_Double_List(Double_List* Head)
{
	if (Head != NULL) {
		cout << Head->Data << "\t";
		Print_Double_List(Head->Next);
		//переход к следующему элементу
	}
	else cout << "\n";
}

//вставка элемента с заданным номером в двунаправленный список
Double_List* Insert_Item_Double_List(Double_List* Head, int Number, int DataItem)
{
	Number--;
	Double_List* NewItem = new(Double_List);
	NewItem->Data = DataItem;
	NewItem->Prior = NULL;
	NewItem->Next = NULL;
	//список пуст
	if (Head == NULL) { Head = NewItem; }
	else {//список не пуст
		Double_List* Current = Head;
		for (int i = 1; i < Number && Current->Next != NULL; i++)
			Current = Current->Next;
		if (Number == 0) {
			//вставляем новый элемент на первое место
			NewItem->Next = Head;
			Head->Prior = NewItem;
			Head = NewItem;
		}
		else {//вставляем новый элемент на непервое место
			if (Current->Next != NULL) Current->Next->Prior = NewItem;
			NewItem->Next = Current->Next;
			Current->Next = NewItem;
			NewItem->Prior = Current;
			Current = NewItem;
		}
	}
	return Head;
}

/*удаление элемента с заданным номером из двунаправленного списка*/
Double_List* Delete_Item_Double_List(Double_List* Head, int Number)
{
	Double_List* ptr;//вспомогательный указатель
	Double_List* Current = Head;
	for (int i = 1; i < Number && Current != NULL; i++)
		Current = Current->Next;
	if (Current != NULL) {//проверка на корректность
		if (Current->Prior == NULL) {//удаляем первый элемент
			Head = Head->Next;
			delete(Current);
			Head->Prior = NULL;
			Current = Head;
		}
		else {//удаляем непервый элемент
			if (Current->Next == NULL) {
				//удаляем последний элемент
				Current->Prior->Next = NULL;
				delete(Current);
				Current = Head;
			}
			else {//удаляем непервый и непоследний элемент
				ptr = Current->Next;
				Current->Prior->Next = Current->Next;
				Current->Next->Prior = Current->Prior;
				delete(Current);
				Current = ptr;
			}
		}
	}
	return Head;
}
//Задание 1.
//Написать функцию которая ищет запись с определенным значением, в функцию подается:
//1) Начало списка
//2) Конец списка
//3) Количество Элементов в списке
//4) Искомое значение
// Функция возвращает номер записи в списке
// Поиск записи идет в обоих направлениях от середины

//Задание 2
//Написать функцию которая вставляет значение запись с определенным значением, 
//в функцию подается:
//1) Начало списка
//2) Вставляемое значение
//3) Номер вставки
// Функция возвращает количество элементов в списке
//Действия в фунции
// 1. В функции сначала считает количество элементов в списке и выводит (cout)
// 2. В функции ищется центральный элемент и выводится его значение
// 3. В функции выводятся все номера и значения записи от центра списка до вставляемого

int main()
{
    std::cout << "Hello World!\n";
}
