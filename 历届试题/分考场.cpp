#include<iostream>
#include<vector>
#include<set>
#include <queue>
#include<algorithm>
using namespace std;
typedef long long ll;


int n,m,ans=0x3f3f3f3f;

//不认识，没访问(主要全部初始化为true要用for循环，比较麻烦)
bool G[100][100]={false},inq[100];

//注意！不能这样初始化，这样只会第一个为true值！！
//inq[100]={true};

//初始化各个考场
vector<int> exam[105];
// int exam[105][105];

void BFS(int cnt,int num)
{
    
    if(cnt>=ans) return;

    //递归出口：有所属的人等于总人数
    if(num>n) 
    {
        ans= min(ans,cnt);
        return;
    }
    
    for(int r=1;r<=cnt;r++)
    {
        bool flag=0;
        //罗列cnt号考场内所有选手
        for(vector<int>::iterator it= exam[r].begin();it!=exam[r].end();it++)
        {
            //如果认识考场里的人，跳出，开始判断下一个人
            if(G[num][*it]==true )  {flag=1;break;}
        }
        //所有人都不认识，添加此人于该考场中，设置其有归属了，有归属的人数+1
        //if(flag==0) exam[r].insert(exam[r].begin(),num),BFS(cnt,num+1),exam[r].erase(exam[r].begin());
        if(flag==0) exam[r].push_back(num),BFS(cnt,num+1),exam[r].pop_back();
    }

    
    exam[cnt+1].push_back(num);
    BFS(cnt+1,num+1);
    //exam[cnt+1].erase(exam[cnt+1].begin());
    exam[cnt+1].pop_back();



    // int j, k;
	// for (j = 1; j <= cnt; j++) {//枚举考场
	// 	k = 0;
	// 	while (exam[j][k] && !G[num][exam[j][k]])k++;//找到一个空位 并且与该考场人无关系 
	// 	if (exam[j][k] == 0)exam[j][k] = num, BFS(cnt,num + 1 ), exam[j][k] = 0;//满足条件 进行下一考生 
	// }                                    //回溯 
	// exam[j][0] = num;
	// BFS( cnt + 1,num + 1);// 如果所有房间都不满足条件 增加房间 
	// exam[j][0] = 0;//回溯 

}


int main ()
{   


    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        //认识了
        G[x][y]=G[y][x]=true;
    }


    //第一个考场开始，有归属的人为1
    BFS(1,1);
    cout<<ans<<endl;


    return 0;
}



