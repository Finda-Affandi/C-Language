#include <stdio.h>
void main(){
	int angka;
	char nama[] = "Finda Affandi";
	int nim = 672020113;
	
	
	printf("Nama	: %s\n", nama);
	printf("NIM	: %d\n\n", nim);
	
	printf("Jumlah anak Ayam : ");
	scanf(" %d", &angka);
	
	if ((angka >= 3) && (angka <= 10)) {
		printf("Anak ayam turunlah %d\n", angka);
			for (angka>0; angka--;){
				if (angka>0){
					printf("Mati satu tinggalah %d\n", angka);
				}
					else {
					printf("Mati satu tinggal induknya :(\n");
					printf("Lagu ini dituliskan oleh %s dengan NIM %d", nama, nim);
				}
			}
		}
		else {
			printf("Batas hanya boleh dari 3 sampai 10");
		}
	getch();
}
