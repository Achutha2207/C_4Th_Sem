i#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int n;

int partition(int a[] , int low , int high){
	int pivot=a[low];

	int i=low+1;
	int j=high;

	while(1){
		while(a[i]<=pivot&&i<=high){
			i++;}
		while(a[j]>pivot){
			j--;}
		if(i<j){
			int t=a[i];
			a[i]=a[j];
			a[j]=t;}
		else if(i>=j){
			int te=a[j];
			a[j]=a[low];
			a[low]=te;
			return j;}
		}}






void quicksort(int a[], int low , int high){
if(low<high){
	int j=partition(a,low,high);
	quicksort(a,low,j-1);
	quicksort(a,j+1,high);}}




int main(){
	cin>>n;
	int a[n];

	for(int i= 0; i < n ; i++){
		cin>>a[i];}

	quicksort(a,0,n-1);

	for(int i = 0;i < n ; i++){
		printf("%d\t",a[i]);}cout<<endl;
	return 0;}
