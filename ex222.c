#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int ispn(int n);//소수인지 아닌지 확인하기 위해 만든 함수 
int main(void){
	//int status;
	int i;
	pid_t pid;
	switch (pid=fork()){ //스위치문 
		case -1://오류일때 
			perror("fork");
			exit(1);
			break;
		case 0:	//자식프로세스 
			switch (pid=fork()){//스위치문 
				case -1:
					perror("fork");
					exit(1);
					break;
				case 0:	//자식프로세스 
					//printf("forkc1\n");
					for(i=1;i<25000;i++)
						if(ispn(i)){
						printf("%d\n",i);
						}
					break;
				default://부모프로세스	
					//wait(&status);//자식프로세스가 끝날때까지 대기 
					//printf("forkp1\n");
					for(i=25000;i<50000;i++)
						if(ispn(i))
							printf("%d\n",i);
					break;	
			}
			break;
		default://부모프로세스 
			//wait(status);//자식프로세스가 끝날때까지 대기 
			switch (pid=fork()){//스위치문 
				case -1://오류일때 
					perror("fork");
					exit(1);
					break;
				case 0:	//자식프로세스 
					//printf("forkc2\n");
					for(i=50000;i<75000;i++)
						if(ispn(i))
							printf("%d\n",i);
					break;
				default://부모프로세스 
					//wait(&status);//자식프로세스가 끝날때까지 대기 
					//printf("forkp2\n");
					for(i=75000;i<=100000;i++)
						if(ispn(i))
							printf("%d\n",i);
					break;	
			}
		}
	printf("End of fork\n");
	return 0;
}
int ispn(int n) //소수라면 1을 리턴하고 아니라면 0을 리턴한다. 
{
	int j=0;
	int last=n/2;
	if(n<=1)
		return 0;
	for(j=2;j<=last;j++)
		if((n%j)==0)
			return 0;
	return 1;
}
