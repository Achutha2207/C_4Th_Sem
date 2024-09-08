#include<iostream>
#include<vector>
#include<set>
using namespace std;

void printsubset(const vector<int>& a,int n){
	int mask=1<<n;
	for(int x = 0 ; x < mask ; x++){
		cout<<"{";
		for(int i = 0 ; i < n ; i++){
			if(x&(1<<i)){
				cout<<a[i]<<" ";}}
		cout<<"}"<<endl;}}

void uniquesum(const vector<int>& a , int n){
	set<int> unique;

	int mask=1<<n;

	for(int x = 0 ; x<mask;x++){
		int sum=0;
		for(int i = 0 ; i <n ; i++){
			if(x&(1<<i)){
				sum+=a[i];}}
		unique.insert(sum);}
	for(int num : unique){
		cout<<num<<"\t";}cout<<endl;

}



void sumofsubset(const vector<int>& a , int n, int target){
	cout<<"The Subsets Whose Sum Is Equal To "<<target<<" Is :"<<endl;
	int mask = 1<<n;
	vector<int> b;
	for(int x=0;x<mask;x++){
		int sum=0;
		for(int i = 0 ; i  <n ; i++){
			if(x&(1<<i)){
				b.push_back(a[i]);
				sum+=a[i];}}
		if(sum==target){
			cout<<"{";
		for(int num : b){
			cout<<num<<"\t";}cout<<"}"<<endl;}
		b.clear();}}
		




int main(){
	int n,target;
	cout<<"Enter The Number Of Elements: ";
	cin>>n;
	vector<int> a;
	cout<<"Enter The Elements: ";
	for(int i = 0 ; i < n ; i++){
		int input;
		cin>>input;
		a.push_back(input);}
	cout<<"Enter the Target Sum: ";
	cin>>target;
	printsubset(a,n);
	uniquesum(a,n);
	sumofsubset(a,n,target);
	return 0;}
