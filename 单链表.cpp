#include <iostream>
using namespace std;

const int N = 100010;
int e[N], ne[N], head, idx;

void init() //初始化
{
    head = -1; //head为第一个结点的地址，初始时设为-1
    idx = 1; //开辟结点空间
}

void head_insert(int x) //头插法插入x
{
    e[idx] = x, ne[idx] = head, head = idx ++;
}
void insert(int k, int x) //将x插入到地址（下标）为k的结点之后
{
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx ++;
}

void head_del() //删除头结点
{
    head = ne[head];
}
void del(int k) //将地址为k的结点的后面一个结点删掉
{
    ne[k] = ne[ne[k]];
}

void traverse()
{
    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << ' ';
    puts("");
}

int main()
{
    init();

    int M;
    cin >> M;
    while (M --)
    {
        char op;
        int k, x;

        cin >> op;        
        if (op == 'H')
        {
            cin >> x;
            head_insert(x);
        }
        else if (op == 'D') 
        {
            cin >> k;
            if (k == 0) head_del();
            else del(k);
        }
        else
        {
            cin >> k >> x;
            insert(k, x);
        }
    }
    
    traverse();

    return 0;
}