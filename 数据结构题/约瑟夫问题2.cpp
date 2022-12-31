// https://www.luogu.com.cn/problem/P1996
// 解法：静态链表

#include <iostream>
using namespace std;

const int N = 110;
int e[N], ne[N], idx;

int main()
{
    int n, m;
    cin >> n >> m;
    for (idx = 1; idx <= n; idx ++) 
    {
        e[idx] = idx;
        ne[idx] = idx + 1;
    }
    ne[n] = 1;

    int p = 1, tmp;
    while ((n --) > 1)
    {
        for (int i = 1; i < m; i ++)
        {
            tmp = p;
            p = ne[p];
        }
        cout << e[p] << ' ';
        ne[tmp] = ne[p];
        p = ne[p];
    }
    cout << e[p];

    return 0;
}