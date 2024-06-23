#include "../include/user_functions.h"

void userMenu() {
    cout << endl;
    cout << "Welcome " << fName[logged] << " " << lName[logged] <<  " | " << empType[logged] << endl;
    cout << "[1] View Balance\n";
    cout << "[2] Withdraw Money\n";
    cout << "[3] Edit Profile\n";
    cout << "[4] Exit\n";
    cout << "[!] Enter Number:";
    cin >> choice;

    switch (choice) {
        case 1:
            viewBalance();
            break;
        case 2:
            withdrawMoney();
            break;
        case 3:
            editProfile();
            break;
        case 4:
            cout << "Log Out" << endl;
            loginMenu();
        default:
            cout << "Wrong Input!\n";
            userMenu();
    }
}

void viewBalance() {
    cout << endl;
    cout << "Viewing Balance:\n";
    cout << "Balance is P" << balance[logged];

    cout << endl;
    cout << "[1] Go back to menu\n [2] Log Out\n";
    cin >> choice;

    if (choice == 1) userMenu();
    if (choice == 2) loginMenu();
}

void withdrawMoney() {
    int money;
    cout << endl;
    cout << "Viewing Balance:\n";
    cout << "Balance is P" << balance[logged];

    cout << endl;
    cout << "[1] Withdraw Cash\n [2] Exit";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter cash to withdraw: " << endl;
        cin >> money;

        if (money <= balance[logged]) {
            balance [logged] -= money;
        }
        else {
            cout << "Insufficient Funds!" << endl;
            userMenu();
        }
    }
}

void editProfile() {
    char u[20], p[20];

    cout << endl;
    cout << "Edit Profile\n";
    cout << "[1] Edit Username\n [2] Edit Password\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter new username:" << endl;
        cin >> u;

        strcpy(username[logged], u);
        cout << "Username updated!\n";
        userMenu();
    }
    else if (choice == 2) {
        cout << "Enter new password:" << endl;
        cin >> p;

        strcpy(password[logged], p);
        cout << "Password updated!\n";
        userMenu();
    }
    else {
        cout << "Wrong Input!" << endl;
        userMenu();
    }
}
