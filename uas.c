#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 5000
struct data{
    int id;
    char nama[50];
    char prodi[40];
};


int menu(){
	int pilih;
	
	printf("1. Tambah data\n");
	printf("2. Tampilkan data\n");
    printf("3. Hapus data\n");
	printf("0. Keluar\n");
	printf("Pilih: ");
	scanf("%d", &pilih);
	
	return pilih;
}

int main(){

    FILE *fp;
    char line[MAX_LINE_LENGTH];
	struct data dosen[100];
	int i, j, banyak, total, pilih, id;
	
	total = 0;

	do{
		pilih = menu();
		
		switch(pilih){
			case 1:
				printf("\nMasukan banyak data yang ingin ditambahkan : ");
    			scanf("%d", &banyak);
    			
    			for (i = total; i < total+banyak; i++){
    				printf("Data ke-%d\n", i+1);
			        printf("Masukan ID : ");
			        scanf("%d", &dosen[i].id);
			        printf("Masukan Nama : ");
			        fflush(stdin);
			        gets(dosen[i].nama);
			        printf("Masukan Prodi : ");
			        fflush(stdin);
			        gets(dosen[i].prodi);
			        printf("\n");
				}
				system("clear");
				total += banyak;
			break;
			
			case 2:
                system("clear");
                printf("\nData sebelumnya : \n\n");
                fp = fopen("datadosen.txt", "r");
                if(fp != NULL){
                    while(fgets(line, MAX_LINE_LENGTH, fp)){
                        printf("%s", line);
                    }
                }
                fclose(fp);
                printf("-----------------------\n\n");
                if (total == 0 && fp == NULL){
                    printf("Data masih kosong!\nSilahkan tambahkan data terlebih dahulu!\n\n");
                }
                else{
                    for (i = 0; i < total; i++) {
                        printf("Data ke-%d\n", i+1);
                        printf("ID : %d\n", dosen[i].id);
                        printf("Nama : %s\n", dosen[i].nama);
                        printf("Prodi : %s\n\n", dosen[i].prodi);
				    }
                }
            break;
            case 3:
                if (total == 0){
                    printf("\nData sekarang kosong!, Jika ada data berarti data sebelumnya.\n");
                    printf("Masukan data terlebih dahulu!\n\n");
                }
                else{
                    printf("Masukan ID yang ingin dihapus : ");
                    scanf("%d", &id);
                    for (i = 0; i < total; i++){
                        if (dosen[i].id == id){
                            for (j = i; j < total; j++){
                                dosen[j] = dosen[j+1];
                            }
                            total--;
                            printf("Data berhasil dihapus!\n\n");
                            break;
                        }
                        else{
                            printf("Data tidak ditemukan!\n\n");
                        }
                    }
                }
                
		}
		
	} while (pilih != 0);
    system("clear");
	printf("Terima kasih!\n");
    fp = fopen("dataterbaru.txt", "w+");
    for (i = 0; i < total; i++) {
        fprintf(fp,"Data ke-%d\n", i+1);
        fprintf(fp,"ID : %d\n", dosen[i].id);
        fprintf(fp,"Nama : %s\n", dosen[i].nama);
        fprintf(fp,"Prodi : %s\n\n", dosen[i].prodi);
    }
    fclose(fp);
	return 0;
}
