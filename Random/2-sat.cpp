//https://cp-algorithms.com/graph/2SAT.html

#include<bits/stdc++.h>
#define SZ 100
#define pb push_back

using namespace std;

bool vis[SZ],assignment[SZ];
vector<int>adj[SZ],adjR[SZ],order;
int id[2*SZ];

void DFS(int n)
{
    vis[n]=1;
    for(auto x : adj[n])
    {
        if(vis[x]) continue;
        DFS(x);
    }
    order.push_back(n);
}

void DFS2(int n, int cl)
{
    id[n]=cl;
    for(auto x: adjR[n])
    {
        if(id[x]==-1)
            DFS2(x, cl);
    }
}

bool solve_2SAT(int n,int m)
{
    memset(vis,0,sizeof vis);
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
            DFS(i);
    }
    memset(id, -1, sizeof id);
    reverse(order.begin(),order.end());
    int c=0;
    for(auto x : order)
    {
        if(id[x]==-1)
        {
            DFS2(x,c++);
        }
    }
    memset(assignment,0,sizeof assignment);
    for(int i=1; i<=m; i++)
    {
        if(id[i]==id[i+m])
            return 0;
        assignment[i]=id[i]>id[i+m];
    }
    return 1;
}

int main()
{
    int n,m,x,y,i;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>x>>y;
        adj[x].pb(y);
        adjR[y].pb(x);
    }
   
    return 0;
}
/**
13 14
0 1
0 4
8 10
1 3
7 9
4 3
8 7
11 2
10 12
0 5
3 6
5 6
7 12
3 5
*/

