//This program will listen on port 8080 of my LAN and call another program on detecting a connection request


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <netinet/in.h>

int main(int argc, char* argv[]){
	
	printf("%d",SOCK_STREAM);

	pid_t pid  = fork();
	if(pid<0){
		perror("Fork failed");
		exit(1);
		
	}
	else if(pid == 0){
		execv("./server",NULL);	
	}
	wait(NULL);
	return 0;
}
