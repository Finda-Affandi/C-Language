#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	char line[200], file_name[] = "list_data.txt";
	FILE *fp;
	int i, j, k;
	
	char delim[] = ";"; //delimiters (pemisah)
	char tampung[200][3][200]; //array untuk menampung hasil pecahan
	
	printf("Membuka file %s \n", file_name);
	
	//buka file dan lihat datanya
	fp = fopen(file_name, "r");

	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(EXIT_FAILURE);
	} else {
		//kalau mau lihat per karakter
		/*
		while ((ch = fgetc(fp)) != EOF) {
			printf("%c", ch);
		}
		*/
		
		i = 0;
		//melihat per baris
		while (fgets(line, sizeof(line), fp) != NULL) {
			//fungsi untuk memecah string mjd kata disimpan dalam pointer
			char *token = strtok(line, delim);
    		
    		j = 0;
			while (token != NULL) {
				 //simpan kata dari token ke array tampung
				strcpy(tampung[i][j], token);
				
				//hapus (kosongkan) token
				token = strtok(NULL, delim);
				j++;
				//j = 0 = nama
				//j = 1 = harga
				//j = 2 = stok
			}
			
			i++;  
			//i = baris = data
		}
		
		for (k = 0; k < i; k++) {
		    printf("Nama  : %s \n", tampung[k][0]);
		    printf("Harga : Rp %s \n", tampung[k][1]);
		    printf("Stok : %s \n", tampung[k][2]);
		    printf("Total Harga : Rp %d \n", atoi(tampung[k][1]) * atoi(tampung[k][2]));
		    printf("====================\n");
		}
	}
   	
	fclose(fp);
}
