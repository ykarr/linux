#include<stdio.h>
#include<sys/time.h>
int main(void){
	int i,j;
	struct timeval t1,t2;
	gettimeofday(&t1,NULL);
	for(i=1;i<=100;i++)
		for(j=1;j<10;j++)
			printf("%d*%d=%d\n",i,j,i*j);
	gettimeofday(&t2,NULL);
	printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec+t1.tv_usec*0.000001));
	return 0;
}
