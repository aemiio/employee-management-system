#ifndef login_h
#define login_h

#include <iostream>
#include <cstring>
#include "../include/admin_functions.h"
#include "../include/user_functions.h"

using namespace std;

void loginMenu();

void adminLogin();

void userLogin();

extern int accNum;
extern int idNum[20];
extern char empType[50][20];
extern char username[50][20];
extern char password[50][20];
extern int balance[];
extern char fName[50][20];
extern char lName[50][20];
extern int banned[50];
extern int choice;
extern int logged;
extern int tries;
extern int i;

#endif
