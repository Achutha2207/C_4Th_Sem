#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int n;

void merge(int a[],int low , int mid , int high){
	int b[n];

	int i=low;
	int j=low;
	int k=mid+1;

	while(i<=mid&&k<=high){
		if(a[i]>=a[k]){
			b[j]=a[k];
			k++;}
		else{
			b[j]=a[i];
			i++;}
		j++;}
	if(i>mid){
		for(int x=i; x<=high; x++){
			b[j]=a[x];
			j++;}}
	else{
		for(int x=i;x<=mid;x++){
			b[j]=a[x];
			j++;}}
	for(int v = low ; v<=high ; v++){
		a[v]=b[v];}}






void mergesort(int a[] , int low , int high){
	if(low<high){
		int mid = (low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);}}








int main(){
	cin>>n;
	int a[n];

	for(int i = 0 ; i < n ; i++){
		cin>>a[i];}

	mergesort(a,0,n-1);
	for(int i = 0 ;i < n ; i++){
	printf("%d\t",a[i]);}cout<<endl;
	return 0;}

