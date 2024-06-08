#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int *a , n , key;

void insertionsort(int a[] ){
		int i = 1;
		int j=i-1;
		key=a[j];
		for(int i = 1 ; i<n;i++){
			key=a[i];
			j=i-1;
			while(j>=0&&key<a[j]){
				a[j+1]=a[j];
				
				j--;}a[j+1]=key;}}


void main(){
	printf("Enter The Value Of n\n");
	scanf("%d",&n);

	clock_t s,e;
	double t;

	a=(int *)malloc(n *sizeof(int));

	printf("The Random Elements Are\n");
	for(int i = 0 ; i < n ; i++){
		a[i]=rand()%100;
	printf("%d\t",a[i]);}printf("\n");

	s=clock();
	insertionsort(a);
	e=clock();

	t=(double)(e-s)/CLOCKS_PER_SEC;

	printf("Sorted Array\n");
	for(int i = 0 ; i < n; i++){
		printf("%d\t",a[i]);}printf("\n");
	printf("The Time Required To Compute INSETION SORTIs %f s\n",t);}
	

