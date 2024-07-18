#include<stdio.h>
#include<iostream>
#include<string.h>
#define max 500

using namespace std;

char pattern[30];
char text[31];
int shifttable[max];

int max_pattern , max_text;


void table(){

	//initialize all values to max_text
	
	for(int i = 0 ; i < max ; i++){
		shifttable[i]=max_pattern-1;}

	//initialize the ascii character index to no of positions to be shifted
	
	for(int i = 0 ;i < max_pattern-i ; i++){
		shifttable[pattern[i]]=max_pattern-1-i;}}


int horsepool(){

	//while last index of pattern is greater than max_text
	int text_index = max_pattern-1;
	

	while(text_index < max_text){

		//while all characters are not found 

		int pattern_index = 0 ;  

		while((pattern_index<max_pattern)&&(pattern[max_pattern-1-pattern_index]==text[text_index-pattern_index])){
			//while it is matching in text increase maching characters 
				pattern_index++;}
		if(pattern_index==max_pattern){
			return text_index-max_pattern+1;}

		else{
			text_index+=shifttable[pattern[text_index]];}}
	return -1;}

int main(){
	cout<<"Enter The Text"<<endl;
	cin>>text;
	cout<<"Enter The Pattern "<<endl;
	cin>>pattern;

	max_pattern=strlen(pattern);
	max_text=strlen(text);

	table();

	int x = horsepool();

	if(x>0){
		cout<<"The Given Pattern Found At Index "<<x<<endl;}
	else{
		cout<<"The Pattern Was Not Found In The Text"<<endl;}
	return 0;}
