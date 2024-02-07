#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
using namespace std;

struct Elem
{
	string name;
	string work;
	Elem* next;
};

void InsertAtHead(Elem*& head, string name, string work)
{
	Elem* newNode = head;
	head = new Elem;
	head->name = name;
	head->work = work;
	head->next = newNode;
}

void BrListFromFirst(Elem* head) // �������� ������ � ������ � �����
{
	while (head != nullptr)
	{
		cout << "���: " << head->name << " ���������: " << head->work << endl;
		head = head->next;
	}
}

void BrListFromEnd(Elem* head) // �������� ������ � ����� � ������
{
	if (head != nullptr)
	{
		BrListFromEnd(head->next);
		cout << "���: " << head->name << " ���������: " << head->work << endl;
	}
}

int Count(Elem* head, string work) // ����� ��������� � �������� ��������� � ������� �� ����������
{
	int count = 0;
	Elem* current = head;
	while (current != nullptr)
	{
		if (current->work == work)
		{
			count++;
		}
		current = current->next;
	}
	return count;
}

void Delete(Elem* head, string work) //�������� �������� � �������� ��������� (��� ���� ��������� � �������� ���������)
{
	Elem* current = head;
	Elem* prev = nullptr;

	while (current != nullptr && current->work != work)
	{
		prev = current;
		current = current->next;
	}
	if (prev == nullptr) // ���� ��������� ������� - ������ ������
	{
		head = current->next;
	}
	else
	{
		prev->next = current->next;
	}
	delete current;
	std::cout << "������� ������" << endl;
}

struct Elem2
{
	string name;
	string work;
	Elem2* next;
};

void InsertAtTail(Elem2*& head, string name, string work)
{

}

int main()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "1. ���������������� ������, ���������� LIFO" << endl;
	std::cout << "2. ���������������� ������, ���������� FIFO" << endl;
	std::cout << "3. ���������������� ������ � ����������� �� ������ �����" << endl;
	std::cout << "4. ��������������� ������ � ����������� �� ������ �����" << endl;
	std::cout << "5. ��������������� ������ � ����������� �� ���� ������" << endl;

	char  i;
	std::cin >> i;
	string name;
	string work;

	switch (i)
	{
	case '1':
		Elem * head = nullptr;
		//std::cout << "������� ���������� ��������� � ������" << endl;
		//int n;
		//std::cin >> n;
		//for (int k = 1; k < n + 1; k++)
		//{
		//	std::cout << "������� ������ ���������� ��� ������� " << k << endl;
		//	std::cout << "���: ";
		//	std::cin >> name;
		//	std::cout << "���������: ";
		//	std::cin >> work;
		//	InsertAtHead(head, name, work);
		//	std::cout << "������� " << endl;
		//}

		InsertAtHead(head, "John", "Programmer");
		InsertAtHead(head, "Mike", "Scientist");
		InsertAtHead(head, "Mary", "Florist");
		InsertAtHead(head, "John", "Gardener");
		InsertAtHead(head, "Rose", "Actriss");
		InsertAtHead(head, "Ann", "Florist");
		InsertAtHead(head, "Robert", "Programmer");
		InsertAtHead(head, "Victor", "Builder");
		InsertAtHead(head, "Monica", "Programmer");
		InsertAtHead(head, "Joseph", "Pastor");

		std::cout << endl;
		BrListFromFirst(head);
		std::cout << endl;
		BrListFromEnd(head);
		std::cout << endl;

		std::cout << "������� ������ ��� ������ ���������: ";
		std::cin >> work;
		//work = "Gardener"
		std::cout << Count(head, work) << endl;
		std::cout << endl;

		std::cout << "������� ������ ��� �������� ���������: ";
		std::cin >> work;
		//work = "Florist"
		int k = Count(head, work);
		if (k != 0)
		{
			for (int j = 0; j < k; j++)
				Delete(head, work);
			std::cout << endl;
			BrListFromFirst(head);
			std::cout << endl;
			BrListFromEnd(head);
		}
		else
			std::cout << "������ �� ����������" << endl;
		break;
	case '2':

		break;
	}

}