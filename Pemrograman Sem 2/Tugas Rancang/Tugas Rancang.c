#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ESC 27

FILE *login;
int userbenar; passbenar; pilihan; jml;
char user[50]; char pass[50]; char luser[50]; char lpass[50];

void getpassword(){
	FILE *login;
	login=fopen("user.txt","r");
	fscanf(login, "%s", user);
	fscanf(login, "%s", pass);
	fclose(login);
}
void loginpage(){
	getpassword();
	printf("========================================\n");
	printf("=              Login Page              =\n");
	printf("========================================\n\n");
	printf("Username : ");
	scanf("%s", &luser);
	printf("Password : ");
	scanf("%s", &lpass);
	userbenar=strcmp(luser, user);
	passbenar=strcmp(lpass, pass);
}

void mainmenu(){
	printf("========================================\n");
	printf("=               Main Menu              =\n");
	printf("========================================\n");
	printf("\n1. Transaksi");
	printf("\n2. Cek Barang");
	printf("\n3. Keluar");
	printf("\nMasukan Pilihan : ");
	scanf("%d", &pilihan);
}

void menupilih(){
	switch (pilihan){
		case 1 :
			system("cls");
			transaksi();
			break;
		case 2 :
			system("cls");
			cekbarang();
			break;
		case 3 :
			exit(0);	
	}
}

void transaksi(){
	printf("========================================\n");
	printf("=               Transaksi              =\n");
	printf("========================================\n\n");
	char huruf;
	int trans[100][100];
	int kode[100];
	int harga[100];
	char x;
	
	FILE *tr;
	FILE *fp;
	FILE *tl;
	int i, j, k, l;
	char delim[] = ";";
	char tampung[200][10][200];
	char line[200];
	
	printf("Data List Barang\n\n");
	
	fp = fopen("database.txt", "r");

		i = 0;

		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		j = 0;
			while (token != NULL) {
				strcpy(tampung[i][j], token);
				
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;  
		}
		

			printf("Kode : %s \n", tampung[k][0]);
		    printf("Nama  : %s \n", tampung[k][1]);
		    printf("Harga : Rp.%s \n", tampung[k][2]);
		    printf("Stok : %s \n", tampung[k][3]);
		    printf("Total Harga : Rp %d \n", atoi(tampung[k][2]) * atoi(tampung[k][3]));
		    printf("====================\n");
		
	

	
	printf("Masukan jumlah menu yang di beli : ");
	scanf("%d", &jml);
	
	for(j = 0; j < jml; j++) {
		printf("=============\n");
		printf("Kode : ");
		scanf("%d", &kode[j]);
		x = kode[j];
		printf("Total : ");
		scanf("%d", &trans[kode[j]-1][0]);
	}
	                             
	for (k=0; k<i; k++){ 
		tr = fopen("tmp.txt","w"); 
		fprintf(tr, "%d", atoi(tampung[kode[k]-1][3])-trans[kode[k]-1][0]);
		fclose(tr); 
		
		tl = fopen("total.txt", "a+");
		fprintf(tl, "%s;%s;%d;%d;\n", tampung[kode[k]-1][1], tampung[kode[k]-1][2], trans[kode[k]-1][0], atoi(tampung[kode[k]-1][2])*trans[kode[k]-1][0]);
		fclose(tl);
		
		tr = fopen("tmp.txt", "r");
		fscanf(tr, "%s", tampung[kode[k]-1][3]);
		fclose(tr);  
    
	}
	
	fp = fopen("database.txt","w");
	for (k=0; k < i; k++) {
		fprintf(fp, "%s;%s;%s;%s;", tampung[k][0], tampung[k][1], tampung[k][2], tampung[k][3]);
		fprintf(fp, "\n");
	}
	fclose(fp);
	
	printf("\n==================== Transaksi Berhasil! ====================\n\n");
	system("pause>nul | echo Klik Enter untuk melihat struk");
	system ("cls");
	struk();
}

void struk(){
	printf("========================================\n");
	printf("=            Struk Pembelian           =\n");
	printf("========================================\n\n");
	
	char line[200], file_name[] = "total.txt";
	FILE *fp;
	int i, j, k;
	
	char delim[] = ";";
	char total[200][4][200];
	
	fp = fopen(file_name, "r");

	
		i = 0;
		
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		j = 0;
			while (token != NULL) {
				strcpy(total[i][j], token);
			
				token = strtok(NULL, delim);
				j++;
		
			}
			
			i++;  
		
		}
		
		for (k = 0; k < jml; k++) {
		    printf("Nama : %s \n", total[k][0]);
		    printf("Harga  :Rp.%s \n", total[k][1]);
		    printf("Jumlah : %s \n", total[k][2]);
		    printf("Total Harga : Rp.%s \n", total[k][3]);
		    printf("====================\n");
		}
   			printf("\n========================================\n");
   			printf("Jumlah yang harus dibayar : Rp.%d", atoi(total[0][3]) + atoi(total[1][3]) + atoi(total[2][3]) + atoi(total[3][3]) + atoi(total[4][3]) + atoi(total[5][3]) + atoi(total[6][3]) + atoi(total[7][3]) + atoi(total[8][3]) + atoi(total[9][3]) + atoi(total[10][3]) + atoi(total[11][3]) + atoi(total[12][3]) + atoi(total[13][3]) + atoi(total[14][3]) + atoi(total[15][3]) + atoi(total[16][3]) + atoi(total[17][3]) + atoi(total[18][3]) + atoi(total[19][3]) + atoi(total[20][3]) + atoi(total[21][3]) + atoi(total[22][3]) + atoi(total[23][3]) + atoi(total[24][3]));
   			printf("\n========================================\n\n");
   			
	fclose(fp);
	
		
	fp = fopen("total.txt","w");
	fprintf(fp, "");
	fclose(fp);
	
	
	system("pause>nul | echo Klik Enter untuk kembali!");
	system("cls");
	mainmenu();
}

void cekbarang(){
	printf("========================================\n");
	printf("=           List Data Barang           =\n");
	printf("========================================\n\n");
	char line[200], file_name[] = "database.txt";
	FILE *fp;
	int i, j, k;
	char delim[] = ";";
	char tampung[200][10][200];
	
	printf("Data List Barang\n\n");
	
	fp = fopen(file_name, "r");

	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(EXIT_FAILURE);
	} else {
		i = 0;

		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		j = 0;
			while (token != NULL) {
				strcpy(tampung[i][j], token);
				
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;  
		}
		
		printf("===========================================================================\n");
		printf("  Kode    Nama\t\t\t\t\tHarga                Stok\n");
		printf("===========================================================================\n");
		
		for (k = 0; k < i; k++) {
			printf("   %s", tampung[k][0]);
		    printf("      %s", tampung[k][1]);
		    printf("\t\t\t\tRp. %s", tampung[k][2]);
		    printf("\t      %s\n", tampung[k][3]);
		}
		
		printf("===========================================================================\n\n");
		
		printf("====Edit Barang====\n\n1. Tambah Barang\n2. Edit Barang\n3. Hapus Barang\n");
		printf("\nMasukan Pilihan : ");
		scanf("%d", &pilihan);
		switch (pilihan){
			case 1 :
				system("cls");
				tambah();
				break;
			case 2 :
				system("cls");
				ganti();
				break;
			case 3 :
				
			default :
				printf("Pilihan tidak ada!");
				cekbarang();
		}
	}
	
}
void tambah(){
	printf("========================================\n");
	printf("=             Tambah Barang            =\n");
	printf("========================================\n\n");
	
		int kode; char nama; int harga; int stok; char line[200];
		FILE *barang;
	
		barang = fopen("database.txt","a+");
		printf("Edit stok barang\n");
		printf("Masukan Kode \t: ");
		scanf("%d", &kode);
		printf("Masukan Harga \t\t\t: ");
		scanf("%d", &harga);
		printf("Masukan Stok \t\t\t: ");
		scanf("%d", &stok);
		printf("Masukan Nama \t\t\t: ");
		scanf("%s", &nama);
	
		
		
		fclose(barang);
	
		printf("\nBarang Sukses Ditambahkan\n");
		system("pause>nul | echo Klik terserah untuk lanjut");
			system ("cls");
			cekbarang();
	}	
void ganti(){
	printf("========================================\n");
	printf("=             Ganti Barang             =\n");
	printf("========================================\n\n");
	
	int baris;
	char line[200], file_name[] = "database.txt";
	FILE *fp;
	int i, j, k;
	char delim[] = ";";
	char tampung[200][10][200];

	fp = fopen("database.txt", "r");

	i = 0;

	while (fgets(line, sizeof(line), fp) != NULL) {
		char *token = strtok(line, delim);
    		
   		j = 0;
		while (token != NULL) {
			strcpy(tampung[i][j], token);
			
			token = strtok(NULL, delim);
			j++;
		}
		
		i++;  
	}
	
	fclose(fp);
	
	printf("Edit barang\n");
	printf("Masukan baris : ");
	scanf("%d", &baris);
	k=baris-1;
	
	printf("Nama  : %s \n", tampung[k][1]);
    printf("Harga : Rp %s \n", tampung[k][2]);
    printf("Stok : %s \n", tampung[k][3]);
    printf("Total Harga : Rp %d \n", atoi(tampung[k][2]) * atoi(tampung[k][3]));
    printf("====================\n");
    
    printf("\nUbah data!\n");
    printf("Nama : ");
	scanf("%s", &tampung[k][1]);
	printf("Harga : ");
	scanf("%s", &tampung[k][2]);
	printf("Stok : ");
	scanf("%s", &tampung[k][3]);
	
	fp = fopen("database.txt","w");
	for (k=0; k < i; k++) {
		fprintf(fp, "%s;%s;%s;%s;", tampung[k][0], tampung[k][1], tampung[k][2], tampung[k][3]);
		fprintf(fp, "\n");
	}
		
	fclose(fp);
		
	printf("\nBarang Sukses Diperbarui\n");
	system("pause>nul | echo Klik apa saja untuk lanjut");
	system ("cls");
	
	cekbarang();
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
	else if (passbenar != 0){
		printf("Password Salah\n");
		system("pause");
		system("cls");
		loginpage();
	}
	else {
		system("cls");
		mainmenu();
	}
	menupilih();
}