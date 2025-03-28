#include "Order.h"

Order::Order()
{
	time_t timer;
	timer = time(NULL);
	orderDate = new tm;
	localtime_s(orderDate, &timer);
	orderState = 0;
}

void Order::SetOrderNum()
{
	time_t timer;
	timer = time(NULL);
	orderDate = new tm;
	localtime_s(orderDate, &timer);
}

void Order::SetOrderNum(int SN)
{
	this->orderNum = SN;
}

int Order::GetOrderNum()
{
	return this->orderNum;
}

void Order::SetOrderDate()
{
}


void Order::SetOrderDate(tm* datetime)
{
	this->orderDate = datetime;
}

tm* Order::GetOrderDate()
{
	return this->orderDate;
}

void Order::InitOrderState()
{
	orderState = 0;
}

void Order::ProceedOrderState()//멤버함수?
{
	if (orderState >= 0 && orderState < 2)
	{
		this->orderState++;
	}
	else if (orderState == 2)
	{
		cout << "Already delivered!" << endl;
	}
	else
	{
		cout << "Error in ProceedOrderState()" << endl;
	}
}

void Order::CancleOrderState()
{
	if (orderState != NULL)
	{
		if (orderState == 0)
		{
			this->CancleOrderState();
		}
		else if (0 < orderState < 2)
		{
			cout << "주문이 진행 중으로 취소할 수 없습니다." << endl;
		}
	}
	else
	{
		cout << "orderState Not Initialized!" << endl;
	}
}

void Order::SetOrderState(int state)
{
	this->orderState = state;
}

int Order::GetOrderState()
{
	return this->orderState;
}

void Order::SetOProduct(shared_ptr<Product> oProduct)
{
	this->oProduct = oProduct;
}

shared_ptr<Product> Order::GetOProduct()
{
	return this->oProduct;
}
