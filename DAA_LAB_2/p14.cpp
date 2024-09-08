#include<iostream>
#include<set>
#include<vector>
int a[10],b[10],n;
int count=0;
int no=0;
int sum1;
using namespace std;

void subset(int target , int ts , int cs , int index){
	no++;
	b[index]=1;

	if(cs+a[index]==target){
		cout<<"The Subsets Of Sum "<<target<<" Are ";

		for(int i = 0 ; i <= index ; i++){
			if(b[i]==1){
				cout<<a[i]<<"\t";}}cout<<endl;}
	// Include
	else if(cs+a[index]+a[index+1]<=target&&index<=n-1){
		subset(target , ts - a[index] , cs+a[index] , index+1);}
	if(cs+ts-a[index]>=target&&index<=n-1){
		b[index]=0;
		subset(target,ts-a[index],cs,index+1);}} 

void subset2(int target , int n){
	int mask=1<<n;
	set<int> unique;
	vector<int> b;
	
	for(int x=0;x <mask;x++){
		 sum1=0;
		for(int i=0 ; i<n ; i++){
			if(x&(1<<i)){
				sum1+=a[i];
				unique.insert(a[i]);}}
		if(sum1==target){
			for(int n : unique){
				cout<<n<<"\t";}cout<<endl;}
		unique.clear();}}








int main(){
	int target , sum=0;

	cout<<"Enter The Number Of Elements :";
	cin>>n;
	cout<<"Enter The Elements :";
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		sum+=a[i];}
	cout<<"Enter The Value Of Target :";
	cin>>target;

	cout<<"The Subsets Of Sum " <<target << " Is "<<endl;
	subset(target,sum,0,0);
	cout<<"BITWISE"<<endl;
	subset2(target,n);
	cout<<"BACKTRACKING "<<no<<endl;
	int zodd=1<<n;
	cout<<"BITWISE " <<zodd<<endl;
	return 0;}

	
