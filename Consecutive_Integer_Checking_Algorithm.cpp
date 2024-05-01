#include<iostream>

using namespace std;

class fun{

	int a , b ,min,max;

	
	public:
	fun(int a , int b){
		this->a=a;
		this->b=b;}


	void hcf(){
	
		if(a<b){
			min=a;
			max=b;

		}
		else{

			max=a;
			min=b;}

		int check=0;
		int t = min;
		while(max%min!=0||t%min!=0){
			min-=1;
			check=1;
		cout<<"HCF Is "<<min<<endl;}
			if(check==0){
		 cout<<"HCF Is "<<min<<endl;}
	}};

int main(){

	int a,b;

	cout<<"Enter The Value Of a\n";
	cin>>a;
	cout<<"Enter The Valuue Of b\n";
	cin>>b;

	fun s(a,b);
	s.hcf();
	return 0;
	

}
	
		

		

