// https://www.luogu.com.cn/problem/P1996
// 解法：动态链表

#include <iostream>
using namespace std;

struct node
{
    int val;
    node *next;
};
node *head;

void init()
{
    head = new node;
    head->val = 1;
    head->next = NULL;
}

int main()
{
    int n, m;
    cin >> n >> m;

    init();

    node *cur = head;
    for (int i = 2; i <= n; i ++)
    {
        node *p = new node;
        p->val = i;
        p->next = NULL;

        cur->next = p;
        cur = p;
    }
    cur->next = head;

    node *p = head, *tmp; 
    while ((n --) > 1)  //只要剩余结点数 >2 就继续进行循环
    {
        for (int i = 1; i < m; i ++)
        {
            tmp = p; //用tmp暂存p前一个结点
            p = p->next;
        } 
        cout << p->val << ' '; //循环结束，此时p指向报数为 m 的结点

        tmp->next = p->next;  //删去该结点
        delete p;
        p = tmp->next;
    }

    cout << p->val; //最后一个结点
    delete p;
    return 0;
}
