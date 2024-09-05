#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int **a , *visited , *queue , n ,f=0,r=-1;


void enqueue(int c){
	queue[++r]=c;}

int dequeue(){
	return queue[f++];}

int isempty(){
	return f>r;}


void bfs(int start){
	enqueue(start);
	visited[start]=1;

		while(!isempty()){
			int x=dequeue();

			for(int i = 0 ; i < n ; i++){
				if(a[x][i]==1&&!visited[i]){
					printf("%d------->>>>>%d\n",x,i);
					visited[i]=1;
					enqueue(i);
				}}}}
	










int main(){

	cout<<"Enter Number Of Vertices"<<endl;
	cin>>n;

	a=(int **)malloc(n*sizeof(int *));
	visited=(int *)malloc(n*sizeof(int));
	queue=(int *) malloc(n*sizeof(int));
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

	bfs(start);
	return 0;}
