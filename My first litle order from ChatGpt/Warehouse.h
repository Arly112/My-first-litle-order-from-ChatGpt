#pragma once
#include "Product.h"
#include <vector>

class Warehouse
{
private:
	std::vector<Product>product;
	int next_id = 1;
public:
	void cout_all_product();
	void add_product();
	void delete_product();
	void find_product();
	void sell_product();
	void give_new_product();
	void cout_product_few();
	void Save();
	void Load();
};