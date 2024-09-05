#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int **a,n,*visited,*queue,f=0,r=-1;

void enqueue(int t){
	queue[++r]=t;}

int dequeue(){
	return queue[f++];}

int isempty(){
	return f>r;}

void bfs(int start){
	visited[start]=1;
	enqueue(start);

	while(!isempty()){
		int x = dequeue();

		for(int i = 0 ; i < n ; i++){
			if(a[x][i]==1&&!visited[i]){
				printf("%d------>>>%d\n",x,i);
				visited[i]=1;
				enqueue(i);}}}}

void dfs(int start , int buffer){
	visited[start]=1;

	if(buffer!=-1){
		printf("%d------->>>>%d\n",buffer,start);}
	for(int i =0 ; i < n ; i++){
		if(a[start][i]==1&&!visited[i]){
			visited[i]=1;
			dfs(i,start);}}}


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
	cout<<"BFS"<<endl;
	bfs(start);
	for(int i = 0; i < n ; i++){
		visited[i]=0;}
	int start1;
	cout<<"Enter Starting Vertex Of DFS"<<endl;
	cin>>start1;
	cout<<"DFS"<<endl;
	dfs(start1,-1);

	return 0;}
