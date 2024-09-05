#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;
int main(){

	int n ; 

	cin>>n;

	int a[n];

	for(int i= 2 ; i < n ; i++){
		a[i]=i;}

	for(int i = 2 ; i < sqrt(n) ; i++){
		int j=i*i;

		while(j<=n){
			a[j]=0;
			j+=i;}}

	for(int i=2 ; i < n ; i++){
		if(a[i]!=0){
			printf("%d\t",a[i]);}}cout<<endl;



	return 0;}

