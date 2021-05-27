#include <stdio.h>

void tambah(int a, int i){
	for (i=1; i<=a; i++){
		if(i<a){
			printf("%d + ", i);
		}
		else{
			printf("%d\n", i);
		}
	}
	
	printf("Hasil penjumlahan = %d", a*(a+1)/2);

}

void main(){
	int satu = 9;
	int dua;
	tambah(satu, dua);
}
