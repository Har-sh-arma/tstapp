//This program will listen on port 8080 of my LAN and call another program on detecting a connection request


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

void delay(int n){
	clock_t s = clock();
	while(n+s > clock())
		;
}

int main(int argc, char* argv[]){
		
	struct sockaddr_in myaddr;
	int sockid = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	printf("Socket initialized...");
	
	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(8080);
	inet_aton("192.168.0.103",&myaddr.sin_addr);

	int status = bind(sockid,(struct sockaddr*)&myaddr, sizeof(myaddr));
	printf("Listener application bound to port 8080");
	while(1){
		printf(".");
		delay(1000);
	};


	pid_t pid  = fork();
	if(pid<0){
		perror("Fork failed");
		exit(1);
		
	}
	else if(pid == 0){
		execv("./server",NULL);	
	}
	wait(NULL);
	status = close(sockid);
	return 0;
}
