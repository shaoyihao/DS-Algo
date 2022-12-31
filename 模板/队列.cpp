// https://www.acwing.com/problem/content/831/
// 手写队列

#include <iostream>
using namespace std;

const int N = 100010;
int q[N], head, tail;

int main()
{
    int m;
    cin >> m;
    while (m --)
    {
        string op;
        cin >> op;

        if (op == "push")
        {
            int x;
            cin >> x;
            q[tail ++] = x;
        }
        else if (op == "pop") head ++;
        else if (op == "empty") puts(head == tail ? "YES" : "NO");
        else if (op == "query") cout << q[head] << endl;
    }

    return 0;
}