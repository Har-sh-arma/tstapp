//This program will listen on port 8080 of my LAN and call another program on detecting a connection request


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){

	pid_t pid  = fork();
	if(pid<0){
		perror("Fork failed");
		exit(1);
		
	}
	else{
		execv("./server",NULL);	
	}
	wait(NULL);
	return 0;
}