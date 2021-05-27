#include <stdio.h>
#include <stdlib.h>

void segitiga() {
	int angka;
	int i,j;
	int k = 1;
	
	printf("Masukkan Angka : ");
	scanf("%d",&angka);
		
	for(i=1 ; i<=angka ; i++){
		for(j=angka ; j>=i ; j--){
			printf(" ");
		}
		for (j=1 ; j<1+i ; j++){
	 		printf("%d ",k);
			if (k<=8){
				k++;
			}
			else {
				k=0;
			}
	 	}
	 	for(j=angka ; j>=i;j--){
	 		printf(" ");
	 	}
		printf("\n");
	}
}

void drive() {
while(1) {
	printf("1.Lurus\n");
	printf("2.Belok kiri\n");
	printf("3.Belok kanan\n");
	printf("4.Stop\n");
	int perintah;
	printf("Masukkan perintah (1-3) : ");
	scanf("%d",&perintah);

	if(perintah==1) {
		printf("Mobil lurus\n");
	
		int i,j;
		printf("\n");
		for(i=0;i<6;i++) {
			for(j=7-i;j>1;j--) {
				printf(" ");
			}
			for(j=0;j<=i*2;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<5;i++) {
			for(j=6;j>1;j--) {
				printf(" ");
			}
			for(j=4;j>1;j--) {
				printf("*");
			}
			printf("\n");
		}

	}else if(perintah==2) {
		printf("Mobil belok kiri\n");
		printf("\n");
		int i,j;
		for(i=0;i<4;i++) {
			for(j=i;j<6;j++) {
				printf(" ");
			}
			for(j=0;j<=i;j++) {
				printf("*");
			}
			printf("\n");
   		}
  	  	for(i=0;i<1;i++) {
    		for(j=i;j<2;j++) {
    			printf(" ");
			}
			for(j=0;j<11;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<1;i++) {
    		for(j=i;j<1;j++) {
    			printf(" ");
			}
			for(j=0;j<12;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<1;i++) {
    		for(j=i;j<2;j++) {
    			printf(" ");
			}
			for(j=0;j<11;j++) {
				printf("*");
			}
			printf("\n");
		}
  		for(i=4;i>=1;i--) {
			for(j=i;j<=6;j++) {
				printf(" ");
			}
			for(j=1;j<=i;j++) {
				printf("*");
			}
			printf("\n");
		}
	}else if(perintah==3) {
		printf("Mobil belok kanan\n");
		printf("\n");
		int i,j;
		for(i=0;i<4;i++) {
			for(j=0;j<=6;j++) {
				printf(" ");
			}
			for(j=0;j<=i;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<1;i++) {
			for(j=0;j<1;j++) {
				printf(" ");
			}
			for(j=0;j<11;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<1;i++) {
			for(j=0;j<1;j++) {
				printf(" ");
			}
			for(j=0;j<12;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=0;i<1;i++) {
			for(j=0;j<1;j++) {
				printf(" ");
			}
			for(j=0;j<11;j++) {
				printf("*");
			}
			printf("\n");
		}
		for(i=4;i>=1;i--) {
			for(j=0;j<=6;j++) {
				printf(" ");
			}
			for(j=1;j<=i;j++) {
				printf("*");
			}
			printf("\n");
		}
		
	}else if(perintah==4) {
		break;
	}else {
		printf("Anda error\n");
	}
	printf("\n");
	}
}

void main () {
	int nim, pilihan;
	char nama[50];
	
	printf("Masukan nama lengkap \t: ");
	gets(nama);
	
	printf("Masukan NIM \t\t: ");
	scanf("%d", &nim);
	
	system ("cls");
	
	menu :
	printf("Selamat datang %s (%d)\n", nama, nim);
	printf("Menu \n1. Segitiga Angka \n2. Smart Driving \n3. Keluar \nMasukan pilihan : ");
	scanf("%d", &pilihan);
	
	switch (pilihan){
		case 1 :
			segitiga();

			system("pause>nul | echo Klik terserah untuk lanjut");
			system ("cls");
			goto menu;
		case 2 :
			drive();
			printf("\n");
			system("pause>nul | echo Klik terserah untuk lanjut");
			system ("cls");
			goto menu;
		case 3 :
			exit(0);
		default :
			printf("\nInputan tidak tersedia!\n");	
			
			system("pause>nul | echo Klik terserah untuk lanjut");
			system ("cls");
			goto menu;
	}
}