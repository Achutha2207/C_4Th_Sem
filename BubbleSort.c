#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubblesort(int *a , int n ){

for(int i = 0 ; i < n-1 ; i ++){
    for(int j=0;j<n-i-1;j++){
        if(*(a+j)>*(a+j+1)){
            int temp = *(a+j);
            *(a+j)=*(a+j+1);
            *(a+j+1)=temp;}}}

printf("Sorted Elements Of The Array\n");

for(int i =0 ; i < n ; i++){
printf("%d\t",*(a+i));}printf("\n");};

void main(){
int *a, n;

printf("Enter The Value Of n\n");
scanf("%d",&n);

a=(int*)malloc(n*sizeof(int));
for(int i=0; i < n  ; i ++){
*(a+i)=rand()%2000;}


printf("Random Elements In The Array\n");
for(int i = 0 ; i < n ; i++){
printf("%d\t",*(a+i));}printf("\n");

clock_t start_time = clock();

bubblesort(a,n);

clock_t end_time=clock();

double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

printf("The Time Taken For Sorting Is %.6f seconds\n",elapsed_time);
free(a);

// Calculate space complexity
size_t space_complexity = n * sizeof(int); // Space for the input array
printf("Space complexity: %zu bytes\n", space_complexity);
}