#include <iostream>
#include<vector>
using namespace std;

typedef long long ll;
const int maxn=100005;
int A[maxn],N,K,ans=-0x3f3f3f3f;
vector<int> VS;

//递归n次，就应该跳出了
void DFS(int cnt,int num)
{

    if(++cnt>N) 
    {
        ans= ans>num ? ans:num;
        return;
    }

    for(int i=1;i<=N;i++)
    {
        for(vector<int>::iterator it=VS.begin();it!=VS.end();it++)
        {
            //如果不符合积分差（不能匹配），添加进去，DFS
            if(abs(A[i]-*it)!=K) VS.push_back(A[i]),DFS(cnt,num+1),VS.pop_back();
        }
    }


}



int main()
{

    cin>>N>>K;
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
    }

    DFS(0,0);

    cout<<ans;

    return 0;
}
