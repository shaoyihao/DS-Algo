// https://www.luogu.com.cn/problem/P1540
// STL queue
#include <iostream>
#include <queue>
using namespace std;

const int N = 1010;
bool st[N];
queue<int> q;

int main()
{
    int m, n, res = 0;
    cin >> m >> n;
    while (n --)
    {
        int x;
        cin >> x;
        if (st[x] == false)
        {
            res ++;
            q.push(x);
            st[x] = true;

            if (q.size() > m)
            {
                st[q.front()] = false;
                q.pop();
            }
        }
    }
    
    cout << res;
    
    return 0;
}