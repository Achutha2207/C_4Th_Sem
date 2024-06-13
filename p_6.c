#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int *a,n,pivot,i,j;

int partition(int low , int high){
	pivot=a[low];
	 i=low+1;
	 j=high;
	while(1){
		while(i<high&&a[i]<=pivot){i++;}
		while(a[j]>pivot){j--;}
		if(i<j){
			int temp = a[i];
			a[i]=a[j];
			a[j]=temp;}
		else{
			int t=a[j];
			a[j]=a[low];
			a[low]=t;
			return j;}}}


		
void quick_sort(int low , int high){
	if(low<high){
		int j=partition(low,high);
		quick_sort(low,j-1);
		quick_sort(j+1,high);}}


void main(){
	printf("Enter The Value Of n\n");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));

	printf("The Random Elements Are\n");

	for(int  i= 0 ; i < n ; i++){
		a[i]=rand()%100;
		printf("%d\t",a[i]);}printf("\n");
	clock_t s,e;
	double t;
	t=(double)(e-s)/CLOCKS_PER_SEC;
	s=clock();
	quick_sort(0,n-1);
	e=clock();
	printf("Sorted Elements Are\n");
	for(int i = 0 ; i < n ; i++){
	printf("%d\t",a[i]);}
	printf("\n");
	printf("The Time Required To Compute Quick_Sort Is %f\n",t);}
