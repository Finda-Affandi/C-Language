#include <stdio.h>
#include <stdlib.h>

void main() {
	FILE *fp;
	char harga;
	int i;
	
	fp = fopen("total.txt", "r");
	
		fscanf(fp, "%s", harga);
		printf("%s", harga);
	fclose(fp);
}

