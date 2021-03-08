#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
using namespace std;
typedef long long ll;

int maxn=-0x3f3f3f3f,now;
set<int> circle;
vector<int> G[10005];
bool track[100005],ans[100005];


void BFS(int v)
{

    for(vector<int>::iterator it=G[v].begin();it!=G[v].end();it++)
    {
        if(track[*it]) {ans[*it]=true;return;}
        ans[*it]=track[*it]=true,BFS(*it),ans[*it]=track[*it]=false;
    }
}




void BFSTrave()
{
    for(int v=1;v<=maxn;v++)
    {
        if(ans[v]==false)
        fill(track, track+100005, false);
        track[v]=true;
        BFS(v);

    }
}






int main()
{
    int N;
    cin>>N;
    while(N--)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b),G[b].push_back(a);
        maxn=max(max(a,b),maxn);
    }





    return 0;
}
