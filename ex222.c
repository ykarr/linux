#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
int ispn(int n);//�Ҽ����� �ƴ��� Ȯ���ϱ� ���� ���� �Լ� 
int main(void){
	//int status;
	int i;
	pid_t pid;
	switch (pid=fork()){ //����ġ�� 
		case -1://�����϶� 
			perror("fork");
			exit(1);
			break;
		case 0:	//�ڽ����μ��� 
			switch (pid=fork()){//����ġ�� 
				case -1:
					perror("fork");
					exit(1);
					break;
				case 0:	//�ڽ����μ��� 
					//printf("forkc1\n");
					for(i=1;i<25000;i++)
						if(ispn(i)){
						printf("%d\n",i);
						}
					break;
				default://�θ����μ���	
					//wait(&status);//�ڽ����μ����� ���������� ��� 
					//printf("forkp1\n");
					for(i=25000;i<50000;i++)
						if(ispn(i))
							printf("%d\n",i);
					break;	
			}
			break;
		default://�θ����μ��� 
			//wait(status);//�ڽ����μ����� ���������� ��� 
			switch (pid=fork()){//����ġ�� 
				case -1://�����϶� 
					perror("fork");
					exit(1);
					break;
				case 0:	//�ڽ����μ��� 
					//printf("forkc2\n");
					for(i=50000;i<75000;i++)
						if(ispn(i))
							printf("%d\n",i);
					break;
				default://�θ����μ��� 
					//wait(&status);//�ڽ����μ����� ���������� ��� 
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
int ispn(int n) //�Ҽ���� 1�� �����ϰ� �ƴ϶�� 0�� �����Ѵ�. 
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
