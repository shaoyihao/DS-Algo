// https://www.acwing.com/problem/content/830/
// 手写栈

#include <iostream>
using namespace std;

const int N = 100010;
int stk[N], top;

int main()
{
    int m;
    cin >> m;
    while (m --)
    {
        string op;
        cin >> op;
        
        if (op == "push")  //入栈
        {
            int x;
            cin >> x;
            stk[top ++] = x;
        }
        else if (op == "pop") top --; //出栈
        else if (op == "empty") puts(top == 0 ? "YES" : "NO"); //判断栈是否为空
        else if (op == "query") cout << stk[top - 1] << endl;  //输出栈顶元素
    }
    
    return 0;
}