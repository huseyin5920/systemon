#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"
#include "structs/structs.h"
#include <unistd.h>
#include "log_color/color.h"
#include <stdarg.h>

ServerInfoGroupEnum serverInfoGroupEnum = rocky_linux;
ServerInfoStruct serverInfoStruct;
void print_color(const char *color_code, const char *format, ...);

int main(){
    //TODO: kritik değişkenler .env dosyasından alınacak.
    PGconn *conn = PQconnectdb("user=username password=password dbname=systemon host=localhost port=5432");

    print_color(RED, "Aaaaaaaaaaaaaaaaaaaaa\n");

    printf("\033[0;31mBu metin kirmizi renkte.\033[0m\n");

    // Yeşil renkte bir metin yazdırma
    printf("\033[0;32mBu metin yesil renkte.\033[0m\n");

    // Mavi renkte bir metin yazdırma
    printf("\033[0;34mBu metin mavi renkte.\033[0m\n");

    // ConnStatusType status = PQstatus(conn);
    
    print_color(BLUE, "Bağlantı Durumu: %d\n", PQstatus(conn));
    printf("Bağlantı Durumu: %s\n", PQresStatus(PQstatus(conn)));



    // if (PQstatus(conn) == CONNECTION_BAD) {
    //     fprintf(stderr, "Connection to database failed %s\n",
    //             PQerrorMessage(conn));
    //     PQfinish(conn);
    //     exit(EXIT_FAILURE);
    // }  
    // if (PQstatus(conn) == CONNECTION_OK) {
    //     fprintf(stderr, "Connection to database okey %s\n",
    //             PQerrorMessage(conn));
    // }      

    // PGresult *res = PQexec(conn, "DROP TABLE IF EXISTS school");

    // printf("%s",PQresultStatus(res));
    
    // if (PQresultStatus(res) != PGRES_COMMAND_OK) {
    //     PQclear(res);
    // }
    

    // PQfinish(conn);

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




void print_color(const char *color_code, const char *format, ...) {
    va_list args;
    va_start(args, format);
    printf("%s", color_code);
    vprintf(format, args);
    printf("%s", RESET);
    va_end(args);
}
