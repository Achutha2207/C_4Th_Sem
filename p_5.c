#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int n=10;
int a[10];
void merge(int low , int mid , int high){
int  b[n]; 
int i; //Index For b
int h; //Index For a
int m; //for while loop
int k; //arbitrary index
i=low;
h=low;
m=mid+1;

while(h<=mid&&m<=high){
	
	//If both sub arrays has elements

	if(a[h]<=a[m]){
		b[i]=a[h];
		h++;}
	else{
		b[i]=a[m];
		m++;}
	i++;}

//if left subarray is filled

if(h>mid){
	for(k=m;k<=high;k++){
		b[i]=a[k];
		i++;
	}}
//If right subarray is filled
else{
	for(k=h;k<=mid;k++){
		b[i]=a[k];
		i++;}}
for(k=low ; k <= high ; k++){
	a[k]=b[k];}}
void merge_sort(int low , int high){
	int mid;
	if(low<high){
		mid = (high+low)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low , mid , high);}}
	
void main(){
	printf("Enter The Number Of ELements \n");
	scanf("%d",&n);

	printf("The Random Elements Are\n");

	for(int i = 0 ; i < n ; i++){
		a[i]=rand()%100;
		printf("%d\t",a[i]);}printf("\n");

	clock_t s , e;
	double t;

	s=clock();

	merge_sort(0,n-1);

	e=clock();

	t=(double)(e-s)/CLOCKS_PER_SEC;

	printf("Sorted ELements Are\n");
	for(int i = 0 ; i < n ; i++){
		printf("%d\t",a[i]);}printf("\n");
	printf("The Time Required To Compute MergeSort Is %f\n",t);
}
