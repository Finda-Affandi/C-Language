#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#define ESC 27

void struk(){
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
		
		for (k = 0; k < i; k++) {
		    printf("Nama : %s \n", total[k][0]);
		    printf("Harga  :Rp.%s \n", total[k][1]);
		    printf("Jumlah : %s \n", total[k][2]);
		    printf("Total Harga : Rp.%s \n", total[k][3]);
		    printf("====================\n");
		}
   			printf("\n========================================\n");
   			printf("Jumlah yang harus dibayar : Rp.%d", atoi(total[0][3]) + atoi(total[1][3]) + atoi(total[2][3]) + atoi(total[3][3]) + atoi(total[4][3]) + atoi(total[5][3]) + atoi(total[6][3]) + atoi(total[7][3]) + atoi(total[8][3]) + atoi(total[9][3]) + atoi(total[10][3]) + atoi(total[11][3]) + atoi(total[12][3]) + atoi(total[13][3]) + atoi(total[14][3]) + atoi(total[15][3]) + atoi(total[16][3]) + atoi(total[17][3]) + atoi(total[18][3]) + atoi(total[19][3]) + atoi(total[20][3]) + atoi(total[21][3]) + atoi(total[22][3]) + atoi(total[23][3]) + atoi(total[24][3]));
   			printf("\n========================================\n");
   			
	fclose(fp);
	
		
	fp = fopen("total.txt","w");
	fprintf(fp, "");
	fclose(fp);

}

void transaksi(){
	char huruf;
	int trans[100][100];
	int kode[100];
	int harga[100];
	char x;
	
	FILE *tr;
	FILE *fp;
	FILE *tl;
	int i, j, k, l, jml;
	char delim[] = ";";
	char tampung[200][10][200];
	char line[200];
	
	printf("Data List Barang\n\n");
	
	fp = fopen("database.txt", "r");

	if (fp == NULL) {
		printf("Gagal membuka file ");
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
		

		for (k = 0; k < i; k++) {
			printf("Kode : %s \n", tampung[k][0]);
		    printf("Nama  : %s \n", tampung[k][1]);
		    printf("Harga : Rp.%s \n", tampung[k][2]);
		    printf("Stok : %s \n", tampung[k][3]);
		    printf("Total Harga : Rp %d \n", atoi(tampung[k][2]) * atoi(tampung[k][3]));
		    printf("====================\n");
		}
	}

	
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
	
	printf("\n==================== Transaksi Berhasil! ====================\n");
	system("pause>nul | echo Klik Enter untuk melihat struk");
	system ("cls");
	struk();
	
}
		