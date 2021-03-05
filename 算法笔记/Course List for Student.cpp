#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>

using namespace std;
int main()
{
    int n, k, course, nk;
    string name;
    map<string, set<int>> list;
    cin >> n >> k;
    while (k--)
    {
        cin >> course >> nk;
        while (nk--)
        {
            //输入学生姓名，并添加课程名到所应字典中
            cin >> name;
            list[name].insert(course);
        }
        for (auto &x : list)
        {
            std::cout << x.first << ": " << x.second << '\n';
        }

        return 0;
    }

}
    // 11 5
    // 4 7
    // BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
    // 1 4
    // ANN0 BOB5 JAY9 LOR6
    // 2 7
    // ANN0 BOB5 FRA8 JAY9 JOE4 KAT3 LOR6
    // 3 1
    // BOB5
    // 5 9
    // AMY7 ANN0 BOB5 DON2 FRA8 JAY9 KAT3 LOR6 ZOE1
    // ZOE1 ANN0 BOB5 JOE4 JAY9 FRA8 DON2 AMY7 KAT3 LOR6 NON9