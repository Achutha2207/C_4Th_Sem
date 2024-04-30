#include<stdio.h>

void main(){
	int n;

	printf("Enter Positive Natural Number\n");
	scanf("%d",&n);
	int c=1;

	while(n>1){

		c+=1;

		n/=2;

	}

	printf("The Number Of Binary Digits Required To Store %d Is %d\n",n,c);}
