#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"
#include "structs/structs.h"

ServerInfoGroupEnum serverInfoGroupEnum = rocky_linux;
ServerInfoStruct serverInfoStruct;
void close_connection(PGconn *connection, int code) {
  PQfinish(connection);
  exit(code);
}



int main(){

    PGconn *conn = PQconnectdb("user=username password=password dbname=school host=localhost port=5432");

    if (PQstatus(conn) == CONNECTION_BAD) {
        fprintf(stderr, "Connection to database failed %s\n",
                PQerrorMessage(conn));
        close_connection(conn, 1);
    }  
    if (PQstatus(conn) == CONNECTION_OK) {
        fprintf(stderr, "Connection to database okey %s\n",
                PQerrorMessage(conn));
        close_connection(conn, 1);
    }      
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

