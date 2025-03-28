#include "Server.h"

Server::Server()
{
	this->idpw = new map<string,string>;
	this->members = new vector<Customer*>;
	this->products = new vector<shared_ptr<Product>>;
	MakeProducts();
}

Server::~Server()
{
}

void Server::AddNewMembers(string id, string pw, unique_ptr<Customer> newCustomer)
{	//아이디 중복 처리!!!
	idpw->insert({ id,pw });
	Customer* addCustomer = newCustomer.release();
	members->push_back(addCustomer);
}

void Server::AddMember(unique_ptr<Customer> customer)
{
	Customer* addCustomer = customer.release();
	members->push_back(addCustomer);
}

bool Server::Login(string id, string pw)
{
	//if(this->members->find(id)!= this->members->end(id))
	for (int i = 0;i < idpw->size();i++)
	{
		if (idpw->find(id)!=idpw->end())
		{
			if ((*idpw)[id] == pw) {
				return true;
			}
			else
			{
				cout << "패스워드가 잘못되었습니다." << endl;
				return false;
			}
		}
		else
		{
			cout << "아이디가 잘못되었습니다." << endl;
			return false;
		}
	}
	cout << "로그인에 실패하였습니다." << endl;
	return false;
}

unique_ptr<Customer> Server::FindCustomer(string id)//무조건 이 함수로 members 접근
{
	for (int i = 0;i < members->size();i++)
	{
		if (members->at(i)->GetId()==id)
		{
			//unique_ptr<Customer> returnCustomer(move(members->at(i)));//Customer delete 되나???????
			unique_ptr<Customer> returnCustomer = make_unique<Customer>(*(members->at(i))); //복제됨
			//members->erase(members->begin()+i); //빼지 않기로 함
			return move(returnCustomer);//?????(*(members->at(i)))?
		}
	}
	cout << "회원정보가 없습니다." << endl;
	return nullptr;
}

shared_ptr<Product> Server::FindProduct(int num)
{	
	return products->at(num);
}

void Server::PrintProducts()
{
	cout << "No." << '\t' << "상품명" << '\t\t' << "가격" << '\t' << "재고" << endl << endl;
	for (int i = 0;i < products->size();i++)
	{
		cout << i << '\t' << products->at(i)->GetName() << '\t' <<
			products->at(i)->GetPrice() << '\t' << products->at(i)->GetStock() << endl;
	}
	cout << endl;
}


class Compare
{
	
};


void Server::MakeProducts()
{
	for (int i = 0;i < 5;i++)
	{
		shared_ptr<Product> newProduct = make_shared<Product>("Galaxy"+to_string(i+1),i,i);
		cout << "made product and count is: " << newProduct.use_count() << endl;
		this->products->push_back(newProduct);
		cout << "push product and count is: " << newProduct.use_count() << endl << endl;
	}	
}


