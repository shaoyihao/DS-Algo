//https://www.acwing.com/problem/content/829/

#include <iostream>
using namespace std;
#define HEAD 0
#define END 100001

const int N = 100010;
int e[N], l[N], r[N], idx;

void init()
{
    r[HEAD] = END;
    l[END] = HEAD;
    idx = 1;
}

void insert(int k, int x)
{
    e[idx] = x;
    l[idx] = k, r[idx] = r[k];
    l[r[k]] = idx;
    r[k] = idx ++;
}
void head_insert(int x)
{
    insert(HEAD, x);
}
void tail_insert(int x)
{
    insert(l[END], x);
}

void del(int k)
{
    r[l[k]] = r[k];
    l[r[k]] = l[k];
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

    int T;
    cin >> T;
    while (T --)
    {
        string op;
        int k, x;

        cin >> op;
        if (op == "L")
        {
            cin >> x;
            head_insert(x);
        }
        else if (op == "R")
        {
            cin >> x;
            tail_insert(x);
        }
        else if (op == "D")
        {
            cin >> k;
            del(k);
        }
        else if (op == "IL")
        {
            cin >> k >> x;
            insert(l[k], x);
        }
        else if (op == "IR")
        {
            cin >> k >> x;
            insert(k, x);
        }
    }

    traverse();

    return 0;
}
