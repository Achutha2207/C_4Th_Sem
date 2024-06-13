#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int *a  , n,l,r,left,right;
void heap_sort(int a[]){
	int k=1;
	 left=2*k;
	right=l+1;
	int x=1;
	while(a[k]<a[left]||a[k]<a[right]&&x!=n/2){
		
		l=2*x;
		r=l+1;
		if(a[x]<a[l]){
		int z=a[x];
		a[x]=a[l];
		a[l]=z;}
		if(a[x]<a[r]){
			int y = a[x];
			a[x]=a[r];
		        a[r]=y;}
		x++;

		
	}}


void  main(){int r;

	printf("Enter The Value Of n\n");
	scanf("%d",&n);

	a=(int *) malloc((n+1)*sizeof(int));
	printf("Do You  Want To Give The Values Or Randomly Allocate? [0/1]\n");
	scanf("%d",&r);
	if(r==0){
		printf("Enter The Elements\n");
		for(int i = 1 ; i  < n+1 ; i++){
			scanf("%d",&a[i]);}}

	else{

	printf("The Random Elements Are\n");
	for(int i = 1 ; i< n+1 ; i++){
		a[i]=rand()%100;
		printf("%d\t",a[i]);}
	printf("\n");}

	clock_t s , e ;
	double t ;

	s=clock();

	heap_sort(a);

	e=clock();

	t=(double)(e-s)/CLOCKS_PER_SEC;

	printf("Sorted Elements\n");

	for(int i = 1 ;  i < n+1 ; i++){
		printf("%d\t",a[i]);}printf("\n");
	printf("The Time Required To Compute Merge Sort Is %f seconds\n",t);}

