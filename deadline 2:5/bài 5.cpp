#include <Windows.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	char data;
	struct node* pNext;
};
typedef struct node NODE;

struct queue
{
	NODE* pHead;
	NODE* pTail;
};
typedef struct queue QUEUE;

void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

NODE* KhoiTaoNode(char x)
{
	NODE* p = new NODE();
	p->data = x;
	p->pNext = NULL;
	return p;
}

bool IsEmpty(QUEUE q)
{

	if (q.pHead == NULL)
	{
		return true;
	}
	return false;
}

bool Push(QUEUE& q, NODE* p)
{
	if (p == NULL)
	{
		return false;
	}


	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p;
	}
	else
	{
		q.pTail->pNext = p;
		q.pTail = p;
	}
	return true;
}

bool Pop(QUEUE& q, char& x)
{
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		NODE* p = q.pHead;
		x = p->data;
		q.pHead = q.pHead->pNext;
		delete p;

	}
	return true;
}
void XuatQueue(QUEUE q)
{
	system("cls");
	QUEUE k;
	KhoiTaoQueue(k);
	if (!IsEmpty(q)) {
		
		while (1) {
			char arr = { };
			NODE* i = KhoiTaoNode(arr);
			Push(k, i);
			NODE* n = k.pHead;
			while (n != NULL) {
				cout << n->data;
				cout << " ";
				n = n->pNext;
				
			}
			NODE* p = q.pHead;
			while (p != NULL)
			{
				cout << p->data;
				p=p->pNext;
			}
			
			Sleep(10);
			system("cls");
			
		}
		
	}

}
void NhapQueue(QUEUE& q, string h)
{
	for (int i = 0; i < h.length(); i++)
	{
		NODE* n = KhoiTaoNode(h[i]);
		Push(q, n);
	}
}
int main()
{
	string h;
	cin >> h;
	QUEUE q;
	KhoiTaoQueue(q);
	NhapQueue(q, h);
	XuatQueue(q);
	return 0;
}