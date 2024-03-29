#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>
#include <netinet/in.h>
#include "enums/enums.h"


typedef struct serverInfoStruct
{
    char serverName[30];
    struct in_addr ip_address; 
}ServerInfoStruct;


typedef struct ip
{
    
}Ip;

 





int main(){

    ServerInfoGroupEnum huseyin = ubuntu;
    printf("%d", huseyin );


}

void show_server_info(ServerInfoStruct s){

}