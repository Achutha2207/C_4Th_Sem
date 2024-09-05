#include<string.h>
#include<iostream>
#include<stdio.h>

using namespace std;
int bfsm(int m , int n,char t[] , char p[]){
	int j;
	for(int i = 0 ; i < n-m ; i++){
		j = 0;

		while(j<m&&p[j]==t[j+i]){
			j++;}
	if(j==m){
		return i;}}
	return -1;}
int main(){
	
	int m ;
	int n ;
	cin>>n>>m;
	char t[n];
	char p[m];

	cin>>t;
	cin>>p;
	int j;
	
	int x=bfsm(m,n,t,p);
	
	if(x==-1){
		cout<<"Not Found"<<endl;}
	else{
		cout<<x<<endl;}

	return 0;}
