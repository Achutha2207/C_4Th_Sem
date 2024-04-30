#include<stdio.h>
#include<stdlib.h>
int found=0;
int bs(int *a , int key,int n){

int l=0,m,h=n-1;
m=l+(h-l)/2;


while(found==0&&l<=h){
	
	if(*(a+m)==key){
	
	 
        printf("Element %d Found In The Array At Index %d\n",key,m);
	found=1;
	exit(1);
	}
	

	else if(*(a+m)>key){

	h=m-1;
	m=l+(h-l)/2;

	}
	else{
	l=m+1;
	m=l+(h-l)/2;
	}}
};

void main(){
	int n , key ,*a;
	printf("How Many Random Elements You Want To Store In The Array\n");
	scanf("%d",&n);

	a=(int *) malloc(n*sizeof(int));

	for(int i = 0 ; i< n ; i ++){
		*(a+i)=rand()%n;}
	printf("Random elements are\n");

	for(int i = 0; i < n ; i ++){

		printf("%d\t",*(a+i));
		
	}printf("\n");

	for(int i = 0 ; i < n-1 ; i ++){
		for(int j = i+1;j<n;j++){
			if(*(a+i)>*(a+j)){
				int temp=*(a+i);
				*(a+i)=*(a+j);
				*(a+j)=temp;}}}

	printf("Sorted Array\n");

	
        for(int i = 0; i < n ; i ++){

                printf("%d\t",*(a+i));
        }printf("\n");





	printf("Enter The Element You Want To Search\n");
	scanf("%d",&key);

	bs(a,key,n);
	if(found==0){
        printf("Element %d Not Found In The  Array\n",key);




	free(a);
	}}

