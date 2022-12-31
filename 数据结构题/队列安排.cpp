// https://www.luogu.com.cn/problem/P1160
// 解法：双向链表

#include <iostream>
using namespace std;
#define HEAD 0
#define END 100001

const int N = 100010;
int e[N], l[N], r[N], idx;
bool st[N];

void init()
{
    e[1] = 1;
    r[HEAD] = 1; r[1] = END;
    l[END] = 1; l[1] = HEAD;
    idx = 2;

    st[1] = true;
}

void insert(int t, int x) //将x插入到地址t后边
{
    e[idx] = x;
    l[idx] = t, r[idx] = r[t];
    l[r[t]] = idx;
    r[t] = idx ++;
}

void del(int t)
{
    r[l[t]] = r[t];
    l[r[t]] = l[t];
}

void traverse()
{
    for (int i = r[HEAD]; i != END; i = r[i])
        cout << e[i] << ' ';
    puts("");
}

int main()
{
    init();

    int n;
    cin >> n;
    for (int i = 2; i <= n; i ++)
    {
        int k, p;
        cin >> k >> p;

        if (p == 0) insert(l[k], i);
        else insert(k, i);

        st[i] = true;
    }

    int m;
    cin >> m;
    while (m --)
    {
        int x;
        cin >> x;
        if (st[x] == true) 
        {
            del(x);
            st[x] = false;
        }
    }

    traverse();

    return 0;
}