#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 500
int table[SIZE];

void shifttable(char p[]){
	int i, m ;

	m=strlen(p);

	for(i = 0 ; i < SIZE ; i++)
		table[i]=m;

	for(int j=0;j<m-1;j++)
		table[p[j]]=m-1-j;
}


int horsepool(char text[100] ,char pattern[25]){
int m , n , k , i ;
m=strlen(pattern);
n=strlen(text);
i=m-1;
while(i<n){
	k=0;
	while(k<m&&(pattern[m-1-k]==text[i-k])){k++;}
	if(k==m){
		return i-m+1;}
	else{
		i=i+table[text[i]];
	}}
	return -1;}
int main(){
	char text[100], pattern[25];
	int result;
	printf("Enter The Text\n");
	scanf("%s",text);
	printf("Enter The Pattern\n");
	scanf("%s",pattern);
	shifttable(pattern);
	result = horsepool(text,pattern);
	if(result==-1){
		printf("The Pattern Not Found In The Text\n");
		return ;}
	else{
		printf("The Pattern Was Found At %d\n",result+1);}
return 0;}
