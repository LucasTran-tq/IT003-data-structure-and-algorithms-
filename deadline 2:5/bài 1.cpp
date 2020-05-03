#include<iostream>
using namespace std;
#define MAX 100
struct Stack
{
    int n;
    int e[MAX];
};
void Init(Stack &s)
{
    s.n = -1;
}
int IsEmpty(Stack s)
{
    if (s.n == -1)
        return 1;
    return 0;
}

int IsFull(Stack s)
{
    return (s.n == MAX - 1);
}
void Push(Stack &s, int x)
{
    if (IsFull(s))
        cout << "Ngan xep day";
    else
    {
        s.n++;
        s.e[s.n] = x;
    }
}
int Pop(Stack& s)
{
    if (IsEmpty(s))
    {
        cout << "Ngan xep rong";
        return -1;
    }
    else
        return s.e[s.n--];
}
void Input(Stack& s)
{
    int n, x;
    cout << "Nhap so phan tu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap gia tri: ";
        cin >> x;
        Push(s, x);
    }
}
void Output(Stack& s)
{
    while (IsEmpty(s) == 0)
        cout << Pop(s) << " " ;
}
int main()
{
    Stack S;
    Init(S);
    Input(S);
    cout << "Lay cac phan tu ra tu ngan xep: ";
    Output(S);
}


