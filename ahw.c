#include <sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
int main(void){
	int fd, n;
	off_t start, cur;
 	char buf[256];
	fd=open("test.txt",O_RDONLY);
	if(fd==-1){
		perror("Open test.txt");
		exit(1);
	}
	start=lseek(fd,23,SEEK_SET);
	n=read(fd,buf,17);
	buf[n]='\0';

	printf("Offset start = %d, Read Str=%s, n=%d\n", (int)start,buf,n);
	close(fd);
	return 0;
}
