
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>
#include <ctype.h>


void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
     int sockfd, newsockfd, portno;
     socklen_t clilen;
     char buffer[512];
     struct sockaddr_in serv_addr, cli_addr;
     int n;
     if (argc < 2) {
         fprintf(stderr,"ERROR, no port provided\n");
         exit(1);
     }
     sockfd = socket(AF_INET, SOCK_STREAM, 0);
     if (sockfd < 0) 
        error("ERROR opening socket");
     bzero((char *) &serv_addr, sizeof(serv_addr));
     portno = atoi(argv[1]);
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = INADDR_ANY;
     serv_addr.sin_port = htons(portno);
     if (bind(sockfd, (struct sockaddr *) &serv_addr,
              sizeof(serv_addr)) < 0) 
              error("ERROR on binding");
     listen(sockfd,5);
     clilen = sizeof(cli_addr);
     newsockfd = accept(sockfd, 
                 (struct sockaddr *) &cli_addr, 
                 &clilen);
     if (newsockfd < 0) 
          error("ERROR on accept");
          
          
          
          FILE *fp;
         int ch = 0;
            fp = fopen("glad_receive.txt","a");            
            int words;
		read(newsockfd, &words, sizeof(int));
         
          while(ch != words)
       	   {
        	 read(newsockfd , buffer , 512); 
	   	 fprintf(fp , " %s" , buffer);   
		
		 ch++;
	   }
     	printf("The file was received successfully\n");
	   printf("The new file created is glad5.txt");
     close(newsockfd);
     close(sockfd);
     return 0; 
}

//client

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include<ctype.h>

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[512];
    if (argc < 3)
    {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
  
        bzero(buffer,512);
        
    FILE *f;
    
    int words = 0;
    char c;
     f=fopen("glad.txt","r");
    while((c=getc(f))!=EOF)			
	{	
		fscanf(f , "%s" , buffer);
		if(isspace(c)||c=='\t')
		words++;	
	}
	
       
      
	write(sockfd, &words, sizeof(int));
     	rewind(f);
      
         
	int sz = ftell(f);				
	printf("Size is %d \n" , sz);
          rewind(f);  
            */
       
    char ch ;
       while(ch != EOF)
      {
		
		fscanf(f , "%s" , buffer);
	
		write(sockfd,buffer,512);
		ch = fgetc(f);
      }
	printf("The file was sent successfully");
    
    close(sockfd);
    return 0;
}
