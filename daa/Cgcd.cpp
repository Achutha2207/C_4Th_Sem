#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main(){

	int a,b,t;

	cin>>a>>b;

	if(a>b){
		t=b;}
	else{
		t=a;}

	while(1){
	if(a%t==0&&b%t==0){
		cout<<"GCD Is "<<t<<endl;
		exit(1);}
	else{t--;}}

	return 0;}
