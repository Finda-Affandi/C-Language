#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char file_name[] = "kasir_data.txt";
char delim[] = ";";
char data_barang[50][3][50][50];
int jml_data_barang = 0;

char *substring(char *string, int position, int length) {
   	char *pointer;
   	int c;
 
   	pointer = malloc(length+1);
   
   	if (pointer == NULL) {
      	printf("Unable to allocate memory.\n");
		exit(EXIT_FAILURE);
   	}
 
   	for (c = 0 ; c < length ; c++) {
      	*(pointer+c) = *(string+position-1);      
      	string++;  
   	}
 
   	*(pointer+c) = '\0';
 
   	return pointer;
}

void getData() {
	FILE *fp = fopen(file_name, "r");
    char line[200];
	
	memset(data_barang,0,sizeof(data_barang));
    jml_data_barang = 0;  
	   
	if (fp == NULL) {
		printf("Gagal membuka file %s", file_name);
		exit(0);
	} else {
		int i = 0;
		while (fgets(line, sizeof(line), fp) != NULL) {
			char *token = strtok(line, delim);
    		
    		int j = 0;
			while (token != NULL) {
				strcpy(data_barang[i][j], token);
				token = strtok(NULL, delim);
				j++;
			}
			
			i++;
			jml_data_barang++;
		}
	}
	fclose(fp);
}

void viewData() {
    getData();
    system("@cls||clear");
    printf("||==============================================||\n");
   	printf("||\t      Menu Lihat data barang\t        ||\n");
   	printf("||==============================================||\n\n\n");
    if (jml_data_barang > 0) {
        printf("  Kode Barang   Nama Barang      Harga(Rp.) Stok\n");
   		printf("  ==============================================\n");
        int i;
		for (i = 0; i < jml_data_barang; i++) {
			int kode = atoi(data_barang[i][0]);
			char nama_brg[100];
			strcpy(nama_brg, data_barang[i][1]);
			if (strlen(nama_brg) > 15) {
		   		strcpy(nama_brg, substring(nama_brg, 1, 15));
			} else if (strlen(nama_brg) < 8) {
		   		snprintf(nama_brg, sizeof nama_brg, "%s%s", data_barang[i][1], "\t");
			}
		
            int harga_brg = atoi(data_barang[i][2]);
            int stok_brg = atoi(data_barang[i][3]);
            printf("   %d\t        %s\t  %d\t     %d \n",kode,nama_brg,harga_brg,stok_brg);
        }
    } else {
        printf("\t     Tidak ada data barang!\n");
    }
    printf("  ==============================================\n\n\n");
    system("pause");
    menu_utama();
}

bool addToFile(char inputan[]) {
	FILE *fp = fopen(file_name,"a+");
	if (fp == NULL) {
		return false;
	} else {
		fputs(inputan, fp);
	}
	fclose(fp);
	return true;
}

void tambahData() {
	scanf("%c");
	system("@cls||clear");
    printf("||==========================================||\n");
   	printf("||\t    Menu Lihat data barang\t    ||\n");
   	printf("||==========================================||\n\n\n");
  char kode[50], nama[100], harga[50], stok[50], hasil[200];
  
   	printf("\tMasukkan kode Barang  : ");
   	gets(kode);
   	
   	int kodee = atoi(kode);
    printf("\t_____________________\n");
	printf("\tMasukkan Nama Barang  : ");
   	gets(nama);
   	if (strlen(nama) > 15) {
   		strcpy(nama, substring(nama, 1, 15));
	}
	  printf("\t_____________________\n");
   	printf("\tMasukkan Harga Barang : Rp.");
   	gets(harga);
   	int hargaa = atoi(harga);
   	if (hargaa < 1000) hargaa = 1000;
   	else if (hargaa > 9999999) hargaa = 9999999;
   	  printf("\t_____________________\n");
   	printf("\tMasukkan Stok Barang  : ");
   	gets(stok);
   	int stokk = atoi(stok);
   	if (stokk < 1) stokk = 1;
   	else if (stokk > 10000) stokk = 10000;
   	 printf("\t_____________________\n\n");
   printf("||==========================================||\n");
	snprintf(hasil, sizeof hasil, "%d;%s;%d;%d; \n",kodee, nama, hargaa, stokk);
	if (addToFile(hasil)) {
		printf("||\tSukses tambah data barang!\t    ||\n");
	} else {
		printf("||\tGagal tambah data barang!\t    ||\n");
	}
	printf("||==========================================||\n\n\n");
	system("pause");
    menu_utama();
}
void gantiData() {
	//menu ganti data
}
void hapusData() {
	scanf("%c");
	system("@cls||clear");
    printf("||==========================================||\n");
   	printf("||\t    Menu Hapus data barang\t    ||\n");
   	printf("||==========================================||\n\n\n");
   	char kode[100];
   	printf("       *Masukkan Kode Barang : ");
   	gets(kode);
	if (jml_data_barang > 0) {
		FILE *fp = fopen(file_name, "r");
	    char line[200];
		   
		if (fp == NULL) {
			printf("Gagal membuka file %s", file_name);
			exit(EXIT_FAILURE);
		} else {
			bool ada = false, ada2 = false;
			int i = 0, j = 0, k = 0;
			char tampung[100][200];
			while (fgets(line, sizeof(line), fp) != NULL) {
				char *token = strtok(line, delim);
	    		j = 0;
				ada = false;
				while (token != NULL) {
					if (j == 0) {
						if (strcmp(data_barang[i][j],kode) == 0) {
							ada = true;
							ada2 = true; //memastikan jika ketemu
						}
					}
					token = strtok(NULL, delim);
					j++;
				}
				
				if (!ada) {
					//data barang yg bukan dihapus akan ditampung di array tampung
					snprintf(tampung[k], sizeof tampung[k], "%s;%s;%s;%s;\n", data_barang[i][0], data_barang[i][1], data_barang[i][2],data_barang[i][3],data_barang[i][4]);
					k++;
				}
				
				i++;
			}
			
			fclose(fp);
			printf("\n");
		
			if (ada2) {
				fp = fopen(file_name, "w"); //reset file jadi kosong
				fclose(fp);
				if (k > 0) {
					for (i = 0; i < k; i++) {
						addToFile(tampung[i]);
					}	
				}
				printf("     Sukses hapus kode (%s) dari data barang!\n",kode);
			} else {
				printf("     Kode Barang (%s) tidak ditemukan!\n",kode);
			}
		}
   	} else {
   		printf("   ============================================\n");
   		printf("Tidak ada data barang!\n");
    }
    
    printf("     =======================================\n\n\n");
    system("pause");
    menu_utama();
}
void transaksi(){
	system("@cls||clear");
	 printf("\t\t\t\t  ||==========================================||\n");
   	printf("\t\t\t\t  ||\t\t  Menu Transaksi\t      ||\n");
   	printf("\t\t\t\t  ||==========================================||\n\n\n");
	int banyak,jumlah,i,uangpem;
	char nama[100];
	char nama1[100];
	char bln[10];
    int tgl,thn;
    int rek;
	char atasnama[30];
	int jumlah1;	
	int harga;
	int buku = 2000;
	int bgambar = 2500;
	int pulpen = 1500;	
	int pensil = 2000;
	int Tas = 25000;
	int Penggaris = 3000;
	int Penghapus = 3000;
	int Disgrip = 7000;
	int Staples = 5000;
	int timex = 4000;
	int Cutter = 5000;
	int Busur_Derajat = 2000;
	int Pensil_Mekanik = 9000;
	int Rautan = 3000;
	int Spidol = 10000;
	int Lem_Kertas = 2000;
	int Cat_Warna = 12000;
	int Sepatu = 50000;
	int Topi_Pramuka = 15000;
	int Dasi = 7000;
	int Jangka = 5000;
	int crayon = 12000;
	int talipramuka = 6000;
	int solasi = 2500;
	int kaoskaki = 7000;

 	printf("1. buku = %d\t   ",buku);
 	printf("6. Penggaris = %d\t",Penggaris);
 	printf("11. Cutter = %d\t",Cutter);
 	printf("   16. Lem Kertas = %d\t",Lem_Kertas);
 	printf("21. Jangka = %d\t\t",Jangka);	
 	printf("2. Bgambar = %d  ",bgambar);
 	printf("7. Penghapus = %d\t",Penghapus);
 	printf("12. Busur Derajat = %d",Busur_Derajat);
 	printf("   17. Cat Warna = %d\t",Cat_Warna);
 	printf("22. Crayon = %d\t\t",crayon);
 	printf("3. Pulpen = %d   ",pulpen);
 	printf("8. Disgrip = %d\t",Disgrip);
 	printf("13. Pensil Mekanik = %d",Pensil_Mekanik);
 	printf("  18. Sepatu = %d\t",Sepatu);
 	printf("\t23. Tali Pramula = %d\t",talipramuka);	
 	printf("4. Pensil = %d   ",pensil);
 	printf("9. Staples = %d\t",Staples);
 	printf("14. Rautan Pensil = %d",Rautan);
 	printf("   19. Topi Pramuka = %d  ",Topi_Pramuka);
 	printf("   24. Solasi = %d\t\t",solasi);	
 	printf("5. Tas = %d\t  ",Tas);
 	printf("10. Timex = %d\t",timex);
 	printf("15. Spidol = %d\t",Spidol);
 	printf("   20. Dasi = %d\t",Dasi);
 	printf("\t25. Kaos Kaki = %d",kaoskaki);
 		printf("\n");
 		printf("\n");
    	printf(" Tanggal/bulan/tahun(spasi) : "); 
		scanf("%d %s %d",&tgl,&bln,&thn);
  	
	  	printf(" Masukkan Nomor Rekening    : ");
	  	scanf(" %d",&rek);
	  	printf(" Atas nama                  : ");
	  	scanf(" %[^\n]s",&atasnama);
		printf(" \n Berapa macam barang yang ingin dibeli : ");
		scanf(" %d",&banyak);
		printf("\n"); 
	if(banyak < 1 || banyak > 25) {
		printf("barang macam barang hanya ada 25 !!\n");
		system("pause");
		printf("\n");
		transaksi();
	}else{	
		
		for(i = 1; i <=banyak; i++){
		
		if (banyak>0 && banyak<2) {
			
		printf("\tMasukkan nama barang     : ");
		scanf("%s",&nama);
		
		printf("\tMasukkan jumlah barang   : ");
		scanf("%d",&jumlah); 
		
		printf("\tMasukkan harga(pilih no) : ");
		scanf("%d",&harga);
		printf("\tHarga 1 %s adalah    :RP. ",nama);
		if(harga == 1) {
				printf("2000");
		}else if(harga == 2) {
			printf("2500");
 		}else if(harga == 3) {
			printf("1500");
		}else if(harga == 4) {
			printf("2000");
		}else if(harga == 5) {
			printf("25000");
		}else if(harga == 6) {
			printf("3000");
		}else if(harga == 7) {
			printf("3000");
		}else if(harga == 8) {
			printf("7000");
		}else if(harga == 9) {
			printf("5000");
		}else if(harga == 10) {
			printf("4000");
		}else if(harga == 11) {
			printf("5000");
		}else if(harga == 12) {
			printf("2000");
		}else if(harga == 13) {
			printf("9000");
		}else if(harga == 14) {
			printf("3000");
		}else if(harga == 15) {
			printf("10000");
		}else if(harga == 16) {
			printf("2000");
		}else if(harga == 17) {
			printf("12000");
		}else if(harga == 18) {
			printf("50000");
		}else if(harga == 19) {
			printf("15000");
		}else if(harga == 20) {
			printf("7000");
		}else if(harga == 21) {
			printf("5000");
		}else if(harga == 22) {
			printf("12000");
		}else if(harga == 23) {
			printf("6000");
		}else if(harga == 24) {
			printf("2500");
		}else if(harga == 25) {
			printf("7000");
		}
		
	
			}
				else if( banyak >1 && banyak<=25) {
		printf("\n\tMasukkan nama barang ke-%i : ",i);
		scanf("%s",&nama);
		printf("\tMasukkan jumlah barang    : ");
		scanf("%d",&jumlah);
		printf("\tMasukkan harga(pilih no)  : ");
		scanf("%d",&harga);
		printf("\tHarga 1 %s adalah      : ",nama);
		
		if(harga == 1) {
				printf("2000");
		}else if(harga == 2) {
			printf("2500");
		}else if(harga == 3) {
			printf("1500");
		}else if(harga == 4) {
			printf("25000");
		}else if(harga == 5) {
			printf("3000");
		}else if(harga == 6) {
			printf("3000");
		}else if(harga == 7) {
			printf("7000");
		}else if(harga == 8) {
			printf("5000");
		}else if(harga == 9) {
			printf("4000");
		}else if(harga == 10) {
			printf("12000");
		}else if(harga == 11) {
			printf("5000");
		}else if(harga == 13) {
			printf("9000");
		}else if(harga == 14) {
			printf("3000");
		}else if(harga == 15) {
			printf("10000");
		}else if(harga == 16) {
			printf("2000");
		}else if(harga == 17) {
			printf("12000");
		}else if(harga == 18) {
			printf("50000");
		}else if(harga == 19) {
			printf("15000");
		}else if(harga == 20) {
			printf("7000");
		}else if(harga == 21) {
			printf("5000");
		}else if(harga == 22) {
			printf("12000");
		}else if(harga == 23) {
			printf("6000");
		}else if(harga == 24) {
			printf("2500");
		}else if(harga == 25) {
			printf("7000");
		}
		printf("\n");
				
			}
	
		}
				printf("\n");
																																																	
	}
	
	
	printf("\n\n\n");

	int tekan;
		
		printf(" Tekan 1 untuk lihat Struk atau 2 untuk Ganti Data :");
		scanf("%d",&tekan);
		if(tekan ==1){
		
			system("cls");
		printf(" No Rek   \t\t\t : %d\n",rek);
		printf(" Atas nama    \t\t\t : %s\n",atasnama);
		printf(" Banyak macam barang yang dibeli : %d\n",banyak);	
	
		
	for(i = 1; i <=banyak; i++){
		if (banyak>0 && banyak<2) {
		printf(" Nama barang  \t\t\t : %s\n",nama);
		printf(" Jumlah barang  \t\t : %d\n",jumlah);
			
	
			}else if( banyak >1 && banyak<=25) {
		
		printf(" Nama barang ke-%i \t\t : ",i);
		printf("%s\n",nama);
			printf(" Jumlah barang ke-%i \t\t : ",i);
		printf("%d\n",jumlah);
		
}
			}if(harga == 1) {
				int total = jumlah*buku;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 2) {
		int total = jumlah*bgambar;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 3) {
		int total = jumlah*pulpen;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 4) {
		int total = jumlah*pensil;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 5) {
		int total = jumlah*Tas;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 6) {
		int total = jumlah*Penggaris;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 7) {
		int total = jumlah*Penghapus;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 8) {
		int total = jumlah*Disgrip;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 9) {
		int total = jumlah*Staples;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 10) {
		int total = jumlah*timex;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 11) {
		int total = jumlah*Cutter;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 12) {
		int total = jumlah*Busur_Derajat;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 13) {
		int total = jumlah*Pensil_Mekanik;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 14) {
		int total = jumlah*Rautan;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 15) {
		int total = jumlah*Spidol;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 16) {
		int total = jumlah*Lem_Kertas;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 17) {
		int total = jumlah*Cat_Warna;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 18) {
		int total = jumlah*Sepatu;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 19) {
		int total = jumlah*Topi_Pramuka;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 20) {
		int total = jumlah*Dasi;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 21) {
		int total = jumlah*Jangka;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 22) {
		int total = jumlah*crayon;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 23) {
		int total = jumlah*talipramuka;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 24) {
		int total = jumlah*solasi;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}else if(harga == 25) {
		int total = jumlah*kaoskaki;
			int kembalian = uangpem-total;
			printf(" Total harga \t\t\t : Rp.%d\n",total );
			printf(" Uang pembayaran \t\t : Rp.%d\n",uangpem);
			printf(" Uang kembalian \t\t : Rp.%d\n\n",kembalian);
		}
	
	
		}else if(tekan == 2){
		transaksi();
		}
			
	
}
void login() {
	system("cls");
	char user[50];
	int pass[50];
	printf("\n");
	
	printf("\t\t||==========================================||\n");
   	printf("\t\t||\t      --     LOGIN\t--          ||\n");
   	printf("\t\t||==========================================||\n\n\n");
   	printf("\t\t*Masukkan nama dan NIM untuk lanjut berbelanja\n\n");	
    printf("\t\t   Masukan Username  : ");
    scanf(" %[^\n]s",&user);
    printf("\t\t   Masukkan Password : ");
    scanf("%d",&pass);
}
void menu_utama() {
	int pilihan = 0;
	while (pilihan == 0) {
		system("cls");
		printf("||==========================================||\n");
   		printf("||\t\tMENU UTAMA\t\t    ||\n");
   		printf("||==========================================||\n\n\n");
		printf(" 1. Lihat Data Barang\n");
		printf(" 2. Tambah Data Barang\n");
		printf(" 3. Hapus Data Barang\n");
		printf(" 4. Transaksi\n");
		printf(" 5. Logout\n");
		printf(" 6. Exit\n\n");
		printf(" Pilih Menu : ");
		scanf("%d",&pilihan);
		if (pilihan <= 0 || pilihan > 6) {
			pilihan = 0;
			system("@cls||clear");
			printf("Pilihan Menu Salah!");
			system("pause");
		}
	}
		if (pilihan == 1) viewData();
	else if (pilihan == 2) tambahData();
	else if (pilihan == 3) hapusData();
	else if (pilihan == 4) {
		transaksi();
		system("pause");
		menu_utama();
	}
	else if (pilihan == 5) {
		main();
		system("cls");
		login();
	}
	else if (pilihan == 6) {
		exit(0);
	}
	else menu_utama(pilihan);

	
}
void main() {
	getData();
    login();
	menu_utama();
}
		
		
