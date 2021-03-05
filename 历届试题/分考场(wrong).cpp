#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m, ans = 0x3f3f3f3f;

//不认识，没访问(主要全部初始化为true要用for循环，比较麻烦)
bool G[100][100] = {false}, inq[100];

//注意！不能这样初始化，这样只会第一个为true值！！
//inq[100]={true};

//初始化各个考场
vector<int> exam[105];

void BFS(int cnt, int num)
{
    if (cnt > ans)
        return;

    //递归出口：有所属的人等于总人数
    if (num == n)
    {
        ans = ans > --cnt ? cnt : ans;
        return;
    }
    for (int r = 1; r < cnt)
        for (int u = 1; u <= n; u++)
        {
            if (inq[u] == true)
                continue;
            bool flag = 0;
            //罗列cnt号考场内所有选手，并添加不认识的人
            for (vector<int>::iterator it = exam[cnt].begin(); it != exam[cnt].end(); it++)
            {
                //如果认识考场里的人，跳出，开始判断下一个人
                if (G[u][*it] == true)
                {
                    flag = 1;
                    break;
                }
            }
            //所有人都不认识，添加此人于该考场中，设置其有归属了，有归属的人数+1
            if (flag == 0)
                exam[cnt].push_back(u), inq[u] = true, num++;
        }

    //判断完一个考场，进行下一考场的判断
    BFS(++cnt, num);
}

int main()
{

    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        //认识了
        G[x][y] = G[y][x] = true;
    }

    inq[1] = true, exam[1].push_back(1);
    //第一个考场开始，有归属的人为1
    BFS(1, 1);
    cout < < < < endl;

    return 0;
}
