#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	char a[100]={"abcdefg"};
	int length = strlen(a);//length-1 ���±�λ�� 
	int n =0;
	
	for(int i= 0;i<3;i++){//������λ 
		char *p = a;
		char b = *p;	
		for(int j=0;j<length;j++){
			*p=*(p+1);
			p++;
		}
		a[length-1]=b;
	}
	printf("%s",a);
	return 0;
}

