#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>

#define BUFLEN 503
#define PORT 8885

void die(char *s)
{
	perror(s);
	exit(1);
}

int main(void)
{
	struct sockaddr_in si_me, si_other;
	
	int s, i,j, slen = sizeof(si_other) , recv_len;
	char buf[BUFLEN];
	
	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}
	
	memset((char *) &si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
	{
		die("bind");
	}
	
	char fname[20];
	FILE *fp;
	recv_len = recvfrom(s, buf, 20, 0, (struct sockaddr *) &si_other, &slen);
	
	char fna[100];
	
	strcpy(fna,buf);
	
	memset(buf,0,503);
	recv_len = recvfrom(s, buf, 20, 0, (struct sockaddr *) &si_other, &slen);
	
	int len= strlen(fna);
	
	for(j=len-1;j>=0;j--)
	{
		if(fna[j]=='.')
		{
			fna[j-1]='1';
		}
	}
	unsigned long  mm = atoi(buf);
	
	
	fp=fopen(fna,"wb");
	int itr=1;
	memset(buf,0,503);
	while(itr*503<mm)
	{
		if ((recv_len = recvfrom(s, buf, 503, 0, (struct sockaddr *) &si_other, &slen)) == -1)
		{
			die("recvfrom()");
		}
		fwrite(buf,503, 1, fp);
		memset(buf,0,503);
		itr++;
	}
	printf("%ld",(mm%503));
	recv_len = recvfrom(s, buf, (mm%503), 0, (struct sockaddr *) &si_other, &slen);
	
	fwrite(buf,(mm%503), 1, fp);
	memset(buf,0,503);
	fclose(fp);
	close(s);
	
	return 0;
}

//client
#include<stdio.h>
#include<string.h> 
#include<stdlib.h> 
#include<arpa/inet.h>
#include<sys/socket.h>

#define SERVER "127.0.0.1"
#define BUFLEN 503
#define PORT 8885

void die(char *s)
{
	perror(s);
	exit(1);
}
unsigned long fsize(char* file)
{
    FILE * f = fopen(file, "r");
    fseek(f, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(f);
    fclose(f);
    return len;
}

int main(void)
{
	struct sockaddr_in si_other;
	int s, i, slen=sizeof(si_other);
	char buf[BUFLEN];
	char message[BUFLEN];

	if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}

	memset((char *) &si_other, 0, sizeof(si_other));
	si_other.sin_family = AF_INET;
	si_other.sin_port = htons(PORT);
	
	if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
	{
		fprintf(stderr, "inet_aton() failed\n");
		exit(1);
	}
	
	char  fname[20];
	printf("Enter Filename with extension: ");
	scanf("%s",fname);
	sendto(s, fname, 20 , 0 , (struct sockaddr *) &si_other, slen);
	
	memset(message,0,503);
	
	unsigned long siz = fsize(fname);
	printf("%ld",(siz % 503));
	char str[10];
	sprintf(str, "%ld", siz);
	sendto(s, str, 20 , 0 , (struct sockaddr *) &si_other, slen);
	
	FILE *f;
	
	f=fopen(fname,"rb");
	memset(message,0,503);
	fread(message, 503,1,f);
	
	int itr =1;
	while(itr*503<siz){
		
		if (sendto(s, message, 503 , 0 , (struct sockaddr *) &si_other, slen)==-1)
		{
			die("sendto()");
		}
		memset(message,0,503);
		fread(message, 503,1,f);
		itr++;
	}
	fread(message, (siz % 503),1,f);
	sendto(s, message, (siz % 503) , 0 , (struct sockaddr *) &si_other, slen);
	
	memset(message,0,503);
	fclose(f);
	close(s);
	
	return 0;
}
