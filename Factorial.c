#include<stdio.h>


int fact(int n){
	if(n==0){
		return 1;}
	else{
	return fact(n-1)*n;}}

void main(){

	int n,answer ;

	printf("Enter The Number For Which YOu Want TO Calculate The Factorial For\n");
	scanf("%d",&n);

	printf("The Factorial Of %d Is \n");

	answer=fact(n);

	printf("%d\n",answer);}
