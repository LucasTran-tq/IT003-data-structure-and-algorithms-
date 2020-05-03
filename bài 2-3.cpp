#include <iostream>
using namespace std;
struct NODE
{
    int Data;
    NODE* Next;
};
struct LIST
{
    NODE* Top;
    NODE* Bottom;
};

NODE* CreateNode(int x)
{
    NODE* p = new NODE;

    p->Data = x;
    p->Next = NULL;
    return p;
}
void CreateEmptyList(LIST& S)
{
    S.Top = S.Bottom = NULL;
}
int isEmpty(LIST& S)
{
    if (S.Top == NULL)
        return 1;
    return 0;
}
void PUSH(LIST& S, NODE* p)
{
    if (S.Top == NULL)
    {
        S.Top = S.Bottom = p;
    }
    else {
        p->Next = S.Top;
        S.Top = p;
    }
}
bool POP(LIST& S, int& x)
{
    NODE* p;
    if (isEmpty(S) != 1)
    {
        if (S.Top != NULL)
        {
            p = S.Top;
            x = p->Data;
            S.Top = S.Top->Next;
            if (S.Top == NULL)
                S.Bottom = NULL;
            return 1;
        }
    }
    return 0;
}
void EnQueue(LIST& Q, NODE* p)
{
    if (Q.Top == NULL)
    {
        Q.Top = Q.Bottom = p;
    }
    else
    {
        Q.Bottom->Next = p;
        Q.Bottom = p;
    }
}
bool DeQueue(LIST& Q, int& x)
{
    NODE* p;
    if (isEmpty(Q) != 1)
    {
        if (Q.Top != NULL)
        {
            p = Q.Top;
            x = p->Data;
            Q.Top = Q.Top->Next;
            if (Q.Top == NULL)
            {
                Q.Bottom = NULL;
            }
            return 1;
        }
    }
    return 0;
}
void nhapNodeStack(LIST& S)
{
    NODE* p;
    char ch;
    do
    {
        ch = getchar();
        if (ch >= '0' && ch <= '9')
        {
            p = CreateNode(ch - '0');
            PUSH(S, p);
        }
    } while (ch != '\n');
}
void nhapNodeQueue(LIST& Q)
{
    NODE* p;
    char ch;
    do
    {
        ch = getchar();
        if (ch >= '0' && ch <= '9')
        {
            p = CreateNode(ch - '0');
            EnQueue(Q, p);
        }
    } while (ch != '\n');
}

void Print(LIST l)
{
    NODE *p = l.Top;
    cout<<"Print List: ";
    while(p)
    {
        cout<<p->Data;
        p = p->Next;
    }
    cout<<endl;
}

int main()

{
        LIST S;
        CreateEmptyList(S);
        cout<<"Stack: ";
        nhapNodeStack(S);
        Print(S);
        cout << "Queue: ";
        LIST Q;
        CreateEmptyList(Q);
        nhapNodeQueue(Q);
        Print(Q);
}


