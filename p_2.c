#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int **a , n , initial_vertex ,*visited;

void dfs(int initial_vertex , int buffer){
	visited[initial_vertex]=1;

	if(buffer!=-1){
		printf("Node %d ----->>>>> Node %d\n",buffer,initial_vertex);}
	for(int i = 0 ; i < n ; i++){
		if(a[initial_vertex][i]==1&!visited[i]){
			dfs(i,initial_vertex);}}}
void main(){
	printf("Enter The Value Of n\n");
	scanf("%d",&n);
	 a=(int **) malloc(n*sizeof(int *));
	 for(int i = 0 ; i < n ; i++){
		 a[i]=(int *) malloc(n*sizeof(int));}
	visited = (int *) malloc(n*sizeof(int));
	printf("Enter The Adjacency Matrix Values\n");
	for(int i = 0 ; i<n ; i++){
		for(int  j = 0 ; j <  n; j++){
			scanf("%d",&a[i][j]);}}
	printf("Enter The Value Of Initial_Vetex\n");
	scanf("%d",&initial_vertex);
	clock_t s , e;
	double t;
	s=clock();
	dfs(initial_vertex,-1);
	e=clock();
	t=(double)(e-s)/CLOCKS_PER_SEC;
	printf("The Time Require To Compute DFS Is %f s\n",t);}	
	

