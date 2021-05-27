#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Variabel

FILE *login;
int userbenar, passbenar, jml, pilih;
int pilihan;
char luser[50]; char lpass[50]; char user[10][5][10]; char pass[];
char huruf;
char yn;
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
char total[200][10][200];
char line[200];
int code; char name[200]; int price; int stock; int baris;
FILE *barang;

// Getdata

void getdata() {
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
}

void gettotal(){
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
}

void showdata(){
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
}

// Database

void tambah(){
	printf("===========================================================================\n");
	printf("=                                Tambah Barang                             =\n");
	printf("===========================================================================\n\n");
	
	barang = fopen("database.txt","a+");
	printf("Edit stok barang\n");
		printf("Masukan Kode \t: ");
		scanf("%d", &code);
		printf("Masukan Nama \t: ");
		scanf("%s", &name);
		printf("Masukan Harga \t: ");
		scanf("%d", &price);
		printf("Masukan Stok \t: ");
		scanf("%d", &stock);
		
		fprintf(barang, "\n%d;%s;%d;%d;", code, name, price,stock);
	
		fclose(barang);
	
		printf("\nBarang Sukses Ditambahkan\n");
		system("pause>nul | echo Klik terserah untuk lanjut");
			system ("cls");
			cekbarang();
}

void ganti(){
	printf("===========================================================================\n");
	printf("=                                Ganti Barang                             =\n");
	printf("===========================================================================\n\n");
	
	fp = fopen("database.txt","r");
	
	getdata();
	
	fclose(fp);
	
	showdata();
	
	printf("Edit barang\n");
	printf("Masukan kode : ");
	scanf("%d", &baris);
	k=baris-1;

    
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

void hapus(){
	printf("===========================================================================\n");
	printf("=                                 Hapus Barang                            =\n");
	printf("===========================================================================\n\n");
	
	fp = fopen("database.txt", "r");
	
	getdata();
	showdata();
	
	fclose(fp);
	
	printf("Masukan baris : ");
	scanf("%d", &baris);
	k=baris-1;
	
	awal :
	printf("Nama  : %s \n", tampung[k][1]);
    printf("Harga : Rp %s \n", tampung[k][2]);
    printf("Stok : %s \n", tampung[k][3]);
    printf("Total Harga : Rp %d \n", atoi(tampung[k][2]) * atoi(tampung[k][3]));
    printf("====================\n");
    
    printf("\nHapus Data!\n");
    printf("Apakah anda yakin ingin menghapus barang ini ? (Y/N) : ");
    scanf("%s", &yn);
    if (yn == 'y') {
    	
    	fp = fopen("database.txt","w");
   		for (k=0; k < baris-1; k++) {
			fprintf(fp, "%s;%s;%s;%s;", tampung[k][0], tampung[k][1], tampung[k][2], tampung[k][3]);
			fprintf(fp, "\n");
		}
		fclose(fp);
		
		fp = fopen("database.txt","a+");
		for (k = baris; k < i; k++) {
			fprintf(fp, "%d;%s;%s;%s;", atoi(tampung[k][0])-1, tampung[k][1], tampung[k][2], tampung[k][3]);
			fprintf(fp, "\n");
		}
		fclose(fp);
		
		printf("\nData Berhasil Di hapus!\n");
		system("pause>nul | echo Klik Enter untuk Kembali");
		system ("cls");
	
		cekbarang();
	}
	else if (yn == 'n') {
		printf("Penghapusan barang dibatalkan!");
	}
	else {
		printf("Inputan salah\n");
		system("pause>nul | echo Klik enter untuk ulangi");
		system("cls");
		goto awal;
		}
}

void cekbarang(){
	printf("===========================================================================\n");
	printf("=                               List Data Barang                          =\n");
	printf("===========================================================================\n\n");
	
	fp = fopen("database.txt", "r");
	
	getdata();
	showdata();
	
	printf("====Edit Barang====\n\n1. Tambah Barang\n2. Edit Barang\n3. Hapus Barang\n");
		printf("\nMasukan Pilihan : ");
		scanf("%d", &pilih);
		switch (pilih){
			case 1 :
				system("cls");
				tambah();
				break;
			case 2 :
				system("cls");
				ganti();
				break;
			case 3 :
				system("cls");
				hapus();
				break;
			default :
				printf("Pilihan tidak ada!");
				system("cls");
				cekbarang();
		}
}

// transaksi

void prosestransaksi(){
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
	
	printf("\n=========================== Transaksi Berhasil! ==========================\n\n");
	system("pause>nul | echo Klik Enter untuk melihat struk");
	system ("cls");
}

void struk(){
	printf("===========================================================================\n");
	printf("=                               Struk Pembelian                           =\n");
	printf("===========================================================================\n\n");
	
	fp = fopen("total.txt", "r");
	
	gettotal();
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

void transaksi(){
	printf("===========================================================================\n");
	printf("=                                 Transaksi                               =\n");
	printf("===========================================================================\n\n");
	
	fp = fopen("database.txt", "r");
	
	getdata();
	showdata();
	prosestransaksi();
	struk();
}

// Main menu

void mainmenu(){
	printf("===========================================================================\n");
	printf("=                                 Main Menu                               =\n");
	printf("===========================================================================\n");
	printf("\n1. Transaksi");
	printf("\n2. Cek Barang");
	printf("\n3. Keluar");
	printf("\nMasukan Pilihan : ");
	scanf("%d", &pilihan);
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
		default :
			printf("Pilihan tidak ada!");
			system("cls");
			cekbarang();
	}
}

// login


void loginpage(){
	getpassword();
	printf("===========================================================================\n");
	printf("=                                Login Page                               =\n");
	printf("===========================================================================\n\n");
	printf("Username : ");
	scanf("%s", &luser);
	printf("Password : ");
	scanf("%s", &lpass);
	if((strcmp(luser,"yono")==0) && (strcmp(lpass,"nene") ==0) || (strcmp(luser,"yoyo")==0) && (strcmp(lpass,"roy")==0)){
		system("cls");
		mainmenu();
	}
	else{
		printf("username atau password anda salah\n");
		system("cls");
		loginpage();
	}
}



// Main Program

void main(){
	getpassword();
	loginpage();
	syncdata();
	mainmenu();
}