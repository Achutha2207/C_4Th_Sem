#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n,d;
	cout<<"Enter Number Of Elements"<<endl;
	cin>>n;
	int a[n];
	//int b[(2^n)-(n-1)];
	int b[20000];
	int c[n][n];
	int x=pow(2,n);
	cout<<"Enter Elements"<<endl;
	for(int i=0 ; i < n ;i++){
		cin>>a[i];}
	for(int i = 0 ;i<n;i++){
		for(int j =0 ; j < n ; j++){
			c[i][j]=a[j];}}
	cout<<"Enter SUM"<<endl;
	cin>>d;
	int sum=0;
	for(int i = 0 ; i <n ; i++){
		sum+=a[i];}
	if(sum<d){
		cout<<"Solution Doesnt Exists"<<endl;
		return 0;}
	else if(sum==d){
		cout<<"Solution Found"<<endl;
		for(int i = 0 ; i < n ;i++){
			cout<<a[i]<<"\t";}cout<<endl;}
	int count=0;
	int i=0;
	
	for(int i = 0 ; i < n ; i++){
		for(int j = i+1; j < n; j++){
			b[count++]=c[i][i]+c[i][j];
			}}
	int flex=0;
	for(int i = 0 ;i < n ; i++){
		int temp=a[i];
		a[i]=0;
		for(int j = 0 ; j < n ; j++){
			if(a[j]!=0){
				flex+=a[j];}}
		b[count++]=flex;
		flex=0;
		a[i]=temp;}
	b[count]=sum;

	for(int i = 0 ; i <=x; i++){
		cout<<b[i]<<"\t";}cout<<endl;
	return 0;}
		


			
