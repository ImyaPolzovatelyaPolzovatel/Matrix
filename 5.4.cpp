#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, flag, mem;
	bool flag1 = false;
	while (flag1 != true)
	{
		cout << "Введите количество кирпичей: ";
		cin >> n;
		if (n <= 0)
			cout << endl << "Вы ввели недопустимое количество кирпичей" << endl;
		else
			flag1 = true;
	}
	flag1 = false;
	flag = rand() % 2;
	cout << "____________________________________" << endl;
	if (flag == 0)
	{
		while (n > 0)
		{
			cout << "Ход компьютера: ";
			if (n < 4)
				mem = n;
			else
				mem = 1 + rand() % 3;
			cout << mem << endl;
			n -= mem;
			cout << "Количество кирпичей: " << n << endl;
			if (n <= 0)
			{
				cout << "____________________________________" << endl << "Вы проиграли" << endl << "____________________________________" << endl;
				break;
			}
			cout << "____________________________________" << endl << "Ваш ход" << endl;
			while (flag1 != true)
			{
				cout << "Введите количество кирпичей: ";
				cin >> mem;
				if (mem > 4 || mem <= 0)
				{
					cout << endl << "Вы ввели недопустимое количество кирпичей" << endl;
					flag1 = false;
				}
				else
				{
					n -= mem;
					cout << "Количество кирпичей: " << n << endl;
					flag1 = true;
				}
			}
			if (n <= 0)
			{
				cout << "____________________________________" << endl << "Вы выйграли" << endl << "____________________________________" << endl;
				break;
			}
			flag1 = false;
			cout << "____________________________________" << endl;
		}
	}
	else
	{
		while (n > 0)
		{
			cout << "Ваш ход" << endl;
			while (flag1 != true)
			{
				cout << "Введите количество кирпичей: ";
				cin >> mem;
				if (mem > 4 || mem <= 0)
				{
					cout << endl << "Вы ввели недопустимое количество кирпичей" << endl;
					flag1 = false;
				}
				else
				{
					n -= mem;
					cout << "Количество кирпичей: " << n << endl;
					flag1 = true;
				}
			}
			if (n <= 0)
			{
				cout << "____________________________________" << endl << "Вы выйграли" << endl << "____________________________________" << endl;
				break;
			}
			cout << "____________________________________" << endl;
			cout << "Ход компьютера: ";
			if (n < 4)
				mem = n;
			else
				mem = 1 + rand() % 3;
			cout << mem << endl;
			n -= mem;
			cout << "Количество кирпичей: " << n << endl;
			if (n <= 0)
			{
				cout << "____________________________________" << endl << "Вы проиграли" << endl << "____________________________________" << endl;
				break;
			}
			flag1 = false;
			cout << "____________________________________" << endl;
		}
	}
	system("pause");
	return 0;
}
