#include<iostream>
#include<stdio.h>

using namespace std;

int main(){

	int n;
	cin>>n;

	int a[n];
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];}
	int j,min;
	for(int i = 0 ; i < n-1 ; i++){
		 min=i;
	for(j = i+1 ; j < n ; j++){
			if(a[min]>a[j]){min=j;}}
		int t = a[i];
		a[i]=a[min];
		a[min]=t;}

	for(int i = 0 ; i < n ; i++){
		printf("%d\t",a[i]);}printf("\n");
       return 0;}
