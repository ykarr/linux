#include<stdio.h>
//#include<sys/time.h>//시간측정을 위해 
int ispn(int n);//소수인지 아닌지 
int main(void){
	int i;
//	struct timeval t1,t2;
//	gettimeofday(&t1,NULL);
	for(i=1;i<=100000;i++)
		if(ispn(i)){
			printf("%3d\n",i);
		}
//	gettimeofday(&t2,NULL);
//	printf("%f\n",(t2.tv_sec+t2.tv_usec*0.000001)-(t1.tv_sec+t1.tv_usec*0.000001));
	return 0;
}
int ispn(int n)
{
	int i=0;
	int last=n/2;
	if(n<=1)
		return 0;
	for(i=2;i<=last;i++)
		if((n%i)==0)
			return 0;
	return 1;
}
