#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void main(){
        int *a,n,check;
        printf("Enter The Number Of Elements You Want To Store In The Array\n");
        scanf("%d",&n);

        a = (int*)malloc(n*sizeof(int));
        for(int i = 0 ; i < n ; i ++){
                *(a+i)=rand()%100;}
        
        printf("The Elements In The Array Are\n");

        for(int i = 0 ; i < n ; i ++ ) {
 		printf("%d\t",*(a+i));}printf("\n");

	for(int i = 0 ; i < n-2 ; i ++){
		for(int j= i+1 ; j < n-1 ;j++){
			if(*(a+i)==*(a+j)){
				check=1;
                printf("The Array Is Ambiguous\n");
		exit(1);
			}}}
	
	printf("The Array Is Unambiguous\n");
}


