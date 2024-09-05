#include<iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int **a,n,*visited;


void dfs(int start , int buffer){
	visited[start]=1;
	//execute from 2nd iteration
	printf("%d----->>>>%d\n",buffer,start);

	for(int i = 0 ; i < n ; i++){
		if(a[start][i]==1&&!visited[i]){
			visited[i]=1;
			dfs(i,start);}}}









int main(){
	cout<<"Enter Number Of Vertices"<<endl;
	cin>>n;

	a=(int **)malloc(n*sizeof(int *));
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

	dfs(start,-1);

	return 0;}
	
	
