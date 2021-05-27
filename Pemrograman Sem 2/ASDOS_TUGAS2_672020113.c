#include <stdio.h>
#include <stdlib.h>

int pilihan, dereta, deretb, faktora, faktorb, tsegitiga, jmlsegitiga, sgti, sgtj, sgtk;

void deret(int a, int i){
	for (i=1; i<=a; i++){
		if(i<a){
			printf("%d + ", i);
		}
		else{
			printf("%d\n", i);
		}
	}
	
	printf("Hasil penjumlahan dari 1 hingga %d = %d\n\n", a, a*(a+1)/2);
}

void faktor(int a, int i){
	for (i = a; i >= 1; i--){
		if (a%i == 0){
			printf("%d\n", i);
		}
	}
}

void segitiga(int a, int b, int i, int j, int k){
	for (i=0; i < a; i++) {
		for (k=1; k<=b; k++){
			for (j = a-i; j>1; j--){
				printf(" ");
			}
			for (j = 0; j <= i*2; j++){
				printf("*");
			}
			for (j=a-i; j>1; j--){
				printf(" ");
			}				
		}	
		printf("\n");
	}
}

void main(){
	
	printf(">>>>>>>> Tugas 2 Pemrograman <<<<<<<<");
	
	menu :
		printf("\n============= Menu Program =============");
		printf("\n1. Faktor Bilangan\n2. Deret Angka dan Jumlah\n3. Segitiga Beranak\n4. Keluar");
		printf("\n\nMasukan Menu Pilihan Anda : ");
		scanf("%d", &pilihan);
		
	switch(pilihan){
		case 1 :
			printf("\n========================================");
			printf("\n-- Faktor Bilangan --");
			printf("\n\nMasukan bilangan : ");
			scanf("%d", &faktora);
			faktor(faktora,faktorb);
			goto menu;
		
		case 2 :
			printf("\n========================================");
			printf("\n-- Deret Angka dan Jumlah --");
			printf("\n\nMasukan nilai n : ");
			scanf("%d", &dereta);
			deret(dereta,deretb);
			goto menu;
			
		case 3 :
			printf("\n========================================");
			printf("\n-- Deret Angka dan Jumlah --");
			printf("\n\nMasukan Tinggi Segitiga	: ");
			scanf("%d", &tsegitiga);
			printf("Masukan Jumlah Segitiga	: ");
			scanf("%d", &jmlsegitiga);
			printf("\n");
			segitiga(tsegitiga, jmlsegitiga, sgti, sgtj, sgtk);
			goto menu;
			
		case 4 :
			exit(0);
			
		default :
			printf("Maaf inputan salah. Ulangi lagi!\n");
			goto menu;
	}
}
