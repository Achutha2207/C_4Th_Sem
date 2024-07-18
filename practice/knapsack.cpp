#include<iostream>
#include<stdio.h>

using namespace std;

//input n , m , 2 arrays
//output 1 array and max value
//n->>no of items
//m->>max capacity 

int max(int a,int b){
	if(a>b){
		return a;}
	else{return b;}}

void knapsack(int n , int m , int weights[10] , int price[10] , int v[20][20]){
	for(int i = 0 ; i <=n ; i++){
		for(int j = 0 ; j <=m ; j++){
			if(i==0||j==0){
				v[i][j]=0;}
			else if(j<weights[i-1]){
				v[i][j]=v[i-1][j];}
			else{
				v[i][j]=max(v[i-1][j],v[i-1][j-weights[i-1]]+price[i-1]);}}}}


int main(){
	int m , n , weights[10] , price[10] , v[20][20];

	cout<<"Enter The Number Of Items"<<endl;
	cin>>n;

	cout<<"Enter Weights Of Items"<<endl;

	for(int i = 0 ; i < n ; i++){
		cin>>weights[i];}

	cout<<"Enter Their Prices"<<endl;

	for(int i = 0 ; i < n ; i++){
		cin>>price[i];}

	cout<<"Enter The Maximum Capacity Of Knapsack"<<endl;
	cin>>m;

	for(int i = 0 ; i<=n;i++){
		for(int j = 0 ; j <=m ; j++){
			v[i][j]=0;}}

	knapsack(n , m , weights , price , v);
	
	cout<<"Final Matrix"<<endl;

	for(int i = 0 ; i<=n ; i++){
		for(int j = 0; j<=m ;j++){
			cout<<v[i][j]<<"\t";}cout<<endl;}
	return 0;}
