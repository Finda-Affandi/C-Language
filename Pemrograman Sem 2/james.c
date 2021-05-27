#include <stdio.h>

int segitiga (int angka) {
	int angka;
	int i,j;
	int k = 1;
	
	printf("Masukkan Angka :");
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

void main (){
	prosedur();
}
