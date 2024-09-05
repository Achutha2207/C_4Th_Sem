#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main(){
	int t;

	cin>>t;

	int count=1;

	while(t>1){
		count++;
		t=t/2;}

	cout<<count<<endl;
	return 0;}
