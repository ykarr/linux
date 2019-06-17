#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
int main(int argc, char *argv[]){
	DIR *dp;
	struct dirent *dent;
	if((dp=opendir(argv[1]))==NULL){
		perror("opendir:");
		exit(1);
	}
	while((dent=readdir(dp))){
		printf("%d ",(int)dent->d_ino);
		printf("%s\n",dent->d_name);
	}
	closedir(dp);
	return 0;
}
