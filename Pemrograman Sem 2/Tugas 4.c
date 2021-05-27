#include <stdio.h>

void main(){
	int a[3][4];
	int b[4][5];
	int c[3][2];
	int d[3][3];
	int i,j,x;
	
	printf("Array A : \n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &a[0][0], &a[0][1], &a[0][2], &a[0][3], &a[1][0], &a[1][1], &a[1][2], &a[1][3], &a[2][0], &a[2][1], &a[2][2], &a[2][3]);

	printf("\nArray B : \n");
	scanf("%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &b[0][0], &b[0][1], &b[0][2], &b[0][3], &b[0][4], &b[1][0], &b[1][1], &b[1][2], &b[1][3], &b[1][4], &b[2][0], &b[2][1], &b[2][2], &b[2][3], &b[2][4], &b[3][0], &b[3][1], &b[3][2], &b[3][3], &b[3][4]);
	printf("\n");
	
	// Kolom 1
	
	for (x=0; x<3; x++){
		if (a[x][0]%2 == 0){
			c[x][0] = a[x][0]*b[x][0]+a[x][0]*b[x][2]+a[x][0]*b[x][4];	
		}
		
		else if (a[x][0]%2 == 1) {
			c[x][0] = a[x][0]*b[x][1]+a[x][0]*b[x][3];
		}
	}
	
	for (x=0; x<3; x++){
		if (a[x][1]%2 == 0){
			c[x][1] = a[x][1]*b[x][0]+a[x][1]*b[x][2]+a[x][1]*b[x][4];	
		}
		
		else if (a[x][1]%2 == 1) {
			c[x][1] = a[x][1]*b[x][1]+a[x][1]*b[x][3];
		}
	}
	
	for (x=0; x<3; x++){
		d[x][0] = c[x][0] + c[x][1];
	}
	
	// kolom 2
	
	for (x=0; x<3; x++){
		if (a[x][2]%2 == 0){
			d[x][1] = a[x][2]*b[x][0]+a[x][2]*b[x][2]+a[x][2]*b[x][4];
		}
		else if (a[x][2]%2 == 1){
			d[x][1] = a[x][2]*b[x][1]+a[x][2]*b[x][3];
		}
	}

	// kolom 3
	
	for (x=0; x<3; x++){
		if (a[x][3]%2 == 0){
			d[x][2] = a[x][3]*b[x][0]+a[x][3]*b[x][2]+a[x][3]*b[x][4];
		}
		else if (a[x][2]%2 == 1){
			d[x][2] = a[x][3]*b[x][1]+a[x][3]*b[x][3];
		}
	}
	
	//output
	
	printf("\nOutput (3x3)\n");
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			printf("%d ", d[i][j]);
		}
		printf("\n");
	}
}                       