#pragma once
#include <iostream>

using namespace std;

class Administrator
{
private:
	const string adminID = "admin";
	const string adminPW = "1234";
	int* auth; //시간제한 // checker?

public:
	Administrator();

	int Validation(string id, string pw);
};