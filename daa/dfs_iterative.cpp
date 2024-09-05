#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

int **a,n,*visited;
int *stack,top=-1;

int pop(){
	return stack[top--];}

void push(int c){
	stack[++top]=c;}

int empty(){
	return top==-1;}
void dfs(int start){
	int count=0;
	visited[start]=count;
	push(start);

	while(!empty()){
		for(int i = 1 ; i < n ; i++){
			if(a[start][i]==1&&!visited[i]){
				push(i);
				printf("%d---->>%d\n",start,i);
				visited[i]=count++;
				start=i;}}
			pop();
	}}











int main(){
	cout<<"Enter Number Of Vertices"<<endl;
	cin>>n;

	a=(int **)malloc(n*sizeof(int *));
	stack=(int *)malloc(n*sizeof(int));
	visited=(int *)malloc(n*sizeof(int));
	for(int i = 0 ; i < n ; i++){
	a[i]=(int *)malloc(n*sizeof(int));}

	cout<<"Enter Adjacency Matrix"<<endl;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j<n ; j++){
			cin>>a[i][j];}}

	for(int i = 0 ; i < n ; i++){
		visited[i]=0;}

	cout<<"Enter Starting Vertex"<<endl;
	int start;
	cin>>start;

	dfs(start);

	return 0;}
	
	
