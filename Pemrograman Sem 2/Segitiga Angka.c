#include <stdio.h>

void main(){
	int i,j;
	i=0;
	j=0;
	
	while(i<5){
		while(j+i<5){
			printf("  ");
			printf("%d", 5-j-i);
			j++;
		}
		j=0;
		printf("\n");
		i++;
	}
}
