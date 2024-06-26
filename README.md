# Employee Management System

This project is a simple console-based Employee Management System written in C++. It provides basic functionalities for
an admin to manage employee accounts and for employees to manage their profiles and view their account balances.

## Features

### Admin Features:

1. **View Accounts**: Display all employee accounts with details such as ID, employee type, username, balance, and
   names.
2. **Create Employees**: Add new employee accounts ensuring unique usernames and names.
3. **Search Accounts**: Find an employee account by username.
4. **Deposit Salary**: Deposit salary based on hours worked and employee type.
5. **Log Out**: Log out from the admin session.

### User Features:

1. **View Balance**: View the current balance in the user's account.
2. **Withdraw Money**: Withdraw a specified amount of money from the user's account, ensuring sufficient balance.
3. **Edit Profile**: Update username or password.
4. **Log Out**: Log out from the user session.

## Code Structure

- **admin_functions.h**: Header file containing declarations for admin-related functions.
- **login.h**: Header file for login-related functions.
- **user_functions.h**: Header file for user-related functions.


## Function Details

### Admin Functions

- `adminMenu()`: Displays the admin menu and handles user input for various admin operations.
- `viewAcc()`: Shows all employee accounts.
- `createEmp()`: Adds a new employee account.
- `searchAcc()`: Searches for an employee account by username.
- `depositSalary()`: Deposits salary to an employee account based on hours worked.

### User Functions

- `userMenu()`: Displays the user menu and handles user input for various user operations.
- `viewBalance()`: Displays the current balance of the logged-in user.
- `withdrawMoney()`: Allows the user to withdraw money from their account.
- `editProfile()`: Allows the user to update their username or password.

### Login Functions

- `loginMenu()`: Displays the login menu for admin or user login.
- `adminLogin()`: Handles the admin login process.
- `userLogin()`: Handles the user login process.
