/**
	We will iterate over the array and
	when we are at the ith element we 
	will answer all queries (L, R) with
	R == i. To do this efficiently we 
	will keep a DSU using the first i 
	elements with the following structure:
	the parent of an element is the next smaller/greater
	element to the right of it. Then 
	using this structure the answer to 
	a query will be the a[find_set(L)], 
	the smallest number to the right of L.
	O((n + q)·a(n)), a() stands for 
	Akerman inverse function used in DSU.

	for maximum: a[st.top()] <= a[i]
	for minimum: a[st.top()] >= a[i]
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 100005

int par[MAX],ans[MAX],arr[MAX],L[MAX];
vector<int> qu[MAX];

int find_par(int v)
{
	return par[v]==-1? v : par[v]=find_par(par[v]);
}

int main()
{
	memset(par, -1, sizeof par);

	int i,n,q,r;
	cin>>n;
	for(i=0; i<n; i++) cin>>arr[i];
	cin>>q;
	for(i=0; i<q; i++)
	{
		cin>>L[i]>>r;
		L[i]--;
		r--;
		qu[r].push_back(i);
	}

	stack<int> st;
	for(i=0; i<n; i++)
	{
		while(st.size() && arr[st.top()]<=arr[i])
		{
			par[st.top()]=i;
			st.pop();
		}
		st.push(i);
		for(auto ii : qu[i])
			ans[ii]=arr[find_par(L[ii])];
	}
	for(i=0; i<q; i++)
		cout<<ans[i]<<" ";
}
