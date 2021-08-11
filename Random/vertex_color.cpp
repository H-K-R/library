#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
using namespace std;

#define MAX 100

vector<int> adj[MAX];
int color[MAX];

bool isPossible(int u, int c)
{
	for(auto v : adj[u])
	{
		if(color[v]==c)
			return 0;
	}
	return 1;
}
void print(int n)
{
	cout<<"(node,color) \n";
	for(int i=1; i<=n; i++)
		cout<<"("<<i<<","<<color[i]<<")\n";
}
void vertexColor(int n)
{
	int cr=1;//cromatic color
	for(int u=1; u<=n; u++)
	{
		for(int c=1; c<=cr; c++)
		{
			if(isPossible(u,c))
			{
				color[u]=c;
				break;
			}
		}
		if(!color[u])
			color[u]=++cr;
	}
	cout<<"Cromattic Number= "<<cr<<endl;
	print(n);
}
  
int main()
{
	int n,m,u,v;
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vertexColor(n);
	return 0;
}
