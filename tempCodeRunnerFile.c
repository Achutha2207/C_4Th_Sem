#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int **graph,*visited,*queue,num_vertex,front=0,rear=-1;

void enqueue(int vertex){
	queue[++rear]=vertex;}

int dequeue(){
	return queue[front++];}

int isempty(){
	return front>rear;}

void bfs(int start_vertex){
	visited[start_vertex]=1;
	enqueue(start_vertex);

	while(!isempty()){

	

	for(int i = 0 ; i < num_vertex;i++){
		if(graph[start_vertex][i]&&!visited[start_vertex]){
			printf("Node %d ---->>> Node %d\n",start_vertex,i);
			visited[i]=1;
			printf("Visited Array %d\n",visited[i]);
			dequeue();
		}}}
		for(int i = 0 ; i < num_vertex;i++){
		printf("Visited Array %d\t",visited[i]);
		}printf("\n");
		}

void main(){

	printf("Enter The Number Of Nodes\n");
	scanf("%d",&num_vertex);

	clock_t start , end;
	double time;

	//DMA for queue , visited , graph

	graph=(int **) malloc(num_vertex*sizeof( int *));
	queue=(int*)malloc(num_vertex*sizeof(int));
	visited=(int*)malloc(num_vertex*sizeof(int));

	for(int i = 0 ; i < num_vertex;i++){
		graph[i]=(int*)malloc(num_vertex*sizeof(int));}

	for(int i = 0 ; i< num_vertex;i++){
		visited[i]=0;}

		printf("Enter The Ajecency Matrix\n");

	for(int i = 0 ; i<num_vertex;i++){
		for(int j =0 ; j < num_vertex;j++){
			scanf("%d",&graph[i][j]);}}




	int start_vertex;

	printf("Enter The Starting NODE\n");
	scanf("%d",&start_vertex);


	

	start=clock();

	bfs(start_vertex);

	end=clock();

	time=((double)(end-start))/CLOCKS_PER_SEC;

	printf("The Time Required Is %.f\n",time*(10e5));
	
	free(queue);
	free(visited);

	for(int i = 0 ; i<num_vertex;i++){
		free(graph[i]);}
	
	free(graph);}
	
	
	
	
	