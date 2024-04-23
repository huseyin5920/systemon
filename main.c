#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"
#include "structs/structs.h"
#include <unistd.h>
#include "log_color/color.h"
#include <stdarg.h>
#include <libssh/libssh.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

ServerInfoGroupEnum serverInfoGroupEnum = rocky_linux;
ServerInfoStruct serverInfoStruct;
void print_color(const char *color_code, const char *format, ...);
bool isValidIpAddress(char *ipAddress);

int main()
{
    // TODO: kritik değişkenler .env dosyasından alınacak.
    PGconn *conn;
    ConnStatusType conn_status;
    ExecStatusType status;
    PGresult *res;
    const char *status_str;

    char server_ip_address[15];
    char *p_server_ip_address;

    unsigned short int portNumber;

    conn = PQconnectdb("user=username password=password dbname=systemon host=localhost port=5432");
    conn_status = PQstatus(conn);

    if (conn_status == CONNECTION_BAD)
    {
        print_color(RED, "Connection to database failed %s\n", PQerrorMessage(conn));
        PQfinish(conn);
        exit(EXIT_FAILURE);
    }
    if (conn_status == CONNECTION_OK)
    {
        print_color(GREEN, "Connection to database okey %s\n", PQerrorMessage(conn));
    }

    res = PQexec(conn, "CREATE TABLE iars(Id INTEGER PRIMARY KEY,"
                       "Name VARCHAR(20), \
                        Price INT)");

    status = PQresultStatus(res);

    if (status == PGRES_COMMAND_OK)
    {
        status_str = PQresStatus(status); // PQresStatus fonksiyonunun döndürdüğü metni bir const char * değişkenine atama
        print_color(YELLOW, "Sorgu durumu: %s --> ", status_str);
        const char *error_message = PQerrorMessage(conn);
        print_color(GREEN, "BAŞARILI %s\n", error_message);
        PQclear(res);
    }
    if (status != PGRES_COMMAND_OK)
    {
        status_str = PQresStatus(status); // PQresStatus fonksiyonunun döndürdüğü metni bir const char * değişkenine atama
        const char *error_message = PQerrorMessage(conn);
        print_color(YELLOW, "Sorgu durumu: %s --> ", status_str);
        print_color(RED, "HATA: %s\n", error_message);
    }

    PQfinish(conn);

    int islem;

    printf("Yapmak istediğiniz işlemi seçiniz: \n1) Sunucu ekleme...\n2) Sunucu listeleme\n");
    scanf("%d",&islem);

    switch (islem)
    {
    case 1:
        printf("Sunucu eklemeyi seçtiniz...\nBilgileri Doldurunuz\n");
        printf("sunucu ip giriniz: ");
        scanf("%s", server_ip_address);
        printf("%s", server_ip_address);
        if (isValidIpAddress(server_ip_address)) {
            printf("%s is a valid IP address.\n", server_ip_address);
        } else {
            printf("%s is not a valid IP address.\n", server_ip_address);
        }
        printf("sunucu ssh giriniz: ");
        scanf("%hu", &portNumber);
        printf("%d", portNumber);
        break;
    case 2:
        printf("Sunucu listelemeyi seçtiniz...");
        break;
    default:
        printf("1 veya 2 numaralı seçeneği seçmelisiniz...\n");
        break;
    }
}

void print_color(const char *color_code, const char *format, ...)
{
    va_list args;
    va_start(args, format);
    printf("%s", color_code);
    vprintf(format, args);
    printf("%s", RESET);
    va_end(args);
}


bool isValidIpAddress(char *ipAddress) {
    // IP adresinin noktalarla ayrıldığını ve 4 bileşene sahip olduğunu kontrol ediyoruz
    int dotCount = 0;
    for (int i = 0; ipAddress[i] != '\0'; i++) {
        if (ipAddress[i] == '.') {
            dotCount++;
        }
    }
    if (dotCount != 3) {
        return false;
    }

    // IP adresinin bileşenlerini kontrol ediyoruz
    char *token = strtok(ipAddress, ".");
    while (token != NULL) {
        // Her bileşenin sayısal bir değer olup olmadığını kontrol ediyoruz
        for (int i = 0; token[i] != '\0'; i++) {
            if (!isdigit(token[i])) {
                return false;
            }
        }
        // Her bileşenin 0 ile 255 arasında bir değere sahip olduğunu kontrol ediyoruz
        int num = atoi(token);
        if (num < 0 || num > 255) {
            return false;
        }
        token = strtok(NULL, ".");
    }

    return true;
}