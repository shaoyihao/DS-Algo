// https://www.luogu.com.cn/problem/P1996
// 解法：STL list  （并非循环链表）
#include <iostream>
#include <list>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    list<int> nodeList;
    for (int i = 1; i <= n; i ++) nodeList.push_back(i);

    list<int>::iterator t = nodeList.begin();
    while (nodeList.size() > 1)
    {
        for (int i = 1; i < m; i ++)
        {
            t ++;
            if (t == nodeList.end()) t = nodeList.begin();
        }
        cout << *t << ' ';

        list<int>::iterator tmp = t; //记录当前结点（将被删除）
        t = (++ t == nodeList.end()) ? nodeList.begin() : t; //指向下一个位置
        nodeList.erase(tmp);
    }
    cout << *t;

    return 0;
}