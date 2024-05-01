#include<iostream>
using namespace std;

class fun{
	int a;
	int b;
	int r;
	public:
	fun(int a, int b ){
		this->a=a;
		this->b=b;}
	

	void compute(){

	while(b!=0){
		r=a%b;
		 	
		a=b;

		b=r;}}
	

	void lisa(int x , int y){
	int l=(x*y)/a;
	cout<<"The GCD Is "<<a<<std::endl;
	cout<<"Lcm Of "<<x<<" And "<<y<< " Is "<<l<<endl;
	}
};

int main(){
	int q,w;
	
	cout<<"Enter The Value Of q\n";
	cin>>q;

	cout<<"Enter The Value Of w\n";
	cin>>w;
	
	int b1=q;
	int b2=w;

        fun a(q,w);
	a.compute();

	a.lisa(b1,b2);
	return 0;
}



		
