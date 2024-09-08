#include<iostream>
#include<vector>
#include<set>

using namespace std;

int a[10] , b[10] , n , target;
int count=0;
int count1=0;



void subset(int cs , int index , int ts){
	b[index]=1;

	if(cs+a[index]==target){
		cout<<"Sum Of Subset "<<++count<<" Is :"<<endl;
		cout<<"{";
		for(int i = 0 ;i <= index ; i ++){
			if(b[i]==1){
				cout<<a[i]<<" ";}}cout<<"}"<<endl;}
	else if(cs+a[index]+a[index+1]<=target&&index<=n-1){
		subset(cs+a[index],index+1,ts-a[index]);}
	if(cs+ts-a[index]>=target&&index<n-1){
		b[index]=0;
		subset(cs,index+1,ts-a[index]);}}

void subset2(){
	int mask = 1<<n;	


	for(int x = 0 ; x<mask ; x++){
		int sum1=0;
		set<int> unique;
		for(int i=0 ; i< n; i++){
			if(x&(1<<i)){
				sum1+=a[i];
				unique.insert(a[i]);}}
		if(sum1==target){
			cout<<"Sum Of Subset "<<++count1<<" Is :"<<endl;
			cout<<"{";
			for(int num : unique ){
				cout<<num<<" ";}cout<<"}"<<endl;
		}
	unique.clear();}}














int main(){
	cout<<"Enter Number Of Elements: ";
	cin>>n;
	int ts=0;
	cout<<"Enter The Elements :";
	for(int i=0;i<n;i++){
		cin>>a[i];
		ts+=a[i];}
	cout<<"Enter The Target : ";
	cin>>target;
	if(count==0){
		cout<<"No Subsets Found"<<endl;
		return 0;}

	cout<<"BackTracking"<<endl;
	subset(0,0,ts);
	cout<<"Iterative "<<endl;
	subset2();
	return 0;}
