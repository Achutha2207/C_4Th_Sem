#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int **a , *visited , *queue ,initial_vertex, n , f=0,r=-1 , current_vertex;

void enqueue(int x){
	queue[++r]=x;}
int dequeue(){
	return queue[f++];}
int isempty(){
	return f>r;}

void bfs(int initial_vertex){
	visited[initial_vertex]=1;
	enqueue(initial_vertex);

	while(!isempty()){
	current_vertex=dequeue();
	for(int i = 0 ; i <  n ; i++){
		if(a[current_vertex][i]==1&&visited[i]==0){
		printf("From Node %d --->>>>> %d\n",current_vertex,i);
		visited[i]=1;
		enqueue(i);}}}}
	
void main (){
	
	printf("Enter The Value Of n\n");
	scanf("%d",&n);

	a=(int **) malloc(n*sizeof(int *));
	for(int i = 0 ; i < n ; i++){
		a[i]=(int *) malloc(n*sizeof(int));}
	
	visited=(int *)malloc(n*sizeof(int));
	
	queue=(int *)malloc(n*sizeof(int));

	printf("Enter The Adjacency Matrix\n");
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			scanf("%d",&a[i][j]);}}
	printf("Enter The Initial Vertex\n");
	scanf("%d",&initial_vertex);
	clock_t s,e;
	double t;

	s=clock();

	bfs(initial_vertex);

	e=clock();

	t=(double)(e-s)/CLOCKS_PER_SEC;

	printf("The Time Required To Compute BFS Algorithm Is %f s\n",t);}


