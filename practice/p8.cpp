#include<stdio.h>
#include<iostream>
#include<string.h>
#define max 500
using namespace std;


int shifttable[max];

char pattern[20];
char text[21];





//horsepools algo
//input : text , pattern
//output : index of matching pattern or -1


//functions -> shiftable , horsepool


void table(int max_pattern){
	//initialise to max length of pattern
	
	for(int i = 0 ; i < max ; i++){
		shifttable[i]=max_pattern;}

	for(int i = 0 ; i < max_pattern-i ; i++){
		shifttable[pattern[i]]=max_pattern-1-i;}}

int horsepool(int max_text , int max_pattern){
	    int	i=max_pattern-1;

	//when to break? when i > max_text
	
	while(i<max_text){

		//find the matching index 
		//      ddancoidnckldsdocn  --> text
		//	dncwcmwdij  ---> pattern

		int k = 0 ; // iterates through the pattern

		while((k<max_pattern)&&pattern[max_pattern-1-k]==text[i-k]){k++;}
			
			if(k==max_pattern){ return i-max_pattern+1;}
			else{
				i+=shifttable[text[i]];}
	} return -1;}


int main(){
	printf("Enter The Text\n");
	scanf("%s",&text);
	printf("Enter The Pattern\n");
	scanf("%s",&pattern);
	int max_text=strlen(text); 
	int max_pattern=strlen(pattern);
	table(max_pattern);
	int x = horsepool(max_text,max_pattern);
	if(x>0){
		cout<<"The Given Pattern Is Matched At Index "<<x<<endl;}
	else{
		cout<<"The Pattern Wasn't Found In The Text "<<endl;}

	return 0;}


