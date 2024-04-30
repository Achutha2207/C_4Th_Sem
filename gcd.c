#include<stdio.h>

void main(){

	int a,b,r;

	printf("Enter The Value Of a\n");
	scanf("%d",&a);

	printf("Enter The Vlaue Of b\n");
	scanf("%d",&b);

	

	while(r!=0){
		r=a%b;
		a=b;
		b=r;
		

	}

	printf("The GCD Is %d\n",b);
}
