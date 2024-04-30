#include<stdio.h>
#include<stdlib.h>
void hannoi(int n , char s , char d , char a){

	//s -> SOURCE
	//a -> AUCILIARY
	//d -> DESTINATION
	

	if(n==1){
		printf("Move Disk 1 From Rod %c To %c \n",s,d);
		return;}
	hannoi(n-1,s,a,d);
	printf("Move Disk %d from Rod %c To %c\n",n,s,d);
	hannoi(n-1,a,d,s);}


void main(){

	int n ;

	printf("Enter The Number Of Disks\n");
	scanf("%d",&n);

	hannoi(n,'A','C','B');}
