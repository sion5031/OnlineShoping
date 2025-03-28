#pragma once
#include <iostream>

using namespace std;

class Product
{
private:
	string pName;
	int price;
	int stock; //-1¿Ã∏È æ» ∆ 

public:
	Product();
	Product(string name, int price, int stock);
	~Product();

	void SetPName(string name);
	string GetName();
	void SetPrice(int price);
	int GetPrice();
	void SetStock(int stock);
	int GetStock();
	void PlusStock(int num);
};