#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

using namespace std;

int n;
int *a;
int i , j , pivot;

int partition( int low , int high){
	 i=low+1;
	 j=high;
	 pivot=a[low];

	while(1){
		while(i<high&&a[i]<=pivot){i++;}
		while(a[j]>pivot){j--;}
		if(i<j){
		int t =a[i];
		a[i]=a[j];
		a[j]=t;}
		
		else{
		int temp=a[j];
		a[j]=a[low];
		a[low]=temp;
		return j;}}}


void quicksort(int low , int high){
	if(low<high){
		int j=partition(low,high);
		quicksort(low,j-1);
		quicksort(j+1,high);}}

int main(){

		n=10;
		a=(int *)malloc(n*sizeof(int));
		
			for(int i =0;i<n;i++){
				a[i]=rand()%2000;}

			quicksort(0,n-1);

			for(int i = 0 ; i < n ; i++){
				printf("%d\t",a[i]);}cout<<endl;
			free(a);
			return 0;}
