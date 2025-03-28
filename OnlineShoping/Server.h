#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>

#include "Customer.h"
#include "Product.h"

using namespace std;

//class Product;


class Server
{
private:
	map<string,string>* idpw;
	vector<Customer*>* members;
	vector<shared_ptr<Product>>* products;

	void MakeProducts();

public:
	Server();
	~Server();

	void AddNewMembers(string id, string pw, unique_ptr<Customer> newCustomer);
	//void DeleteMembers(string name, string email);
	void AddMember(unique_ptr<Customer> customer);
	bool Login(string id, string pw);
	unique_ptr<Customer> FindCustomer(string id); //보안 취약
	shared_ptr<Product> FindProduct(int num);
	void PrintProducts();

};