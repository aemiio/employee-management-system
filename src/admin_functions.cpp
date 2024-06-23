
#include "../include/admin_functions.h"

void adminMenu() {
    cout << endl;
    cout << "+===Menu===+\n";
    cout << "[1] View Accounts\n";
    cout << "[2] Create Employees\n";
    cout << "[3] Search Accounts\n";
    cout << "[4] Deposit Salary\n";
    cout << "[5] Log Out";
    cout << endl;
    cout << "[!] Enter Number: ";
    cin >> choice;

    switch (choice) {
        case 1:
            viewAcc();
            break;
        case 2:
            createEmp();
            break;
        case 3:
            searchAcc();
            break;
        case 4:
            depositSalary();
            break;
        case 5:
            cout << "Logging out..." << endl;
            loginMenu();
            break;
        default:
            cout << "Wrong Input!" << endl;
            break;
    }
}

void viewAcc() {
    cout << endl;
    cout << "Viewing " << accNum << " Employee Accounts" << endl;

    // column titles
    cout << setw(10) << left << "ID No.";
    cout << setw(18) << left << "Employee Type";
    cout << setw(16) << left << "Username";
    cout << setw(15) << left << "Balance";
    cout << setw(25) << left << "First Name";
    cout << setw(25) << left << "Last Name" << endl;

    //separator line
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');

    for (i = 0; i < accNum; i++) {
        cout << setw(10) << left << idNum[i]
             << setw(18) << left << empType[i]
             << setw(16) << left << username[i]
             << setw(15) << left << balance[i]
             << setw(25) << left << fName[i]
             << setw(25) << left << lName[i] << endl;
    }

    cout << endl;
    cout << "[1] Go back to Menu\n";
    cout << "[2] Log Out\n";
    cin >> choice;

    if (choice == 1) adminMenu();
    else loginMenu();
}

void createEmp() {
    cout << endl;
    cout << "Creating New Employee Account..." << endl;

    char u[20], p[20], firstn[20], lastn[20];
    char type[20];

    a:
    cout << "Username: " << endl;
    cin >> u;

    for (i = 0; i < accNum; i++) {
        if (strcmp(u, username[i]) == 0) {
            cout << "Username already exists!\n";
            goto a;
        }
    }

    cout << "Password: " << endl;
    cin >> p;

    cin.ignore();
    cout << "Choose Employee Type: " << endl;
    cout << "Admin Officer, Utility, Secretary, Admin Aide\n";
    cin.getline(type, 20);

    b:
    cout << "First Name: " << endl;
    cin >> firstn;
    cout << "Last Name: " << endl;
    cin >> lastn;

    for (i = 0; i < accNum; i++) {
        if (strcmp(firstn, fName[i]) == 0 && (strcmp(lastn, lName[i]) == 0)) {
            cout << "Employee already exists!\n";
            goto b;
        }
    }

    strcpy(username[accNum], u);
    strcpy(password[accNum], p);
    strcpy(empType[accNum], type);
    strcpy(fName[accNum], firstn);
    strcpy(lName[accNum], lastn);

    banned[accNum] = 0;
    balance[accNum] = 0;
    accNum++;

    cout << "Successful Account Registration!\n";
    adminMenu();
}

void searchAcc() {
    string u;

    cout << endl;
    cout << "Search Account..." << endl;
    cout << "Enter Username: " << endl;
    cin >> u;

    bool found = false;

    for (i = 0; i < accNum; i++) {
        if (u == username[i]) {
            found = true;

            cout << setw(10) << left << "ID No.";
            cout << setw(16) << left << "Username";
            cout << setw(25) << left << "First Name";
            cout << setw(25) << left << "Last Name" << endl;

            cout << setfill('-') << setw(100) << "-" << endl;
            cout << setfill(' ');

            cout << setw(10) << left << idNum[i]
                 << setw(16) << left << username[i]
                 << setw(25) << left << fName[i]
                 << setw(25) << left << lName[i] << endl;
            break;
        }
    }

    if (!found) cout << "Employee not found!\n";
    adminMenu();
}

void depositSalary() {
    int id;
    int hrs;

    cout << endl;
    cout << "Deposit Salary" << endl;
    cout << endl;
    cout << "Viewing " << accNum << " Employee Accounts" << endl;

    // column titles
    cout << setw(10) << left << "ID No.";
    cout << setw(18) << left << "Employee Type";
    cout << setw(16) << left << "Username";
    cout << setw(15) << left << "Balance";
    cout << setw(25) << left << "First Name";
    cout << setw(25) << left << "Last Name" << endl;

    //separator line
    cout << setfill('-') << setw(100) << "-" << endl;
    cout << setfill(' ');

    for (i = 0; i < accNum; i++) {
        cout << setw(10) << left << idNum[i]
             << setw(18) << left << empType[i]
             << setw(16) << left << username[i]
             << setw(15) << left << balance[i]
             << setw(25) << left << fName[i]
             << setw(25) << left << lName[i] << endl;
    }

    cout << endl;

    cout << "Enter ID No. to deposit: \n";
    cin >> id;

    for (i = 0; i < accNum; i++) {
        if (id != idNum[i]) {
            continue;
        }
        cout << "Id No.: " << idNum[i] << endl;
        cout << "Username: " << username[i] << endl;
        cout << "Employee Type: " << empType[i] << endl;
        cout << "Enter no. of hours worked: \n";
        cin >> hrs;

        cout << "Enter employee type: \n";
        cout << "[1] Utility \n[2] Admin Aide \n[3] Secretary \n[4] Admin Officer\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Utility = 80/hour" << endl;
                balance[i] += 80 * hrs;
                cout << balance[i] << " has been added to " << username[i] << "!" << endl;
                adminMenu();
                break;
            case 2:
                cout << "Admin Aide = 100/hour" << endl;
                balance[i] += 100 * hrs;
                cout << balance[i] << " has been added to " << username[i] << "!" << endl;
                adminMenu();
                break;
            case 3:
                cout << "Secretary = 120/hour" << endl;
                balance[i] += 120 * hrs;
                cout << balance[i] << " has been added to " << username[i] << "!" << endl;
                adminMenu();
                break;
            case 4:
                cout << "Admin Officer = 200/hour" << endl;
                balance[i] += 200 * hrs;
                cout << balance[i] << " has been added to " << username[i] << "!" << endl;
                adminMenu();
                break;
            default:
                cout << endl;
                cout << "Wrong Input!";
                adminMenu();
        }


    }


}