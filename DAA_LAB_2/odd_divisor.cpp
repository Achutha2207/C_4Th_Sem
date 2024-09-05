#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int n;
int main(){
int t;
cin>>t;
while(t--){
cin>>n;
int  a[n];
for(int i =3  ; i <=n ; i++){
	a[i]=i;}
for(int i=2; i<=sqrt(n); i++){
	for(int j=2;j<n;j++){
		if(i*j<=n){
			a[i*j]=0;}}}
for(int i=3; i<n;i++){
	if(a[i]!=0){cout<<a[i]<<"\t";}}cout<<endl;
}







		return 0;}
