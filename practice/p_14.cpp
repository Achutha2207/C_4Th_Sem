#include<iostream>
using namespace std;


void subset(int a[] , int b[] , int target , int n , int cs  , int index){
	if(cs==target){
		for(int i = 0 ;i < n ; i++){
			if(b[i]==1){
				cout<<a[i]<<"\t";}}cout<<endl;
		return;
	}
	if(index>=n||cs>target){return;}

	b[index]=1;
	subset(a,b,target,n,cs+a[index],index+1);

	b[index]=0;
	subset(a,b,target,n,cs,index+1);}

int main(){
	int n,target;
	cout<<"Enter The Number Of Elements :";
	cin>>n;

	int a[n];

	int b[n*n*n];

	cout<<"Enter The Elements :";
	for(int i = 0;i < n  ; i++){
		cin>>a[i];}
	cout<<"Enter The Target Element :";
	cin>>target;

	cout<<"The Subsets Are "<<endl;
	subset(a,b,target,n,0,0);
	return 0;}
