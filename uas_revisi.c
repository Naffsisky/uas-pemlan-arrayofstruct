#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int no;
  char prov[100];
  char tipe[100];
  char nama[100];
  char alamat[100];
} Data;

void tambah();
void puskes();
void hapus();
void cari();
void sort();

int main(){
    int pilih;
    system("clear");
    printf("\n====================================\n");
    printf("\tCreated by.\n");
    printf("Wanda Gustrifa\t\t21081010083\n");
    printf("Rena Rama Rosalinda\t21081010190\n");
    printf("Ahmad Dhany Prayogi\t21081010269\n");
    printf("Prinafsika\t\t21081010278\n");
    printf("====================================\n\n");
    printf("--- MENU ---\n");
    printf("1. Tambah Data\n");
    printf("2. Lihat Data\n");
    printf("3. Hapus Data\n");
    printf("4. Cari Data\n");
    printf("5. Sort Data\n");
    printf("0. Keluar\n");
    printf("Pilih : ");
    scanf("%d", &pilih);
    switch (pilih){
        case 1:
            tambah();
            printf("Apakah anda ingin kembali ke menu?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Pilih : ");
            scanf("%d", &pilih);
            if (pilih == 1){
                main();
            } else {
                return 0;
            }
        break;
        case 2:
            puskes();
            printf("Apakah anda ingin kembali ke menu?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Pilih : ");
            scanf("%d", &pilih);
            if (pilih == 1){
                main();
            } else {
                return 0;
            }
        break;
        case 3:
            hapus();
            printf("Apakah anda ingin kembali ke menu?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Pilih : ");
            scanf("%d", &pilih);
            if (pilih == 1){
                main();
            } else {
                return 0;
            }
        break;
        case 4:
            cari();
            printf("Apakah anda ingin kembali ke menu?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Pilih : ");
            scanf("%d", &pilih);
            if (pilih == 1){
                main();
            } else {
                return 0;
            }
        break;
        case 5:
            sort();
            printf("Apakah anda ingin kembali ke menu?\n");
            printf("1. Ya\n");
            printf("2. Tidak\n");
            printf("Pilih : ");
            scanf("%d", &pilih);
            if (pilih == 1){
                main();
            } else {
                return 0;
            }
        break;
        case 0:
            system("clear");
            printf("Good bye! :)\n");
            return 0;
        break;
        default:
            printf("\nPilihan tidak ada!\n\n");
            main();
        break;
    }
    return 0;
}

void tambah(){
    printf("Tambah Data\n");
    FILE *file;
    file = fopen("anjay.txt", "a");
    if (file == NULL){
        printf("Error opening file.\n");
    }
    Data medical;
    printf("No : ");
    scanf("%d", &medical.no);
    printf("Provinsi : ");
    fflush(stdin);
    gets(medical.prov);
    printf("Tipe : ");
    fflush(stdin);
    gets(medical.tipe);
    printf("Nama : ");
    fflush(stdin);
    gets(medical.nama);
    printf("Alamat : ");
    fflush(stdin);
    gets(medical.alamat);
    fprintf(file, "\n%d,%s,%s,%s,%s", medical.no, medical.prov, medical.tipe, medical.nama, medical.alamat);
    fclose(file);
    printf("Data berhasil ditambahkan!\n\n");
}

void puskes(){
    FILE *file;
    file = fopen("anjay.txt", "r"); 

    if (file == NULL){
        printf("Error opening file.\n");
    }

    Data medical[100];
    int read = 0;
    int records = 0;

    do{
        read = fscanf(file,
                        "%d,%100[^,],%100[^,],%100[^,],%100[^\n]\n",          
                        &medical[records].no, 
                        medical[records].prov, 
                        medical[records].tipe, 
                        medical[records].nama,
                        medical[records].alamat);
        if (read == 5) records++;

        if (read != 5 && !feof(file)){
        printf("File format incorrect.\n\n");
        }
        if (ferror(file)){
        printf("Error reading file.\n\n");
        }
    } while (!feof(file));
    fclose(file);
    printf("\nMembaca %d data.\n\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
            medical[i].no, 
            medical[i].prov,
            medical[i].tipe,
            medical[i].nama,
            medical[i].alamat);
    }
    printf("\n");
    printf("Terbaca %d data.\n", records);
}

void hapus(){
    printf("-- MENGHAPUS DATA --\n");
    FILE *file;
    file = fopen("anjay.txt", "r");
    if (file == NULL){
        printf("Error opening file.\n");
    }
    Data medical[100];
    int read = 0;
    int records = 0;

    do{
        read = fscanf(file,
                        "%d,%100[^,],%100[^,],%100[^,],%100[^\n]\n",          
                        &medical[records].no, 
                        medical[records].prov, 
                        medical[records].tipe, 
                        medical[records].nama,
                        medical[records].alamat);
        if (read == 5) records++;

        if (read != 5 && !feof(file)){
        printf("File format incorrect.\n\n");
        }
        if (ferror(file)){
        printf("Error reading file.\n\n");
        }
    } while (!feof(file));

    fclose(file);
    printf("\nMembaca %d data.\n\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
            medical[i].no, 
            medical[i].prov,
            medical[i].tipe,
            medical[i].nama,
            medical[i].alamat);
    }
    printf("\n");
    printf("Terbaca %d data.\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan nomor yang ingin dihapus : ");
    int hapus;
    scanf("%d", &hapus);
    for (int i = 0; i < records; i++){
        if (medical[i].no == hapus){
            for (int j = i; j < records; j++){
                medical[j] = medical[j+1];
            }
        records--;
        }
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
            medical[i].no, 
            medical[i].prov,
            medical[i].tipe,
            medical[i].nama,
            medical[i].alamat);
    }
    printf("\n");
    printf("Terbaca %d data.\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Data berhasil dihapus!\n\n");
    file = fopen("anjay.txt", "w");
    for (int i = 0; i < records; i++){
        fprintf(file, "%d,%s,%s,%s,%s\n", medical[i].no, medical[i].prov, medical[i].tipe, medical[i].nama, medical[i].alamat);
    }
    fclose(file);
}

void cari(){
    printf("-- MENCARI DATA --\n");
    FILE *file;
    file = fopen("anjay.txt", "r");
    if (file == NULL){
        printf("Error opening file.\n");
    }
    Data medical[100];
    int read = 0;
    int records = 0;
    
    do{
        read = fscanf(file,
                        "%d,%100[^,],%100[^,],%100[^,],%100[^\n]\n",          
                        &medical[records].no, 
                        medical[records].prov, 
                        medical[records].tipe, 
                        medical[records].nama,
                        medical[records].alamat);
        if (read == 5) records++;
    
        if (read != 5 && !feof(file)){
        printf("File format incorrect.\n\n");
        }
        if (ferror(file)){
        printf("Error reading file.\n\n");
        }
    } while (!feof(file));
    
    fclose(file);
    printf("\nMembaca %d data.\n\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
             medical[i].no, 
             medical[i].prov,
             medical[i].tipe,
             medical[i].nama,
             medical[i].alamat);
    }
    printf("\n");
    printf("Terbaca %d data.\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Masukkan nomor yang ingin dicari : ");
    int cari;
    scanf("%d", &cari);
    for (int i = 0; i < records; i++){
        if (medical[i].no == cari){
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
                medical[i].no, 
                medical[i].prov,
                medical[i].tipe,
                medical[i].nama,
                medical[i].alamat);
        }
    }
    printf("\n");
}

void sort(){
    printf("-- MENGURUTKAN DATA --\n");
    FILE *file;
    file = fopen("anjay.txt", "r");
    if (file == NULL){
        printf("Error opening file.\n");
    }
    Data medical[100];
    int read = 0;
    int records = 0;
    
    do{
        read = fscanf(file,
                        "%d,%100[^,],%100[^,],%100[^,],%100[^\n]\n",          
                        &medical[records].no, 
                        medical[records].prov, 
                        medical[records].tipe, 
                        medical[records].nama,
                        medical[records].alamat);
        if (read == 5) records++;
    
        if (read != 5 && !feof(file)){
        printf("File format incorrect.\n\n");
        }
        if (ferror(file)){
        printf("Error reading file.\n\n");
        }
    } while (!feof(file));
    
    fclose(file);
    printf("\nMembaca %d data.\n\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
             medical[i].no, 
             medical[i].prov,
             medical[i].tipe,
             medical[i].nama,
             medical[i].alamat);
    }
    printf("\n");
    printf("Terbaca %d data.\n", records);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Data berhasil diurutkan!\n\n");
    file = fopen("anjay.txt", "w");
    for (int i = 0; i < records; i++){
        for (int j = 0; j < records; j++){
            if (medical[i].no < medical[j].no){
                Data temp = medical[i];
                medical[i] = medical[j];
                medical[j] = temp;
            }
        }
    }
    for (int i = 0; i < records; i++){
        fprintf(file, "%d,%s,%s,%s,%s\n", medical[i].no, medical[i].prov, medical[i].tipe, medical[i].nama, medical[i].alamat);
    }
    fclose(file);   
}
