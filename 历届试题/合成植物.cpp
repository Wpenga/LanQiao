#include<iostream>
#include<vector>
#include<set>
#include <queue>
#include<algorithm>
using namespace std;

typedef long long ll;
const int maxn=1005;
int unioned=0,m,n,k;
//种植园
vector<int>  G[maxn*maxn];
bool inq[maxn*maxn]={false};

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    inq[u]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();i++) //确保了u能到达v
        {
            int v=G[u][i];
            if(inq[v]==false) //只需要判断有没有入队
            {
                q.push(v);
                inq[v]=true;
            }
        }
    }


}



void BFSTrave()
{
    for(int u=1;u<=m*n;u++)
    {
        // for(int i=1;i<=m*n;i++)
        // {
        //     cout<<inq[i];
        // }
        // cout<<endl;

        if(inq[u]==false){
            unioned++;
            BFS(u);

        // for(int i=1;i<=m*n;i++)
        // {
        //     cout<<inq[i];
        // }
        //break;
            
        }
    }
}


int main ()
{   
    cin>>m>>n>>k;

    while (k--)
    {
        int a,b;
        cin>>a>>b;
        //初始化图
        G[a].push_back(b),G[b].push_back(a);
    }

    //广度优先遍历访问
    BFSTrave();

    cout<<unioned<<endl;
    
    return 0;
}



