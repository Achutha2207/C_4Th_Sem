#include<iostream>
#include<vector>
#include<stack>
using namespace std;



void findsubset(vector<int>&array , int target){

	//Structure of stacks
	
	struct State{
		int index;
		int currentsum;
		vector<int> subset;};
	
	stack<State> stk;
	stk.push({0,0,{}});
	while(!stk.empty()){
		State current_state = stk.top();
		stk.pop();

		//3 conditions
		//1--> if found
		//2--> if not found and elemmnt of x index should be included
		//3--> if not found and element of x index must be excluded from stack;

		if(current_state.index>=array.size()||current_state.currentsum>target){continue;}

		//1
		if(current_state.currentsum==target){
			cout<<"{";
			for(int num : current_state.subset){
				cout<<num<<" ";}cout<<"}"<<endl;}
	
		//2
		current_state.subset.push_back(array[current_state.index]);
		stk.push({current_state.index+1,current_state.currentsum+array[current_state.index],current_state.subset});

		//3
		current_state.subset.pop_back();
		stk.push({current_state.index+1,current_state.currentsum,current_state.subset});
		}}













int main(){
	int n;
	cout<<"Enter Number Of Elements"<<endl;
	cin>>n;
	cout<<"Enter Elements"<<endl;
	vector<int> array;
	int input;
	for(int i =0 ; i < n ; i++){
		cin>>input;
		array.push_back(input);}
	int target;
	cout<<"Enter The Final Sum"<<endl;
	cin>>target;
	findsubset(array,target);
	return 0;}
