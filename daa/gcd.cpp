#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
	int m , n , r;

	cin>>m>>n;

	while(n!=0){
		r=m%n;
		m=n;
		n=r;
	}

	cout<<"GCD Is "<<m<<endl;
 return 0;}
