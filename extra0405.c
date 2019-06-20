#include<sys/stat.h>
#include<dirent.h>
#include<stdlib.h>
#include<stdio.h>
void openn(char *name){
	DIR *dp;
	struct dirent *dent;
	struct stat buf;	
	char * namebuf;
	char path[BUFSIZ];	
	if((dp=opendir(name))==NULL){
		perror("opendir");
		exit(1);
	}
	while((dent=readdir(dp))){
		if(dent->d_name[0]=='.')
			 continue;
		else { 
			sprintf(path,"%s/%s",name,dent->d_name);
			stat(path,&buf);
			if(S_ISDIR(buf.st_mode)){ 
				openn(path);
			}
			printf("%d %s\n",(int)dent->d_ino,path);	
		}
	}	
	closedir(dp);
}
int main(int argc,char *argv[]){
	openn(argv[1]);
	return 0;
}
