#include<stdio.h>
#include<math.h>
#include<stdlib.h>


int **matrix , *visited , num_vertices , initial_node ;




void dfs(int initial_node , int adjecent){
visited[initial_node]=1;
if(adjecent!=-1){
	printf("Node %d ----->>>>> Node %d\n",adjecent,initial_node);}

for(int i = 0 ; i < num_vertices ; i++){
	if(matrix[initial_node][i]&&!visited[i]){
		dfs(i,initial_node);}}
}


void main(){
	printf("Enter The Number Of Vertices In The Graph\n");
	scanf("%d",&num_vertices);

	//DMA
	
	visited = (int *) malloc( num_vertices*sizeof(int));

	matrix=(int **) malloc(num_vertices*sizeof(int *));

	for(int i = 0 ; i < num_vertices;i++){
		matrix[i]=(int *) malloc(num_vertices*sizeof(int));}


	printf("Enter The Values Of Adjecency Matrix\n");
	
	for(int i   = 0 ; i < num_vertices;i++){
		for(int j = 0 ; j < num_vertices;j++){
			scanf("%d",&matrix[i][j]);}}


	printf("Enter The Initial Node\n");
	scanf("%d",&initial_node);

	dfs(initial_node,-1);

	printf("Visited Array\n");

	for(int i = 0 ; i < num_vertices ; i++){
		printf("%d\t",visited[i]);}printf("\n");

}
