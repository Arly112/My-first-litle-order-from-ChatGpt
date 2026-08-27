#include <iostream>
#include <fstream>
#include "Warehouse.h"

void Warehouse::cout_all_product()
{
	for (size_t i = 0; i < product.size(); i++)
	{
		std::cout << std::endl;
		std::cout << "ID: " << product[i].ID<<std::endl;
		std::cout << "Название: " << product[i].Name<<std::endl;
		std::cout << "Цена: " << product[i].Price<<std::endl;
		std::cout << "Количество: " << product[i].Count<<std::endl;
		std::cout << "-----------------------------------"<<std::endl;
	}
}

void Warehouse::add_product()
{
	Product p;
	p.ID = next_id;
	next_id++;

	std::cout << std::endl;
	std::cout << "Введите название товара для добавления: ";
	std::getline(std::cin, p.Name);

	std::cout << "Введите цену товара для добавления: ";
	std::cin >> p.Price;
	std::cin.ignore(1000,'\n');

	std::cout << "Введите количество товара для добавления: ";
	std::cin >> p.Count;
	std::cin.ignore(1000,'\n');

	product.push_back(p);
}

void Warehouse::delete_product()
{
	int id;
	std::cout << std::endl;
	std::cout << "Введите ID товара для удаления: ";
	std::cin >> id;

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i].ID == id)
		{
			product.erase(product.begin() + i);
			std::cout << std::endl;
			std::cout << "Товар с ID = " << id << " удалён";
			return;
		}
	}
	std::cout << std::endl;
	std::cout << "Товар с ID = " << id << " не найден";
}

void Warehouse::find_product()
{
	int id;
	std::cout << std::endl;
	std::cout << "Введите ID товара который нужно найти: ";
	std::cin >> id;

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i].ID == id)
		{
			std::cout << std::endl;
			std::cout << "ID: " << product[i].ID << std::endl;
			std::cout << "Название: " << product[i].Name << std::endl;
			std::cout << "Цена: " << product[i].Price << std::endl;
			std::cout << "Количество: " << product[i].Count << std::endl;
			return;
		}
	}
	std::cout << std::endl;
	std::cout << "Товар с ID = " << id << " не найден";
}

void Warehouse::sell_product()
{
	int id,count;
	std::cout << "Введите ID товара который продаёте: ";
	std::cin >> id;
	std::cout << "Введите количество продаваемого товара: ";
	std::cin>>count;

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i].ID == id && product[i].Count>= count)
		{
			std::cout << "Товар с ID = " << id <<" в количестве "<<count<<" успешно продан" << std::endl;
			product[i].Count -= count;
			return;
		}
	}
	std::cout << "Товар с ID = " << id << " не найден или товара на складе слишком мало для данной продажи";
}

void Warehouse::give_new_product()
{
	int id,count;
	std::cout << std::endl;
	std::cout << "Введите ID пополняемого на складе товара: ";
	std::cin >> id;
	std::cout << "Введите количество пополняемого на складе товара: ";
	std::cin>>count;

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i].ID == id)
		{

			product[i].Count += count;
			return;
		}
	}
	std::cout << std::endl;
	std::cout << "Товар с ID = " << id << " не найден";
}

void Warehouse::cout_product_few()
{
	int count;
	std::cout << std::endl;
	std::cout << "Введите минимальный допустимый остаток товара на складе: ";
	std::cin >> count;

	for (size_t i = 0; i < product.size(); i++)
	{
		if (product[i].Count < count)
		{
			if (i + 1 == product.size())
			{
				std::cout << std::endl;
				std::cout << "ID: " << product[i].ID << std::endl;
				std::cout << "Название: " << product[i].Name << std::endl;
				std::cout << "Цена: " << product[i].Price << std::endl;
				std::cout << "Количество: " << product[i].Count << std::endl;
			}
			else
			{
				std::cout << std::endl;
				std::cout << "ID: " << product[i].ID << std::endl;
				std::cout << "Название: " << product[i].Name << std::endl;
				std::cout << "Цена: " << product[i].Price << std::endl;
				std::cout << "Количество: " << product[i].Count << std::endl;
				std::cout << "-----------------------------------" << std::endl;
			}
			return;
		}
	}
	std::cout << std::endl;
	std::cout << "Количество каждого товара больше минимального остатка";
}

void Warehouse::Save()
{
	size_t c;
	c = product.size();
	std::ofstream save;
	save.open("Save.txt");
	save << next_id << std::endl;
	save << c << std::endl;
	for (size_t i = 0; i < c; i++)
	{

		save << product[i].ID << std::endl
			<< product[i].Name << std::endl
			<< product[i].Price << std::endl
			<< product[i].Count << std::endl;
	}
	save.close();
}

void Warehouse::Load()
{
	product.clear();
	size_t c;
	c = product.size();
	std::ifstream Load;
	Load.open("Save.txt");
	Load >> next_id;
	Load >> c;
	for (size_t i = 0; i < c; i++)
	{
		Product p;
		Load >> p.ID;
		Load.ignore(1000, '\n');
		std::getline(Load, p.Name);
		Load >> p.Price >> p.Count;
		product.push_back(p);
	}
	Load.close();
}