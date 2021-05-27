#include <stdio.h>

void main () {
	int a,i,j,max;
	
	printf("Masukan Jumlah Data Simpanan : ");
	scanf("%d", &a);
	
	int data[a];
	
	for (i=0; i<a; i++){
			printf("Input Data Ke-%d = ",i+1);
			scanf("%d", &data[i]);
		}
		
	printf("Data di dalam simpanan = ");
	for (i=0; i<a; i++){
		printf("%d ", data[i]);
	}
	
	max=data[1];
	for (i=1; i<a; i++){
		if (data[i]>max){
			max=data[i];
		}
	}
	printf("\nData Terbesar = %d", max);
}