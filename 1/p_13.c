#include<stdio.h>
#include<math.h>
#define FALSE 0
#define TRUE 1

int a[20];

int place(int k , int i){
	int j ; 

	for(j=1;j<=k;j++){
		if((a[j]==i)||(abs(a[j]-i)==abs(j-k)))
			return FALSE;}
	return TRUE;
}

int nqueens(int k , int n){
	int i , a;
	for(i=1;i<=n;i++){
		if(place(k,i)) {a[k]=i;
			if(k==n){
				for(a=1;a<=n;a++){
					printf("%d\t",a[a]);}
				printf("\n");}
			else{
				nqueens(k+1,n);}}} return 0;}
int main(){
	int n ;
	printf("Enter The Value Of n ");
	scanf("%d",&n);
	if(n<0||n==0||n==2||n==3){
		printf("The Solution To %d Doesn't Eaists \n",n);
		exit(1);}
	printf("The Solution Of nQueens Problem Is \n");
	nqueens(1,n);
        return 0;}
