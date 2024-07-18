#include<stdio.h>
#include<math.h>
#define FALSE 0
#define TRUE 1
#include<iostream>

using namespace std;
int x[20];

int place(int k , int i){
	int j ; 

	for(j=1;j<=k;j++){
		if((x[j]==i)||(abs(x[j]-i)==abs(j-k)))
			return FALSE;}
	return TRUE;
}

int nqueens(int k , int n){
	int i , a;
	for(i=1;i<=n;i++){
		if(place(k,i)) { x[k]=i;
			if(k==n){
				for(a=1;a<=n;a++){
					printf("%d\t",x[a]);}
				printf("\n");}
			else{
				nqueens(k+1,n);}}} return 0;}
int main(){
	int n ;
	cout<<"Enter The Value Of n"<<endl;
	cin>>n;
	if(n<0||n==0||n==2||n==3){
		cout<<"The Solution To "<<n<<" Doesn't Exists "<<endl; exit(1);}
	cout<<"The Solution Of nQueens Problem Is "<<endl;
	nqueens(1,n);
	cout<<x<<endl;
return 0;}
