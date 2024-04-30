#include<stdio.h>
#include<stdlib.h>

int l,m,h,found=0;

int bs(int *a , int key,int n ){
l=0;
h=n-1;

while(found==0 && l<=h){
	m=l+(h-l)/2;
	if(*(a+m)==key){
	
	 if(found==0){
        printf("%d Not Found In The Array\n",key);}
	found=1;
	break;
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

		printf("%d\t",*(a+i));printf("\n");
	}

	printf("Enter The Element You Want To Search\n");
	scanf("%d",&key);

	bs(a,key,n);
	
	if(found==0){
	printf("%d Not Found In The Array\n",key);}

	else{
		printf("Element %d Found At Index %d\n",key,m);
}
}
