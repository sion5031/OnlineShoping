#include "Customer.h"

Customer::Customer(string id, string name, string email)
{
	this->cId = id;
	this->cName = name;
	this->email = email;
	this->orders = new vector<shared_ptr<Order>>;
}

Customer::~Customer()
{
}

void Customer::SetId(string id)
{
	this->cId = id;
}

string Customer::GetId()
{
	return this->cId;
}

void Customer::SetName(string name)
{
	this->cName = name;
}

string Customer::GetName()
{
	return this->cName;
}

void Customer::AddOrder(shared_ptr<Order> order)
{
	this->orders->push_back(order);
}

void Customer::CancleOrder(int SN)
{
	if (GetOrder(SN)) {
		(*GetOrder(SN)).CancleOrderState();
	}
	else
	{
		cout << "주문 취소에 실패하였습니다." << endl;
	}
		
}

int Customer::GetOrderSize() //SN만들 때 씀
{
	return orders->size() + 1;
}


shared_ptr<Order> Customer::GetOrder(int SN)
{
	for (int i = 0;i < this->orders->size();i++) {
		if ((*orders)[i]->GetOrderNum() == SN)
		{
			return (*orders)[i];
		}
		else
		{
			cout << "No Order Found!" << endl;
			return nullptr;
		}
	}
}

void Customer::ProceedOrder()
{
	for (int i = 0;i < orders->size();i++)
	{
		orders->at(i)->ProceedOrderState();
	}
}

void Customer::PrintOrders()
{
	cout << "주문번호" << '\t' << "상품명" << '\t' << "주문일자" << '\t' << "주문상태" << endl;
	for (int i = 0;i < orders->size();i++)
	{
		cout << orders->at(i)->GetOrderNum() << '\t' << orders->at(i)->GetOProduct()->GetName() << '\t';
		cout << orders->at(i)->GetOrderDate()->tm_year + 1900 << '.';
		cout.width(2);
		cout.fill('0');
		cout << orders->at(i)->GetOrderDate()->tm_mon << '.';
		cout.width(2);
		cout.fill('0');
		cout << orders->at(i)->GetOrderDate()->tm_wday << ' ';
		cout.width(2);
		cout.fill('0');
		cout << orders->at(i)->GetOrderDate()->tm_hour << ':';
		cout.width(2);
		cout.fill('0');
		cout << orders->at(i)->GetOrderDate()->tm_min;
		cout << '\t' << orders->at(i)->GetOrderState() << endl;
	}
}

void Customer::SetEmail(string email)
{
	this->email = email;
}

string Customer::GetEmail()
{
	return this->email;
}
