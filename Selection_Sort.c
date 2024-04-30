#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void main(){
int *a , n;

printf("Enter The Number Of Elements You Want To Store In The Array\n");
scanf("%d",&n);

a=(int*)malloc(n*sizeof(int));

for(int i = 0 ; i<n ; i ++){
	*(a+i)=rand()%10;}

printf("Random Elements In The Array Are\n");

for(int i = 0 ; i<n ; i ++){
	printf("%d\t",*(a+i));}
printf("\n");

int swap=0;

for(int i = 0 ; i < n-1 ; i++){

for(int j = i+1 ; j<n;j++){
		
	if(*(a+i)>*(a+j)){
	
		int temp=*(a+i);
		*(a+i)=*(a+j);
		*(a+j)=temp;
		swap+=1;
		printf("Swap %d\n",swap);
		}}}

printf("Sorted Array\n");

for(int i = 0 ; i < n ; i ++){
	printf("%d\t",*(a+i));}
printf("\n");}

