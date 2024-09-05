#include<stdio.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int *a,n;
int main(){
	cout<<"Enter n"<<endl;
	cin>>n;
	a=(int *) malloc(n*sizeof(int));

	cout<<"Enter The Numbers"<<endl;

	for(int i = 0 ; i < n ; i++){
		a[i]=rand()%100;}
	
	

	for(int i = 1 ; i < n ; i++){
		int j=i-1;
		int v=a[i];

		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;}
		a[j+1]=v;}






	cout<<"Sorted Elements Are"<<endl;
	for(int i =0  ; i < n ; i++){
		printf("%d\t",a[i]);}cout<<endl;







	return 0;}




