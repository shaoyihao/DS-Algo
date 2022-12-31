// https://www.luogu.com.cn/problem/P1540
// 循环队列
#include <iostream>
using namespace std;

const int N = 1010;
int q[N], tail;
bool st[N];

int main()
{
    int m, n, res = 0;
    cin >> m >> n;
    
    bool flag = false;
    while (n --)
    {
        int x;
        cin >> x;
        if (st[x] == true) continue;
        else 
        {
            res ++;
            if (flag) st[q[tail]] = false;
            q[tail] = x;
            tail = (tail + 1) % m;
            if (tail == 0) flag = true;
            st[x] = true;
        }
    }
    
    cout << res;

    return 0;
}