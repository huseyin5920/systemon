#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>



typedef struct serverInfoStruct
{
    char serverName[30];
    int serverGroup;
    struct in_addr ip_address; 
}ServerInfoStruct;

 
