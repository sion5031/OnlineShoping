#include "Product.h"

Product::Product()
{
}

Product::Product(string name, int price, int stock)
{
	this->pName = name;
	this->price = price;
	this->stock = stock;
}

Product::~Product()
{
}

void Product::SetPName(string name)
{
	this->pName = name;
}

string Product::GetName()
{
	return this->pName;
}

void Product::SetPrice(int price)
{
	this->price = price;
}

int Product::GetPrice()
{
	return this->price;
}

void Product::SetStock(int stock)
{
	this->stock = stock;
}

int Product::GetStock()
{
	return this->stock;
}

void Product::PlusStock(int num)
{
	this->stock += num;
}
