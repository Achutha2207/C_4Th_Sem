#include<iostream>
#include<stdio.h>

using namespace std;

//functions -> find , union


typedef struct edge{
	int u , v , cost;}edge;





int find(int v , int parent[10]){
	while(v!=parent[v]) parent[v]=v;
	return v;}

void union(int i , int j , int parent[10]){
	parent[j]=i;}


void kruskals(int m , int n , edge e[] ){
	int k=0,sum=0,count=0;
	int parent[10];
	int t[20][2];
	edge temp;

	for(int i = 0 ; i <m-1 ; i++){
		for(int j = 0 ; j <m-1-i ; j++){
			if(e[j].cost>e[j+1].cost){
				temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;}}}

	for(int i = 0 ; i < n ; i++){
		parent[i]=i;}


	for(int i = 0 ; i < m && count != n-1 ; i++){
		int u = e[i].u;
		int v = e[i].v;
		
		int root_u = find(u,parent);
		int root_v = find(v,parent);

		if(root_u!=root_v){
			t[k][0]=u;
			t[k][1]=v;
			k++;
			count++;
			sum+=e[i].cost;
			union(root_u , root_v , parent);}}
	if(count==n-1){
		cout<<"Exists"<<endl;
		for(int i=0 ; i < n ; i++){
			printf("%d %d \t ", t[i][0] , t[i][1]);}printf("\n");
			cout<<"Cost"<<sum<<endl;}
	else{
		cout<<"NO"<<endl;}}


int main(){
	edge e[20] ;
	int parent[10] , m , n ;
	cout<<"Enter Number Of Edges And Vertices "<<endl;
	cin>>m>>n;
	cout<<"Enter The u v cost "<<endl;

	for(int i = 0 ; i < m; i++){
		cin>>e[i].u;
		cin>>e[i].v;
		cin>>e[i].cost;}
	kruskals(m , n , e);
	return 0;}

