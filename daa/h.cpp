#include<stdio.h>
#include<iostream>
#include<string.h>
#define size 500

using namespace std;
int table[size];
char text[100],pattern[100];
void shifttable(char pattern[]){
	int m=strlen(pattern);
	for(int i = 0 ; i<size;i++){
		table[i]=m;}
	for(int i = 0 ; i<m-1 ; i++){
		table[pattern[i]]=m-i-1;}}
	

int horsepool(char text[] , char pattern[]){
	int n=strlen(text);
	int m=strlen(pattern);

	int i=m-1;
	 int k=0;
	while(i<n){//search reaches forward to text
		while(k<=n&&pattern[m-k-1]==text[i-k]){k++;}
		if(k==m){return i+1-m;}
		else{i+=table[text[i]];}}
		return -1;}






int main(){
	//char text[100], pattern[25];
	int result;
	printf("Enter The Text\n");
	scanf("%s",text);
	printf("Enter The Pattern\n");
	scanf("%s",pattern);
	shifttable(pattern);
	result = horsepool(text,pattern);
	cout<<"Found At "<<result<<endl;
	return 0;}
