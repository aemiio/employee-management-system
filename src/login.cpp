#include "../include/login.h"

void loginMenu() {
    cout << "[1] Admin" << endl;
    cout << "[2] User" << endl;
    cout << "[3] Exit" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            adminLogin();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            cout << "Exiting..." << endl;
            exit(0);
        default:
            cout << "Wrong Input!" << endl;
    }
}

void adminLogin() {
    char adminU[20] = "admin";
    char adminP[20] = "admin";

    char u[20], p[20];
    bool isadminLogged = false;

    while (!isadminLogged) {
        cout << "Username: " << endl;
        cin >> u;
        cout << "Password: " << endl;
        cin >> p;

        if ((strcmp(u, adminU) == 0) && (strcmp(p, adminP) == 0)) {
            cout << "Admin Login Successful" << endl;
            isadminLogged = true;
            adminMenu();
            return;

        } else {
            cout << "Incorrect Username or Password!" << endl;
            tries++;

            if (tries > 3) {
                cout << "Temporarily Banned!" << endl;
                isadminLogged = false;
                loginMenu();
                return;
            }
        }
    }

}

void userLogin() {
    char u[20], p[20];
    bool login = false;


    while (true) {
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        for (i = 0; i <= accNum; i++) {
            if ((strcmp(u, username[i]) == 0) && (strcmp(p, password[i]) == 0)) {
                if (banned[logged] == 1) {
                    cout << " Account is Temporarily Banned!\n";
                    loginMenu();
                    return;
                }
                login = true;
                logged = i;
            }

        }

        if (login) {
            cout << "User Login Successful" << endl;
            userMenu();
            return;
        } else {
            cout << "Incorrect Username or Password!\n";
            tries++;

            if (tries > 3) {
                cout << "Temporarily Banned!\n";
                banned[logged] = 1;
                loginMenu();
                return;
            }
        }
    }
}



