#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"
#include "structs/structs.h"

ServerInfoGroupEnum serverInfoGroupEnum = rocky_linux;
ServerInfoStruct serverInfoStruct;



int main(){
    
    int islem;

    printf("Yapmak istediğiniz işlemi seçiniz: \n1) Sunucu ekleme...\n2) Sunucu listeleme\n");
    scanf("%d",&islem);

    switch (islem)
    {
    case 1:
        printf("Sunucu eklemeyi seçtiniz...");
        break;
    case 2:
        printf("Sunucu listelemeyi seçtiniz...");
        break;
    default:
        printf("1 veya 2 numaralı seçeneği seçmelisiniz...\n");
        break;
    }


}

