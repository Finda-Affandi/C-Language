#include <stdio.h>
void main() {
	int i,j,l;
	int k=1;
	for (i=1; i<10; i++) {
		for (l=10; l>0; l--){
			printf(" ");
		}
		for (j=1; j<1+i; j++){
			printf("%d ",k);
			if (k<=8){
				k++;
			}
			else {
				k=0;
			}
		}
		printf("\n");
	}
}
