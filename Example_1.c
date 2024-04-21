#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main(){
	int *a,n,max;
	printf("Enter The Number Of Elements You Want To Store In The Array\n");
	scanf("%d",&n);

	a = (int*)malloc(n*sizeof(int));
	for(int i = 0 ; i < n ; i ++){
		*(a+i)=rand()%100;}
	
	printf("The Elements In The Array Are\n");

	for(int i = 0 ; i < n ; i ++ ) {
		printf("%d\t",*(a+i));}printf("\n");

	max=*(a+0);
	for(int i = 1 ; i < n ; i ++){
	if(*(a+i)>max){
		max=*(a+i);}}
	printf("Maximum Element In The Arrray Is %d\n",max);
	free(a);	
}
