#include<stdlib.h>
#include<stdio.h>
int main(int argc,char *argv[]){
	FILE *rfp, *wfp; //���� ������� ���� �����ϰ�
	int i=0,num; //���ڸ� �ְ�
	if((rfp=fopen(argv[1],"r"))==NULL){
		perror("error");
		exit(1);
	}
	if((wfp=fopen("four.txt","w"))==NULL){
		perror("error");
		exit(1);
	}

	while(fscanf(rfp,"%d",&num)!=EOF){//while���� ������.
		if(num%4==0){
			fprintf(wfp,"%d\n",num);			
			i++;
		}
	}
	fprintf(wfp,"\n %d \n",i);
	
	fclose(rfp);
	fclose(wfp);
	return 0;
}

