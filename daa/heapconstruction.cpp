#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int main(){
	int n ;

	cin>>n;

	int a[n+1];

	for(int i = 1 ; i <= n ; i++){
		cin>>a[i];}
	int count=0;
	for(int i = n/2 ; i>=1 ; i--){
		int k=i;
		int v=a[k];
		int heap=0;
		while(!heap&&2*k<=n){
			int j=2*k;
			if(j<n){
				if(a[j]<a[j+1]){j++;}}
			if(v>=a[j]){
				heap=1;
				count++;
			}
			else{
				a[k]=a[j];
				k=j;}
			a[k]=v;}}
	for(int i = 1; i <=n ; i++){
		cout<<a[i]<<"\t";}cout<<endl;
	return 0;}

