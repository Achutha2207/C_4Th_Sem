#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
int *a , n , key , found ;
int bubblesort(int a[] ){

for(int i = 0 ; i < n ; i++){
	for(int j = 0 ; j < n-i-1 ;  j++){
		if(a[j]>a[j+1]){
			int temp = a[j];
			a[j]=a[j+1];
			a[j+1]=temp;}}}}

int binarysearch(int key){
	int low = 0 , high=n-1;
	int mid ;
	while(low<=high){
		mid=low+(high-low)/2;
		if(a[mid]==key){
			printf("Key %d Found at %d Index\n",key,mid);
			
			return 0;}
		else if(key>a[mid]){
			low=mid+1;}
		else if(key<a[mid]){
			high=mid-1;}
		else{
			printf("Key %d Not Found \n",key);}
	}}

void main(){
	printf("Enter The Valur Of n\n");
	scanf("%d",&n);

	a=(int *)malloc(n*sizeof(int ));

	for(int i = 0 ; i < n ; i++){
		a[i]=rand()%100;}

	printf("The Random Elements Are\n");
	for(int i = 0 ; i < n ; i++){
		printf("%d\t",a[i]);}printf("\n");

	clock_t s1,e1,s2,e2;
	double t1,t2;

	s1=clock();
	bubblesort(a);
	e1=clock();
	t1=(double)(s1-e1)/CLOCKS_PER_SEC;
	printf("The Time Required To Compute BUBBLE SORT Is %f s\n",t1);

	printf("Sorted ELements Are\n");

	for(int i = 0 ; i < n ; i++){
		printf("%d\t",a[i]); }printf("\n");

	printf("Enter The Key Element You Want To Search In The Array\n");
	scanf("%d",&key);

	s2=clock();

	binarysearch(key);

	e2=clock();

	t2=(double)(s2-e2)/CLOCKS_PER_SEC;

	printf("The Time Required To Compute BINARY SEARCH Is %f s\n",t2);}

	

