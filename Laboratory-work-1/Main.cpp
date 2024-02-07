#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");

	static int number;
	std::cout << "Введите номер задания: ";
	std::cin >> number;

	if (number == 1)
	{
		std::cout << "Введите номер подзадания: ";
		std::cin >> number;

		if (number == 1)
		{
			static float S = 1. / 3;
			while (S != 1)
				S = S + 1. / 3;

			std::cout << "Результат: ";
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

			std::cout << "Результат: ";
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

			std::cout << "Результат: ";
			std::cout << "." << A << "." << endl;
		}
	}
	else if (number == 2)
	{
		static float pace = 5.05; //одноставочный тариф за электроэнергию в г.Пермь
		static int ord;
		std::cout << "Введите количество порядков в вашем счетчике: ";
		std::cin >> ord;

		static unsigned __int64 indicator1;
		static unsigned __int64 indicator2;
		static unsigned __int64 all = 1;
		std::cout << "Введите показания счетчика за прошлый месяц: ";
		std::cin >> indicator1;
		std::cout << "Введите показания счетчика за этот месяц: ";
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
		std::cout << "В этом месяце к оплате: ";
		std::cout << toPay << "р." << endl;
	}
	else if (number == 3)
	{
		std::cout << "Введите номер подзадания: ";
		std::cin >> number;

		static float x;
		std::cout << "Введите X, Х не может быть больше 1: ";
		std::cin >> x;
		static double y = ((1. / 4) * log(float(1 + x) / (1 - x))) + (1. / 2) * atan(x);
		static double top = x; //x = 0.5
		static unsigned __int32 bot = 1;
		static double sum = top / bot;
		if (number == 1)
		{
			static unsigned __int16 n;
			std::cout << "Введите количество членов ряда: ";
			std::cin >> n;

			for (int i = 2; i <= n; i++)
			{
				top *= x * x * x * x;
				bot += 4;
				sum += top / bot;
			}
			std::cout << "Сумма ряда до " << n << "-ого члена ряда: ";
			std::cout << fixed << setprecision(17) << setw(20) << sum << endl;
		}
		else if (number == 2)
		{
			static double e;
			//static float e;
			std::cout << "Введите нужную точность: ";
			std::cin >> e;
			static int i = 0;

			{
				i++;
				top *= x * x * x * x;
				bot += 4;
				sum += top / bot;
			} while (top / bot >= e)
				std::cout << "Количество иттераций: " << i << endl; // при double и float e = 0.00000001: 6. Изменений нет.

			std::cout << "Сумма ряда до точности " << e << ": ";
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
				std::cout << "Количество иттераций: " << i << endl; // при double: 6; при float: 30. Из-за уменьшение матисы числа, уменьшилась и максимально возможная точность

			std::cout << "Сумма ряда до макссимальной точности: ";
			std::cout << fixed << setprecision(17) << setw(20) << sum << endl;

		}
		std::cout << "Функция равна ";
		std::cout << y << endl;
	}
	std::cout << endl;
	system("Pause");
}