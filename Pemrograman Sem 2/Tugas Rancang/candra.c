#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *login;
int userbenar; int passbenar; int pilihan;
char user[50]; char pass[50]; char luser[50]; char lpass[50];

void getpassword(){
	FILE *login;
	login=fopen("user.txt","r");
	fscanf(login, "%s", user);
	fscanf(login, "%s", pass);
	fclose(login);
}
void readpass(char *);
void loginpage(){
	readpass(lpass);
	getpassword();
	printf("Login Page\n");
	printf("Username : ");
	scanf("%s", &luser);
	printf("Password : ");
	scanf("%s", &lpass);
	userbenar=strcmp(luser, user);
	passbenar=strcmp(lpass, pass);
}

void main(){
	getpassword();
	loginpage();
	if (userbenar != 0){
		printf("Username Salah\n");
		system("pause");
		system("cls");
		loginpage();
	}
	
	else{
		printf("yy");
	}
}