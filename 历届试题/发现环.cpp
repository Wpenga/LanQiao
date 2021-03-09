#include <iostream>
#include <vector>
#include<set>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxv=100005;

int maxn=-0x3f3f3f3f,now;
set<int> circle;
vector<int> G[maxv];
bool ans[maxv],flag=false;


void BFS(int pre,int u)
{
    if(flag==true) return;
    for(vector<int>::iterator it=G[u].begin();it!=G[u].end();it++)
    {
        if(*it!=pre)
        {
            if(ans[*it])
            {
                for(int i=1;i<=maxn;i++)
                    if(ans[i]) cout<<i<<' ';
                cout<<endl;
                flag=true;
                return;
            }

            else
                ans[*it]=true,BFS(u,*it),ans[*it]=false;
        }
    }
}


void BFSTrave()
{
    for(int i=1;i<=maxn;i++)
    {
        BFS(i,i);
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

    BFSTrave();


    return 0;
}
