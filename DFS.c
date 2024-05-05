#include<stdio.h>
#include<time.h>

int n , a[50][50] , i , j , count=0 , reach[50],pos[50];

void read_matrix(){
	printf("Enter The Adjecent Matrix\n");

	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i!=j){
				printf("(%d %d):\n",i,j);
				scanf("%d",&a[i][j]);
			}
		}
	}
}

int adjecent(int i){
	for(j=pos[i]+1;j<=n;j++){
		if(a[i][j]==1){
			pos[i]=j;
			return j;
		}
	}
	pos[i]=n+1;
	return 0;
}

int checkreach(int u ){
	for(i=1;i<=count;i++){
		if(reach[i]==u){
			return 1;
		}
	}
	return 0;
}

void dfs(int v){
	int u ; 
	reach[++count]=v;
	u=adjecent(v);
	while(u){
		if(checkreach(u)==0)dfs(u);
		u=adjecent(v);
	}
}

int main(){

	int v;
	double clk;
	clock_t Start , End;
	printf("DFS\n");

	printf("Enter The Number Of Land To Be Surved\n");
	scanf("%d",&n);

	for( i = 1 ; i <= n ; i++){
		pos[i]=0;
	}
	read_matrix();

	printf("Enter The Starting Land Number\n");
	scanf("%d",&v);

	Start = clock();

	dfs(v);

	End=clock();

	clk=(double)(End-Start)/CLOCKS_PER_SEC;

	printf("The Runtime Is %f\n",clk);

	return 0;
}
