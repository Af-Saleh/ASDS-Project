#include <stdio.h>
#include "UI.h"
#define red     "\033[31m"
#define green   "\033[32m"
#define yellow  "\033[33m"
#define blue    "\033[34m"
#define cyan    "\033[36m"
#define reset   "\033[0m"
#define white   "\033[37m"
#define bold    "\033[1m"

int account_menu()
{
    char *menu[] = {"Log in",
                    "Sign in",
                    "Exit"};
    return menus(51, menu , 3 , "Login" , blue , white , green , white);
}

int main(){
    account_menu();
}