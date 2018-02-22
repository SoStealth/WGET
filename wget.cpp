/*
Made by Lorenzo Damiano
USAGE: wget_client IP filename
Simple client program who asks a server for a file via TCP socket connection
*/
#include "TCPv2.hpp"
#include <string.h>

#define PORT 80
#define REQUEST_HEADER "GET /"
#define REQUEST_FOOTER " HTTP/1.1"
#define RETURN_CODE_OK "200 OK"
#define ENDLINE "\n"

using namespace std;

int main(int argc, char* argv[]) {
    char* ip;
    char* filename;
	char* request;
    ClientTCP myself();
  
    if(argc!=3) {
        printf("USAGE:%s IP FILENAME\n",argv[0]);
		return -1;
    }
  	
	ip = argv[1];
	Address server(ip,PORT);
	if(myself.connetti(server)) {
		errore(-2,"connetti()\n");	
	}
	
	filename = argv[2];
	char* temp = concat(REQUEST_HEADER,filename);
	request = concat(temp,REQUEST_FOOTER);
	myself.invia(request);
	
	char* response = myself.ricevi();
	if(strstr(response,RETURN_CODE_OK)==NULL) {
		printf("ERROR 404\n");
		return -3;
	}
	
	char* content = strstr(response,ENDLINE);
	FILE* file = fopen(filename,"w");
	
  
    return 0;
}
