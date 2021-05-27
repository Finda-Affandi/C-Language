#include <stdio.h>
#include <conio.h>

void main(){
	int j,i,n;
	n=5;
	for(i=1; i<n; i++){
		for (j=i; j<n; j++)
		printf(" %d", j);
		printf("\n");
	}
}
