#include <iostream>
#include <string>
#include <windows.h>
#include "Warehouse.h"
void cout_Menu()
{
	std::cout<< std::endl;
	std::cout << "1.Показать все товары" << std::endl;
	std::cout << "2.Добавить товар" << std::endl;
	std::cout << "3.Удалить товар" << std::endl;
	std::cout << "4.Найти товар" << std::endl;
	std::cout << "5.Продать товар" << std::endl;
	std::cout << "6.Пополнить товар" << std::endl;
	std::cout << "7.Показать товары, которых мало" << std::endl;
	std::cout << "8.Сохранить данные" << std::endl;
	std::cout << "9.Загрузить данные" << std::endl;
	std::cout << "0.Выход" << std::endl;
	std::cout << std::endl;
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "ru");
	int vab;
	vab = -1;
	Warehouse w;
	while (vab!=0)
	{
		cout_Menu();
		std::cin >> vab;
		std::cin.ignore( 1000,'\n');
		switch (vab)
		{
		case 1:
			w.cout_all_product();
			break;
		case 2:
			w.add_product();
			break;
		case 3:
			w.delete_product();
			break;
		case 4:
			w.find_product();
			break;
		case 5:
			w.sell_product();
			break;
		case 6:
			w.give_new_product();
			break;
		case 7:
			w.cout_product_few();
			break;
		default:
			break;
		}
	}
	
}

