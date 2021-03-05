#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const int maxp = 100005;
int score[maxp], N, K, max_score = -0x3f3f3f3f, temp, ans = 0, val[maxp], most_p[maxp];
vector<int> VS;

void dp()
{
    //K==0不能分组需要单独列出
    if (K == 0)
    {
        for (int i = 0; i <= max_score; i++)
            if (score[i])
                ans++;
    }


    //从0-(k-1)开始进行分组（是score%K的一系列值）。没必要用else，因为K=0进入不了分组循环
    for (int i = 0; i < K; i++)
    {
        int cnt = 0;
        // j,j+K,...,j+nK
        for (int j = i; j <= max_score; j += K)
            val[cnt++] = score[j];

        //边界，dp出口
        most_p[0] = val[0]; //前1个分数，没得选嘛
        most_p[1] = max(val[0], val[1]);  //前两个分数，选人数多的啦
        //进行dp，对于前j个分数来说，考虑第j个分数选不选：
        //1.选，那就是most_p[j - 2] + val[j]，因为第j-1个分数不能选  
        //2.不选，那就和most_p[j - 1]一样
        //所以，只需要取两种情况中最多的人数就可以啦
        for (int j = 2; j < cnt; j++)
            most_p[j] = max(most_p[j - 1], most_p[j - 2] + val[j]);

        ans += most_p[--cnt];
    }
}

int main()
{
    cin >> N >> K;
    while (N--)
    {
        cin >> temp;
        score[temp]++;
        max_score = max_score > temp ? max_score : temp;
    }

    dp();
    cout << ans;
    return 0;
}
