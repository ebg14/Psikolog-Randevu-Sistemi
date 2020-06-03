#include <stdio.h>
#include "randevuOps.h"

int main()
{   int input =0;
    int run = 1;
    createArray();

    while(run){

    printf("1. Randevulari goster\n2. Randevu ara\n3. Randevu ver\n4. Randevu sil\n5. Exit\n");
    int control = scanf("%d", &input);
    while ( ((control = getchar()) != EOF && control != '\n') || (!(1<= input && input <= 5) ) ){
        printf("1 ve 5 arasi deger giriniz");
        scanf("%d", &input);}
    switch (input) {
    case 1:{
        randevuGoster();
        break;
    }
    case 2:{
        int input2;
        int run2 = 1;
        while(run2){
            printf("2.1. Ada gore\n2.2. Gune gore\n2.3. Geri Don\n");
            int control2 = scanf("%d", &input2);
            while ( ((control2 = getchar()) != EOF && control2 != '\n') || (!(1<= input && input <= 3) ) ){
                printf("1 ve 3 arasi deger giriniz");
                scanf("%d", &input);}
            switch (input2) {
            case 1:{
                randevuAra(1);
                break;
            }
            case 2:{
                randevuAra(2);
                break;
            }
            case 3:{
                run2 = 0;
                break;
            }
            }
        }

        break;
    }
    case 3:{
            randevuVer();

        break;
    }
    case 4:{
        randevuSil();

        break;
    }
    case 5:{
        exitApp();
        run = 0;
        break;
    }

    }

 }
    return 0;
}
