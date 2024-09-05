#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;



int main(){

	int n ;
	cin>>n;

	int a[n];

	for(int i = 0 ; i < n ;i++){
		a[i]=rand();}

/*	while(1){
	for(int i = n/2; i >=1; i--){
		int l=i*2;
		int r=(i*2)+1;
		if(a[i]<a[l]){ int t=a[i];
			       a[i]=a[l];
			       a[l]=t;}
		if(a[i]<a[r]){ int t = a[i];
				a[i]=a[r];
				a[r]=t;}}}*/

	
	//INSERTION SORT 
	


	for(int i = 1 ; i < n;i++){
		int j=i-1;
		int key=a[i];

		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;}
		a[j+1]=key;}


	//for(int i = 0; i < n ; i++){
	//	printf("%d\t",a[i]);}cout<<endl;


	int low=0;
	int high=n-1;
	int key=a[0];
	//cout<<"Enter k"<<endl;
	//cin>>key;
	int count=0;
	while(low<=high){
		count++;
		int mid = (low+high)/2;
		if(a[mid]==key){
			long double log = log2l(n);
			printf("Found At %d Divided %d Times : log(%d) is %Lf \n",mid,count,n,log);
			exit(1);}
		else if(key<a[mid]){
			high=mid-1;}
		else if(key>a[mid]){
			low=mid+1;}}
	cout<<"Not Found"<<endl;
	return 0;}
