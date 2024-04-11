#include<stdio.h>

void main(){
int m , n , r ;
int i=0;
printf("%d\n,",r);
printf("Enter The Value Of m and n \n");
scanf("%d%d",&m,&n);
int a=m;
int b=n;

// Euclids Algorithm

while(n!=0){
printf("Step:%d \n",i);
r=m%n;
m=n;
n=r;
i++;}
printf("GCD(%d,%d) Is %d\n",a,b,m);

//Method 2
int t;
if(m>n){
t=m;}
else{
t=n;}

while(m%t!=0){
if(m%t==0){
return t;}
else{
t+=1;}}
printf("GCD = %d\n",t);


// Method 3





}

