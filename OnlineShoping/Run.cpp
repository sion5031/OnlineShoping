#include <conio.h>
#include <Windows.h>

#include "Server.h"
#include "Customer.h"
#include "Order.h"
#include "Product.h"


void Print(string str);
void PrintL(string str);
void LPrintL(string str);


int main()
{
	unique_ptr<Server> server = make_unique<Server>();

	while (true) {
		char t;
		LPrintL("고객 로그인: 1\n\n관리자 로그인 2\n");
		Print("번호 : ");
		t = _getche();
		system("cls");

		if (t == '1')
		{
			char t1;
			unique_ptr<Customer> customerPtr; //위치???????
			string id = "", pw = "", name, email;
			LPrintL("안녕하세요. SWS몰에 오신 것을 환영합니다.");
			LPrintL("메뉴를 선택해주세요.");
			LPrintL("1. 로그인\n\n2. 회원가입\n");
			Print("번호 : ");
			t1 = _getche();
			system("cls");

			if (t1 == '2')
			{
				LPrintL("회원가입을 진행합니다.");
				Print("아이디를 입력해주세요 : ");
				cin >> id;
				Print("패스워드를 입력해주세요 : ");
				cin >> pw;
				Print("이름을 입력해주세요 : ");
				cin >> name;
				Print("이메일을 입력해주세요 : ");
				cin >> email;
				customerPtr = make_unique<Customer>(id, name, email);
				server->AddNewMembers(id, pw, move(customerPtr));
				system("cls");
				LPrintL("회원가입이 완료되었습니다.\n\n로그인 창으로 이동합니다.");
				Sleep(1000);

				continue;
			}
			else if (t1 == '1')
			{
				LPrintL("로그인을 진행합니다.");
				Print("아이디를 입력해주세요 : ");
				cin >> id;
				Print("패스워드를 입력해주세요 : ");
				cin >> pw;
				if (server->Login(id, pw)) {
					customerPtr = move(server->FindCustomer(id));
					system("cls");
					LPrintL("로그인에 성공하였습니다.");
					Sleep(1000);
				}
				else
				{
					continue;
				}
				
				//여기 시작이 맞는가?????
				while (true)
				{
					char t2;

					system("cls");
					cout << customerPtr->GetName() << " 님의 메뉴" << endl << endl;
					LPrintL("1. 쇼핑\n\n2. 주문목록\n\n3. 로그아웃\n\n");
					Print("번호 : ");

					t2 = _getche();

					if (t2 == '1')
					{
						system("cls");
						int orderNum;
						server->PrintProducts();
						LPrintL("원하는 상품 번호를 입력하면 주문이 완료 됩니다.\n");
						Print("번호 : ");
						cin >> orderNum;
						cin.ignore();

						shared_ptr<Order> newOrder = make_shared<Order>();
						newOrder->SetOProduct(server->FindProduct(orderNum));//예외처리
						newOrder->SetOrderNum(customerPtr->GetOrderSize());


						customerPtr->ProceedOrder();
						customerPtr->AddOrder(newOrder);

						LPrintL("주문이 완료되었습니다.");

						continue;
					}
					else if (t2 == '2')
					{
						system("cls");
						customerPtr->PrintOrders();
						LPrintL("계속하려면 Enter를 누르세요.");
						cin.ignore();
						continue;
					}
					else if (t2 == '3')
					{
						system("cls");
						break;
					}
					else {
						continue;
					}







				}
			}


		}
		else if (t == '2') //관리자 로그인
		{

		}

		else
		{
			LPrintL("잘못 입력하셨습니다.");
			continue;
		}











	}

}


void Print(string str)
{
	cout << str;
}
void PrintL(string str)
{
	cout << str << endl;
}
void LPrintL(string str)
{
	cout << endl << str << endl;
}