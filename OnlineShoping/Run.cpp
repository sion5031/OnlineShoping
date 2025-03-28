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
		LPrintL("�� �α���: 1\n\n������ �α��� 2\n");
		Print("��ȣ : ");
		t = _getche();
		system("cls");

		if (t == '1')
		{
			char t1;
			unique_ptr<Customer> customerPtr; //��ġ???????
			string id = "", pw = "", name, email;
			LPrintL("�ȳ��ϼ���. SWS���� ���� ���� ȯ���մϴ�.");
			LPrintL("�޴��� �������ּ���.");
			LPrintL("1. �α���\n\n2. ȸ������\n");
			Print("��ȣ : ");
			t1 = _getche();
			system("cls");

			if (t1 == '2')
			{
				LPrintL("ȸ�������� �����մϴ�.");
				Print("���̵� �Է����ּ��� : ");
				cin >> id;
				Print("�н����带 �Է����ּ��� : ");
				cin >> pw;
				Print("�̸��� �Է����ּ��� : ");
				cin >> name;
				Print("�̸����� �Է����ּ��� : ");
				cin >> email;
				customerPtr = make_unique<Customer>(id, name, email);
				server->AddNewMembers(id, pw, move(customerPtr));
				system("cls");
				LPrintL("ȸ�������� �Ϸ�Ǿ����ϴ�.\n\n�α��� â���� �̵��մϴ�.");
				Sleep(1000);

				continue;
			}
			else if (t1 == '1')
			{
				LPrintL("�α����� �����մϴ�.");
				Print("���̵� �Է����ּ��� : ");
				cin >> id;
				Print("�н����带 �Է����ּ��� : ");
				cin >> pw;
				if (server->Login(id, pw)) {
					customerPtr = move(server->FindCustomer(id));
					system("cls");
					LPrintL("�α��ο� �����Ͽ����ϴ�.");
					Sleep(1000);
				}
				else
				{
					continue;
				}
				
				//���� ������ �´°�?????
				while (true)
				{
					char t2;

					system("cls");
					cout << customerPtr->GetName() << " ���� �޴�" << endl << endl;
					LPrintL("1. ����\n\n2. �ֹ����\n\n3. �α׾ƿ�\n\n");
					Print("��ȣ : ");

					t2 = _getche();

					if (t2 == '1')
					{
						system("cls");
						int orderNum;
						server->PrintProducts();
						LPrintL("���ϴ� ��ǰ ��ȣ�� �Է��ϸ� �ֹ��� �Ϸ� �˴ϴ�.\n");
						Print("��ȣ : ");
						cin >> orderNum;
						cin.ignore();

						shared_ptr<Order> newOrder = make_shared<Order>();
						newOrder->SetOProduct(server->FindProduct(orderNum));//����ó��
						newOrder->SetOrderNum(customerPtr->GetOrderSize());


						customerPtr->ProceedOrder();
						customerPtr->AddOrder(newOrder);

						LPrintL("�ֹ��� �Ϸ�Ǿ����ϴ�.");

						continue;
					}
					else if (t2 == '2')
					{
						system("cls");
						customerPtr->PrintOrders();
						LPrintL("����Ϸ��� Enter�� ��������.");
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
		else if (t == '2') //������ �α���
		{

		}

		else
		{
			LPrintL("�߸� �Է��ϼ̽��ϴ�.");
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