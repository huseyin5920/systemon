#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"
#include "structs/structs.h"
#include<unistd.h>

ServerInfoGroupEnum serverInfoGroupEnum = rocky_linux;
ServerInfoStruct serverInfoStruct;


int main(){
    //TODO: kritik değişkenler .env dosyasından alınacak.
    PGconn *conn = PQconnectdb("user=usernsame password=password dbname=systemon host=localhost port=5432");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed %s\n",
                PQerrorMessage(conn));
        PQfinish(conn);
        exit(EXIT_FAILURE);
    }  
    if (PQstatus(conn) == CONNECTION_OK) {
        fprintf(stderr, "Connection to database okey %s\n",
                PQerrorMessage(conn));
    }      

    PGresult *res = PQexec(conn, "DROP TABLE IF EXISTS school");
    
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        PQclear(res);
        
    }
    

    PQfinish(conn);

    // int islem;

    // printf("Yapmak istediğiniz işlemi seçiniz: \n1) Sunucu ekleme...\n2) Sunucu listeleme\n");
    // scanf("%d",&islem);

    // switch (islem)
    // {
    // case 1:
    //     printf("Sunucu eklemeyi seçtiniz...");
    //     break;
    // case 2:
    //     printf("Sunucu listelemeyi seçtiniz...");
    //     break;
    // default:
    //     printf("1 veya 2 numaralı seçeneği seçmelisiniz...\n");
    //     break;
    // }


}

