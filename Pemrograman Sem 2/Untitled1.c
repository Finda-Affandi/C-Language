#include <stdio.h>

void main() {
	int batas;
	
	printf("Masukan batas (3-10) : ");
	scanf("%d", &batas);
	
	if (batas < 3 || batas > 10) {
		printf("Batas hanya boleh 3-10!");
	}
	else {
		int i, j;
		for (i=0; i < batas; i++) {
			for (j = batas-i; j>1; j--) {
				printf("=");
			}
			for (j=0; j<= i*2; j++) {
				printf("x");
			}
			printf("\n");
		}
	}
}
