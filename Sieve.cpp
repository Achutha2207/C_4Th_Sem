#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main(){

	int *a,n;

	cout<<"Enter The Number\n"<<endl;
	cin>>n;

	a=new int[n];

	for(int i = 2 ; i < n ; i++){
		*(a+i)=i;}

	
	for(int i = 0 ; i < n ; i++){
	for(int j = 2;j<sqrt(n);j++){
		if(*(a+i)%j==0){
			*(a+i)=0;
			break;
			}}}
		
	cout<<"Prime Numbers From 2 To "<<n<<" Are"<<endl;
	for(int i = 0 ; i < n ; i++){
		if(*(a+i)!=0){
	cout<<*(a+i)<<"\t";}}
	cout<<endl;}
	