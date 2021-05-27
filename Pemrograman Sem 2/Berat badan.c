#include <stdio.h>

void main(){
	float bb, tb, bmi;
	printf("Masukan Berat badan (kg) dan tinggi badan (m)	:");
	scanf(" %f", &bb); scanf(" %f", &tb);
	bmi = bb/(tb*tb);
	printf("%.3f\n", bmi);
	
	if (bmi<18.5){
	printf("Terlalu Kurus");
}
	else if (bmi>18.5 && bmi<25){
		printf("Ideal");
	}
	else if(bmi>25){
		printf("Gemuk");
	}
}
