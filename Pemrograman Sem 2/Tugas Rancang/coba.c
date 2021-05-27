#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void main(){
char luser, lpass;
int user1,user2,pass1,pass2;
printf("Username : ");
scanf("%s", &luser);
printf("Pass : ");
scanf("%s", &lpass);

user1=strcmp(luser, "fandi");
pass1=strcmp(lpass, "fann");
//user2=strcmp(luser, "james");
//pass2=strcmp(lpass, "jamm");

if (user1 || user2 != 0){
		printf("Username Salah\n");
		system("pause");
		system("cls");
		loginpage();
	}
	else if (pass1 || pass2 != 0){
		printf("Password Salah\n");
		system("pause");
		system("cls");
		loginpage();
	}
	else {
		system("cls");
	}

}
    	
	