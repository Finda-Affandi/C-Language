#include <stdio.h>

  void main() { 
  int tinggi; int batas; 
  printf ("Masukan Tinggi :"); 
  scanf ("%d", &tinggi); 
  
  int i,j; 
  
  for(i = 1; i < tinggi; i++) { 
  	for (j= tinggi; j> 0 ; j--) { 
	  printf("%i", j); } 
	  printf("\n"); } 
	  
	  printf("\n"); printf("\n"); 
	  
	  for(i = 0; i < tinggi; i++) { 
	  for (j= tinggi-i; j> 0 ; j--) { 
	  printf("%i", j); } 
	  
	  for ( j = i ;j < i + 1; j++){ 
	  printf( "%i", j);
      } 
	  printf( "\n"); } 
	  
	  printf( "\n"); printf( "\n"); 
	  
	  for(i=0 ; i < tinggi; i++)
      { for (j=i ; j> 0 ; j--) { 
	  printf("X"); } 
	  
	  for (j=tinggi - i; j < tinggi * 2 - i; j++){ 
	  printf("%i", j); } printf ( "\n"); } } 
