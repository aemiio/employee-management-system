#include "..//include/login.h"

int accNum = 5;
int idNum[20] =
        {1, 2, 3, 4, 5};
char empType[50][20] =
        {"Admin Officer", "Utility", "Utility", "Secretary", "Admin Aide"};
char username[50][20] =
        {"jose", "wally", "paolo", "Vic", "joey"};
char password[50][20] =
        {"1111", "2222", "3333", "4444", "5555"};
int balance[] =
        {0, 0, 0, 0, 0};
char fName[50][20] =
        {"Jose", "wally", "paolo", "Vic", "Joey"};
char lName[50][20] =
        {"manalo", "bayola", "balesteros", "sotto", "deleon"};
int banned[50] = {0};
int choice = 0;
int logged= 0;
int tries = 0;
int i = 0;

int main() {
    loginMenu();
}