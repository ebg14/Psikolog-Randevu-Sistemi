#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char ad[20];
    char soyad[20];
    int gun;
    int saat;
}Randevu;

Randevu *randevular;// = (Randevu *)malloc(sizeof (Randevu) * 5);
int length;
FILE *fptr;
const char * gunler[] = {"empty","Pazartesi","Sali","Carsamba", "Persembe", "Cuma", "Cumartesi","Pazar"};

void findLength(){

    if((fptr = fopen("C:/Users/beyza/OneDrive/Belgeler/QT Projects/Proje2/randevular.txt","r"))==NULL){
        printf("error");
    }
    else{
        length++;
        while (!feof(fptr)) {
            if(fgetc(fptr) == '\n')
            length++;
        }
    }
}
void createArray(){
    findLength();
    randevular = (Randevu *)malloc(sizeof (Randevu) * length);
    FILE *fptr;
    if((fptr = fopen("C:/Users/beyza/OneDrive/Belgeler/QT Projects/Proje2/randevular.txt","r"))==NULL){
        printf("error");
    }
    else{
        int i = 0;
        while(!feof(fptr)){
           Randevu r;
           fscanf(fptr,"%s %[^,] %*c %d %*c %d",r.ad,r.soyad,&r.gun,&r.saat);
            randevular[i] = r;
            i++;
        }
}
    fclose(fptr);
}

void randevuGoster(){

    printf("Randevular\nAd\tSoyad\t\tGun\t\tSaat\n-----------------------------------------------\n");
        for(int i = 0; i < length; i++){
            printf("%s\t%-10s\t%-10s\t%.2d.00\n", randevular[i].ad, randevular[i].soyad, *(gunler + randevular[i].gun),randevular[i].saat);
        }
}

void randevuAra(int option){
    if(option == 1){
        int flag = 0;
        printf("Ad giriniz:\n");
        char arananAd[20];
        gets(arananAd);
        printf("Ad\tSoyad\t\tGun\t\tSaat\n-----------------------------------------------\n");

        for(int i = 0; i < length; i++){
            if(!strcmp(randevular[i].ad, arananAd)){
             flag = 1;
             printf("%s\t%-10s\t%-10s\t%.2d.00\n", randevular[i].ad, randevular[i].soyad, *(gunler + randevular[i].gun),randevular[i].saat);
        }
}
        if (flag == 0){
            printf("Boyle bir kayit bulunmamaktadir.\n");
        }
    }
    else{
        int arananGun;
        int flag = 0;
        printf("Gunu giriniz\n1- Pazartesi\n2- Sali\n3- Carsamba\n4- Persembe\n5- Cuma\n6- Cumartesi\n7- Pazar\n");
        int kontrol = scanf("%d", &arananGun);
        while(((kontrol = getchar()) != EOF && kontrol != '\n') || !(1 <= arananGun && arananGun <= 7)){
            printf("Lutfen 1-7 arasi bir sayi giriniz.");
        }
        printf("Ad\tSoyad\t\tGun\t\tSaat\n-----------------------------------------------\n");

        for(int i = 0; i < length; i++){
            if(randevular[i].gun == arananGun){
             flag = 1;
             printf("%s\t%-10s\t%-10s\t%.2d.00\n", randevular[i].ad, randevular[i].soyad, *(gunler + randevular[i].gun),randevular[i].saat);
        }
}
        if (flag == 0){
            printf("Boyle bir kayit bulunmamaktadir.\n");
        }


    }
}

void randevuVer(){

    Randevu r;
    printf("Ad giriniz\n");
    scanf("%s", r.ad);
    printf("Soyad giriniz\n");
    scanf("%s",r.soyad);
    int geciciGun;
    int geciciSaat;
    label1:
    printf("Gunu giriniz\n1- Pazartesi\n2- Sali\n3- Carsamba\n4- Persembe\n5- Cuma\n6- Cumartesi\n7- Pazar\n");
    int kontrol = scanf("%d", &geciciGun);
    while(((kontrol = getchar()) != EOF && kontrol != '\n') || !(1 <= geciciGun && geciciGun <= 7)){
        printf("Lutfen 1-7 arasi bir sayi giriniz.");
    }
    printf("Saat giriniz");
    kontrol = scanf("%d", &geciciSaat);
        while(((kontrol = getchar()) != EOF && kontrol != '\n') || !(7 <= geciciSaat && geciciSaat <= 20)){
            printf("Lutfen 7 ile 20 arasi bir sayi giriniz.");
        }
        for (int i = 0; i< length ; i++) {
            if(randevular[i].gun == geciciGun && randevular[i].saat ==geciciSaat){
                printf("Bu gun ve saat doludur, lutfen baska gun ve saat giriniz.\n");
                goto label1;
            }
        }

     r.gun = geciciGun;
     r.saat = geciciSaat;

     if((fptr = fopen("C:/Users/beyza/OneDrive/Belgeler/QT Projects/Proje2/randevular.txt","a"))==NULL){
         printf("error");
     }
     else{
             fprintf(fptr,"\n%s %s,%d,%d", r.ad, r.soyad, r.gun, r.saat);

         }

     randevular = (Randevu *)realloc(randevular, sizeof(Randevu) * (length + 1));
     randevular[length] = r;
     length++;
}
void randevuSil(){
    char isim[20];
    printf("Ad giriniz\n");
    scanf("%s",isim);
    int index = -1;
    for (int i = 0; i < length; i++) {
        if(!strcmp(randevular[i].ad, isim)){
            index = i;
        }
    }
    if(index == -1){
        printf("Kayit bulunamadi.");
    }else{
        for (int i = index; i < length - 1; i++) {
           randevular[i]=randevular[i+1];
        }
         randevular = (Randevu *)realloc(randevular, sizeof(Randevu) * (length - 1));
         length--;
    }
}


void exitApp(){
   /* FILE *fptr;
    if((fptr = fopen("C:/Users/beyza/OneDrive/Belgeler/QT Projects/Proje2/randevular.txt","w"))==NULL){
        printf("error");
    }
    else{
        for(int i = 0; i < length; i++){
            fprintf(fptr,"%s %s,%d,%d", randevular[i].ad, randevular[i].soyad, randevular[i].gun, randevular[i].saat);
             if(i != length -1){
                 fprintf(fptr,"\n");
             }
        }


    }*/
    fclose(fptr);
    free(randevular);
}
