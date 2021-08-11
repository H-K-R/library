/**
	1D array er H size er sub-array er maximum
	ber kora. 
	pre-calculation O(n);
	query O(1)
*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAX 1000006

ll arr[MAX],A[MAX],B[MAX];

void pre_calculation(int n, int h)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(i%h==0)
			B[i]=arr[i];
		else
			B[i]=max(B[i-1], arr[i]);
	}

	A[n-1]=arr[n-1];
	for(i=n-2; i>=0; i--)
	{
		if(i%h==h-1)
			A[i]=arr[i];
		else
			A[i]=max(A[i+1], arr[i]);
	}
}
ll maxInRange(int l, int r)
{
	//Must be r-l+1=h
	return max(A[l], B[r]);
}
int main()
{
	int q,n,h,l,r;
	cin>>n>>h;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	pre_calculation(n,h);
	cin>>q;
	while(q--)
	{
		cin>>l>>r;
		cout<<maxInRange(l,r)<<endl;
	}


}

/*
10 4
5 3 6 1 5 7 2 8 15 10
5
0 3
6 9
5 8
4 7
8 9
*/
