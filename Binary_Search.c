#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

//Binary Search Algorithm

void binary_search(int *a , int n , int key){
int l=0;
int h=n-1;
int found=0;
while(l<=h){
int m = l + (h-l)/2;
int value = *(a+m);
printf("Middle %d \n",m);
if(value<key){l=m+1;}
else if(value==key){printf("%d Found At Index %d\n",key,m);
found=1;
break;}
else{h=m-1;}}if(found==0){
printf("%d Not Found\n",key);}}

void main(){
int *a , n;

//n

printf("Enter The Value Of n\n");
scanf("%d",&n);

//DMA

a=(int *)malloc(n*sizeof(n));

//Random Number Generation

for(int i = 0 ; i< n ; i++){
*(a+i)=rand()%2000;}

//Print Unsorted Array

printf("Random Numbers Are\n");
for(int i = 0 ; i< n; i++){
printf("%d\t",*(a+i));}

//BubbleSort

for(int i = 0 ; i < n -1 ; i ++){
for(int j = 0 ; j < n-i-1;j++){
if(*(a+j)>*(a+j+1)){
int t = *(a+j);
*(a+j)=*(a+j+1);
*(a+j+1)=t;}}}
printf("\n");


//Sorted Array

printf("The Sorted Array\n");
for(int i = 0 ; i < n ; i ++){
printf("%d\t",*(a+i));}
printf("\n");
int key;
printf("Enter The Key You Need To Search In The Above Elements\n");
scanf("%d",&key);

//Time Calculation

clock_t start_time = clock();
binary_search(a,n,key);
clock_t end_time = clock();

double final_time = ((double)(end_time-start_time))/CLOCKS_PER_SEC;

 printf("Time required for binary search %.fµs\n",final_time*1000000);
 printf("Number Of Steps Required %.f\n",log2(n));


}
