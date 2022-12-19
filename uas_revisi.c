#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void sort_id();
void sort_prov();
void sort_tipe();
void total_prov();
void total_detail();
void max();
void min();

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
    printf("4. Cari Data Berdasarkan Nomor\n");
    printf("5. Sort Data Berdasarkan Nomor\n");
    printf("6. Sort Data Berdasarkan Provinsi\n");
    printf("7. Cari Data Berdasarkan Provinsi (Case Sensitive)\n");
    printf("8. Total Puskemas Per Provinsi\n");
    printf("9. Provinsi dengan jumlah Puskesmas terbanyak\n");
    printf("10. Provinsi dengan jumlah Puskesmas tersedikit\n");
    printf("11. Sort Data Berdasarkan Tipe\n");
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
            sort_id();
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
        case 6:
            sort_prov();
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
        case 7:
            total_prov();
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
        case 8:
            total_detail();
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
        case 9:
            max();
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
        case 10:
            min();
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
        case 11:
            sort_tipe();
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
    printf("--- Tambah Data ---\n");
    FILE *file;
    file = fopen("myfaskes.txt", "a");
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
    printf("--- Data Puskesmas ---\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r"); 

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
    file = fopen("myfaskes.txt", "r");
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
    file = fopen("myfaskes.txt", "w");
    for (int i = 0; i < records; i++){
        fprintf(file, "%d,%s,%s,%s,%s\n", medical[i].no, medical[i].prov, medical[i].tipe, medical[i].nama, medical[i].alamat);
    }
    fclose(file);
}

void cari(){
    printf("-- MENCARI DATA --\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r");
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

void sort_id(){
    printf("-- MENGURUTKAN DATA BERDASARKAN NOMOR --\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r");
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
    file = fopen("myfaskes.txt", "w");
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
    puskes();
}

void sort_prov(){
    printf("-- MENGURUTKAN DATA BERDASARKAN PROVINSI --\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r");
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
    file = fopen("myfaskes.txt", "w");
    for (int i = 0; i < records; i++){
        for (int j = 0; j < records; j++){
            if (strcmp(medical[i].prov, medical[j].prov) < 0){
                Data temp = medical[i];
                medical[i] = medical[j];
                medical[j] = temp;
            }
        }
    }
    for (int i = 0; i< records; i++){
        fprintf(file, "%d,%s,%s,%s,%s\n", medical[i].no, medical[i].prov, medical[i].tipe, medical[i].nama, medical[i].alamat);
    }
    fclose(file);
    puskes();
}

void total_prov(){
  int count = 0;
  char prov[100];
  printf("-- MENAMPILKAN TOTAL DATA BERDASARKAN PROVINSI --\n");
  FILE *file;
    file = fopen("myfaskes.txt", "r"); 

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
    printf("Masukan provinsi yang ingin ditampilkan : ");
    fflush(stdin);
    scanf("%[^\n]", prov);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("  No\t\t   Prov\t\t  Tipe\t\t    Nama\t\t\t\tAlamat\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < records; i++){
        if (strcmp(medical[i].prov, prov) == 0){
          count = count + 1;
            printf("%d    \t%s  \t%s  \t%s         \t\t%s\n", 
                medical[i].no, 
                medical[i].prov,
                medical[i].tipe,
                medical[i].nama,
                medical[i].alamat);
        }
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Data berhasil ditampilkan!\n\n");
    printf("Total data provinsi %s adalah %d\n", prov, count);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}

void total_detail(){
  printf("--- Data Puskesmas ---\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r"); 

    if (file == NULL){
        printf("Error opening file.\n");
    }

    Data medical[100];
    int read = 0;
    int records = 0;
    int i;
    int hasil[100];

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
    printf("Banyaknya data Puskesmas perprovinsi\n\n");
    printf("Provinsi\t\t Jumlah\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    int count = 1;
    for (int i=0; i<records; i++){
      for (int j=i+1; j<records; j++){
        if (strcmp(medical[i].prov, medical[j].prov) == 0 && (strcmp(medical[j].prov, "0") != 0)){
          count = count + 1;
          strcpy(medical[j].prov, "0");
        }
      }
      if (strcmp(medical[i].prov, "0") != 0){
        printf("%s\t\t %d\n", medical[i].prov, count);
      }
      hasil[i] = count;
      count = 1;
    }
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Data Provinsi dengan Puskesmas Terbanyak!\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Provinsi\t: ");
    int max = hasil[0];
    for (int i=0; i<records; i++){
      if (max < hasil[i]){
        max = hasil[i];
      }
    }
    for (int i=0; i<records; i++){
      if (max == hasil[i]){
        printf("%s, ", medical[i].prov);
      }
    }
    printf("\nJumlah  \t: %d\n", max);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    int min = hasil[0];
    for (int i=0; i<records; i++){
      if (min > hasil[i]){
        min = hasil[i];
      }
    }
    printf("Data Provinsi dengan Puskesmas Tersedikit!\n");
    printf("--------------------------------------------------------------------------------------------------------------------\n");
    printf("Provinsi\t: ");
    for (int i=0; i<records; i++){
      if (min == hasil[i]){
        if (strcmp(medical[i].prov, "0") != 0){
            printf("%s, ", medical[i].prov);
        }
      }
    }
    printf("\nJumlah  \t: %d\n", min);
    printf("--------------------------------------------------------------------------------------------------------------------\n");
}

void max(){
    printf("--- Data Puskesmas ---\n");
        FILE *file;
        file = fopen("myfaskes.txt", "r"); 
    
        if (file == NULL){
            printf("Error opening file.\n");
        }
    
        Data medical[100];
        int read = 0;
        int records = 0;
        int i;
        int hasil[100];
    
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
        printf("Mencari data provinsi dengan jumlah puskesmas terbanyak\n\n");
        printf("Provinsi\t\t Jumlah\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        int count = 1;
        for (int i=0; i<records; i++){
          for (int j=i+1; j<records; j++){
            if (strcmp(medical[i].prov, medical[j].prov) == 0 && (strcmp(medical[j].prov, "0") != 0)){
              count = count + 1;
              strcpy(medical[j].prov, "0");
            }
          }
          if (strcmp(medical[i].prov, "0") != 0){
            printf("%s\t\t %d\n", medical[i].prov, count);
          }
          hasil[i] = count;
          count = 1;
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        int max = hasil[0];
        for (int i=0; i<records; i++){
          if (max < hasil[i]){
            max = hasil[i];
          }
        }
        printf("Jumlah puskesmas terbanyak adalah %d\n", max);
        printf("Provinsi dengan jumlah puskesmas terbanyak adalah ");
        for (int i=0; i<records; i++){
          if (max == hasil[i]){
            printf("%s, ", medical[i].prov);
          }
        }
        printf("\n");
}

void min(){
    printf("--- Data Puskesmas ---\n");
        FILE *file;
        file = fopen("myfaskes.txt", "r"); 
    
        if (file == NULL){
            printf("Error opening file.\n");
        }
    
        Data medical[100];
        int read = 0;
        int records = 0;
        int i;
        int hasil[100];
    
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
        printf("Mencari data provinsi dengan jumlah puskesmas terkecil\n\n");
        printf("Provinsi\t\t Jumlah\n");
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        int count = 1;
        for (int i=0; i<records; i++){
          for (int j=i+1; j<records; j++){
            if (strcmp(medical[i].prov, medical[j].prov) == 0 && (strcmp(medical[j].prov, "0") != 0)){
              count = count + 1;
                strcpy(medical[j].prov, "0");
            }
          }
            if (strcmp(medical[i].prov, "0") != 0){
                printf("%s\t\t %d\n", medical[i].prov, count);
            }
            hasil[i] = count;
            count = 1;
        }
        printf("--------------------------------------------------------------------------------------------------------------------\n");
        int min = hasil[0];
        for (int i=0; i<records; i++){
          if (min > hasil[i]){
            min = hasil[i];
          }
        }
        printf("Jumlah puskesmas terkecil adalah %d\n", min);
        printf("Provinsi dengan jumlah puskesmas terkecil adalah ");
        for (int i=0; i<records; i++){
            if (min == hasil[i]){
                if (strcmp(medical[i].prov, "0") != 0){
                    printf("%s, ", medical[i].prov);
                }
            }
        }
        printf("\n");
}

void sort_tipe(){
    printf("-- MENGURUTKAN DATA BERDASARKAN TIPE --\n");
    FILE *file;
    file = fopen("myfaskes.txt", "r");
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
    file = fopen("myfaskes.txt", "w");
    for (int i = 0; i < records; i++){
        for (int j = 0; j < records; j++){
            if (strcmp(medical[i].tipe, medical[j].tipe) < 0){
                Data temp = medical[i];
                medical[i] = medical[j];
                medical[j] = temp;
            }
        }
    }
    for (int i = 0; i< records; i++){
        fprintf(file, "%d,%s,%s,%s,%s\n", medical[i].no, medical[i].prov, medical[i].tipe, medical[i].nama, medical[i].alamat);
    }
    fclose(file);
    puskes();
}
