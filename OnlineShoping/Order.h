#pragma once
#include <iostream>
#include <ctime>

#include "Product.h"

using namespace std;

//class Product;



class Order
{
private:
	int orderNum;
	struct tm* orderDate;// = localtime(&timer);
	int orderState;
	shared_ptr<Product> oProduct;

	//void MakeOrderNum(); //

public:
	Order();

	void SetOrderNum();
	void SetOrderNum(int SN);
	int GetOrderNum();

	void SetOrderDate();
	void SetOrderDate(struct tm* datetime);
	struct tm* GetOrderDate();

	void InitOrderState();
	void ProceedOrderState();
	void CancleOrderState();
	void SetOrderState(int state);
	int GetOrderState();

	void SetOProduct(shared_ptr<Product> oProduct);
	shared_ptr<Product> GetOProduct();

};