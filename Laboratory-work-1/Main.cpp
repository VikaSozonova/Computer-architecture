#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	static int number;
	std::cout << "������� ����� �������: ";
	std::cin >> number;

	if (number == 1)
	{
		std::cout << "������� ����� ����������: ";
		std::cin >> number;

		if (number == 1)
		{
			static float S = 1. / 3;
			while (S != 1)
				S = S + 1. / 3;

			std::cout << "���������: ";
			std::cout << S << endl;
		}
		else if (number == 2)
		{
			static unsigned char A;
			A = 255;
			do
			{
				A++;
			} while (A != 0);

			std::cout << "���������: ";
			std::cout << "." << A << "." << endl;
		}
		else if (number == 3)
		{
			static signed __int8 A;
			A = -127;
			while (A < 0)
			{
				A = A - 1;
			}

			std::cout << "���������: ";
			std::cout << "." << A << "." << endl;
		}
	}
	else if (number == 2)
	{
		static float pace = 5.05; //������������� ����� �� �������������� � �.�����
		static int ord;
		std::cout << "������� ���������� �������� � ����� ��������: ";
		std::cin >> ord;

		static unsigned __int64 indicator1;
		static unsigned __int64 indicator2;
		static unsigned __int64 all = 1;
		std::cout << "������� ��������� �������� �� ������� �����: ";
		std::cin >> indicator1;
		std::cout << "������� ��������� �������� �� ���� �����: ";
		std::cin >> indicator2;
		static float toPay;
		if (indicator2 >= indicator1)
		{
			toPay = (indicator2 - indicator1) * pace;
		}
		else
		{
			for (int i = 1; i <= ord; i++)
			{
				all *= 10;
			}
			toPay = (indicator2 + all - indicator1) * pace;
		}
		std::cout << "� ���� ������ � ������: ";
		std::cout << toPay << "�." << endl;
	}
	else if (number == 3)
	{
		std::cout << "������� ����� ����������: ";
		std::cin >> number;

		static float x;
		std::cout << "������� X, � �� ����� ���� ������ 1: ";
		std::cin >> x;
		static double y = ((1. / 4) * log(float(1 + x) / (1 - x))) + (1. / 2) * atan(x);
		static double top = x; //x = 0.5
		static unsigned __int32 bot = 1;
		static double sum = top / bot;
		if (number == 1)
		{
			static unsigned __int16 n;
			std::cout << "������� ���������� ������ ����: ";
			std::cin >> n;

			for (int i = 2; i <= n; i++)
			{
				top *= x * x * x * x;
				bot += 4;
				sum += top / bot;
			}
			std::cout << "����� ���� �� " << n << "-��� ����� ����: ";
			std::cout << fixed << setprecision(17) << setw(20) << sum << endl;
		}
		else if (number == 2)
		{
			static double e;
			//static float e;
			std::cout << "������� ������ ��������: ";
			std::cin >> e;
			static int i = 0;

			{
				i++;
				top *= x * x * x * x;
				bot += 4;
				sum += top / bot;
			} while (top / bot >= e)
				std::cout << "���������� ���������: " << i << endl; // ��� double � float e = 0.00000001: 6. ��������� ���.

			std::cout << "����� ���� �� �������� " << e << ": ";
			std::cout << fixed << setprecision(17) << setw(20) << sum << endl;
		}
		else if (number == 3)
		{
			//static double e = numeric_limits<double>::min();
			static float e = numeric_limits<float>::min();
			static int i = 0;

			{
				i++;
				top *= x * x * x * x;
				bot += 4;
				sum += top / bot;
			} while (top / bot >= e)
				std::cout << "���������� ���������: " << i << endl; // ��� double: 6; ��� float: 30. ��-�� ���������� ������ �����, ����������� � ����������� ��������� ��������

			std::cout << "����� ���� �� ������������� ��������: ";
			std::cout << fixed << setprecision(17) << setw(20) << sum << endl;

		}
		std::cout << "������� ����� ";
		std::cout << y << endl;
	}
	std::cout << endl;
	system("Pause");
}