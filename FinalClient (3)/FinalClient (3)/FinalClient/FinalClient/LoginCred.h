#pragma once
#include<string>
using namespace std;

struct LoginCred {

	char username[50];
	char password[50];

	//value=1 for sign in , value =0 for sign up
	bool purpose;
};