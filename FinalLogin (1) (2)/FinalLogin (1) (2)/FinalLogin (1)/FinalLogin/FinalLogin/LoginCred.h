#pragma once

#include <string>

struct LoginCred {
	char username[50]; // ClientName
	char password[50]; // Password
	bool purpose; // true for signin, false for signup
};