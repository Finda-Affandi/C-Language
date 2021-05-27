#include <stdio.h>

void main () {
	
	int i, j, k, l, tinggi;
	
	printf("Masukan tinggi : ");
	scanf("%d", &tinggi);
	
	// pertama
	
	for(i=tinggi; i>0; i--){
		for(j=tinggi; j>0; j--)
		printf("%d", j);
		printf("\n");
	}
	
	printf("\n");
	
	// kedua
	
	k=0;
	
	for(i=tinggi; i>0; i--){
		for(j=i; j>0; j--)
		printf("%d", j); 
		printf("%d", k);
		k++;			
		printf("\n");
	}
	
	printf("\n");
	
	// ketiga
	l=tinggi;
	
	for(i=0; i<tinggi; i++){
		for(j=0; j<i; j++)
		printf("X");
		for(k=l; k<l+tinggi; k++)
		printf("%d", k);
		l--;
		printf("\n");
	}

}




