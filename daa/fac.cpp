#include<iostream>
#include<stdio.h>
using namespace std;

int fib(int n ){
	if(n==0){
		return 1;}
	else{
		return fib(n-1)*n;}}

int main(){
	int t;
	cin>>t;
	int x = fib(t);

	cout<<x<<endl;
	return 0;}

