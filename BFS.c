#include<stdio.h>
#include<time.h>

void bfs(int a[10][10] , int n , int source){
	int s[10] , q[10] , f=0,r=-1,t,v;

	for(v=0;v<n;v++){
		s[v]=0;}
	q[++r]=source;
	s[source]=1;

	while(f<=r){
		t=q[f++];
			for(v=0;v<n;v++){
				if(a[t][v]==1&&s[v]==0){
					q[++r]=v;
					printf("The BFS Traversal Is %d %d \n " , f , v);
					s[v]=1;}}}}
void main(){
	int a[10][10] , n , i , j , s;

	double clk;

	clock_t Start_time , End_time;

	printf("Enter The Number Of Cities\n");
	scanf("%d",&n);
	
	printf("Enter The Matrix Representation\n");

	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);}}

	printf("Enter The Source City\n");
	scanf("%d",&s);

	Start_time = clock();

	bfs(a,n,s);

	End_time = clock();
	clk = (double)(End_time-Start_time)/CLOCKS_PER_SEC;
	printf("Runtime Is %f\n",clk);}
