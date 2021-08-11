#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;
 
//Define a node class
struct Node{
	int row;
	vector<int>cols;//Save the current solution 
}; 
 
//The function to determine whether it can be placed
bool Place(Node q)
{
	int n=q.row;//last queen
	for(int i=1; i<n; i++)
	{
		if( (abs(n-i)==abs(q.cols[n]-q.cols[i])) || (q.cols[i]==q.cols[n]))
			return false; //same diagonal||same column
	}
	return true;
}
void print(vector<int> v)
{
	cout<<"(row,column) =";
	for(int i=1; i<v.size(); i++)
		cout<<" ("<<i<<","<<v[i]<<")";
	cout<<endl;
}
void nQueen(int n)
{
	queue<Node>Q;//Living node queue
	
	Node Ew;//Current expansion node 
	Ew.row=0; 
	
	//Search subset space tree
	while(1)
	{	
	   //next node ta k'th column a bosabo 
	   for(int k=1;	k<=n; k++)
	   {
			Node q;
	        q.row=Ew.row+1; 
	        q.cols.push_back(0);//avoid 0th index 
	        //copy old data
    	    for(int i=1; i<q.row; i++)
    	    	q.cols.push_back(Ew.cols[i]);

    	    q.cols.push_back(k);//k'th column a rakhbo

			if(Place(q))
    	    	Q.push(q);
    	}
    	if(Q.empty()) break;
		//Take the next extended node, take it out, and assign it to Ew 
		Ew=Q.front();Q.pop();
		
		if(Ew.row==n){//Find the node of the last layer 
		   print(Ew.cols);
		   return;
		} 
	}
	cout<<"Failed to find solution!\n";
}
  
int main()
{
	int N;
	cin>>N;
	nQueen(N);
	
	return 0;
}
