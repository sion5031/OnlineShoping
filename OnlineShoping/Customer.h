#pragma once
#include <iostream>
#include <vector>

#include "Order.h"

using namespace std;


class Customer
{
private:
	string cId;
	string cName;
	string email;
	vector<shared_ptr<Order>>* orders;

public:
	Customer(string id, string name, string email);
	~Customer();

	void SetId(string id);
	string GetId();
	void SetName(string name);
	string GetName();
	void SetEmail(string email);
	string GetEmail();

	void AddOrder(shared_ptr<Order> order);
	void CancleOrder(int SN);
	int GetOrderSize();
	shared_ptr<Order> GetOrder(int SN);

	void ProceedOrder();

	void PrintOrders();
};