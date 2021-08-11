#include<bits/stdc++.h>
using namespace std;

#define MAX 20

int queen[MAX]; //queen[i]= column number of queen at i"th row

int column[MAX],dia1[2*MAX],dia2[2*MAX];

void print(int n)
{
	cout<<"(row,column) = ";
	for(int i=1; i<=n; ++i)
		cout<<"("<<i<<","<<queen[i]<<") ";
	cout<<"\n";
}
void check(int at, int n)
{
	if(at==n+1)
	{
		print(n);
		return;
	}
	for(int i=1; i<=n; i++)
	{
		if(column[i] || dia1[i+at] || dia2[n+i-at])
			continue;
		queen[at]=i;
		column[i]=dia1[i+at]=dia2[n+i-at]=1;
		check(at+1, n);
		column[i]=dia1[i+at]=dia2[n+i-at]=0;
	}
}

void Nqueen(int n)
{
	check(1, n);
}

int main()
{
	int n;
	cin>>n;
	Nqueen(n);
    return 0;
}
