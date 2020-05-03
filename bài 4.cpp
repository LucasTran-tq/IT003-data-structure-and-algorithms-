//
//  main.cpp
//  bài 4
//
//  Created by Thắng Trần on 4/30/20.
//  Copyright © 2020 Thắng Trần. All rights reserved.
//

#include <iostream>
#include <typeinfo>
using namespace std;

struct NODE
{
    char data;
    NODE *Next;
};

struct LIST
{
    NODE *Top;
    NODE *Bottom;
};

void CreateList(LIST &l)
{
    l.Top = l.Bottom = NULL;
}

NODE* CreateNode_Char(char data)
{
   
    NODE *p = new NODE;
    if(p == NULL) return 0;
    else
    {
        p->data = data;
        p->Next = NULL;
    }
    return p;
}

NODE* CreateNode_Int(int data)
{
    NODE *p = new NODE;
    if(p == NULL) return NULL;
    p->data = data;
    p->Next = NULL;
    return p;
}

bool EmptyList(LIST &l)
{
    if(l.Top == NULL) return 1;
    else return 0;
}

// instal STACK
void PUSH(LIST &l, NODE *p)
{
    if(l.Top == NULL)
        l.Top = l.Bottom = p;
    else
    {
        p->Next = l.Top;
        l.Top = p;
    }
}

void POP_Char(LIST &l, char &x)
{
    NODE *p;
    if(EmptyList(l) != 1)
    {
        if(l.Top != NULL)
        {
            p = l.Top;
            x = p->data;
            l.Top = l.Top->Next;
            if(l.Top == NULL)
                l.Bottom = NULL;
            //return 1;
        }
        
    }
    //return 0;
}

void POP_Int(LIST &l, int &x)
{
    NODE *p;
    if(EmptyList(l) != 1)
    {
        if(l.Top != NULL)
        {
            p = l.Top;
            x = p->data;
            l.Top = l.Top->Next;
            if(l.Top == NULL)
                l.Bottom = NULL;
            //return 1;
        }
        
    }
    //return 0;
}

// instal QUEUE

void EnQueue(LIST &l, NODE *p)
{
    if(l.Top == NULL)
        l.Top = l.Bottom = p;
    else
    {
        l.Bottom->Next = p;
        l.Bottom = p;
    }
}

void DeQueue(LIST &l, int x)
{
    NODE *p;
    if(l.Top != NULL)
    {
        p = l.Top;
        x = p->data;
        l.Top = l.Top->Next;
        if(l.Top == NULL)
            l.Bottom = NULL;
    }
}

void Input(LIST &l)
{
    char ch;
    NODE *p;
    cout<<"Input: ";
    do
    {
        ch = getchar();
        if(ch == '\n') break;
        p = CreateNode_Char(ch);
        EnQueue(l, p);
    }while(ch != '\n');
     
}

void Print(LIST l)
{
    NODE *p = l.Top;
    while(p)
    {
        cout<<p->data<<'\t';
        p = p->Next;
    }
    cout<<endl;
    cout<<"l.Top->data: "<<l.Top->data<<endl;
    cout<<endl;
}



int Convert_Postfix_into_Result(LIST &l)
{
    // 512+3+4++
    char Char_In_Queue;
    int Value_into_Stack;
    LIST S;  // S: stack;
    CreateList(S);
    NODE *p;
    int Number = 0;
    int Number1;  // First Number
    int Number2;  // Second Number
    while(l.Bottom != NULL)
    {
        POP_Char(l, Char_In_Queue);//get x from first List
        //cout<<"Char_In_Queue = "<<Char_In_Queue<<endl;
        if(Char_In_Queue == '+')
        {
            POP_Int(S, Number1);
            POP_Int(S, Number2);
            //cout<<"number 1: "<<Number1<<endl;
            //cout<<"number 2: "<<Number2<<endl;
            //cout<<"typeid: ";
            //cout << typeid(Number1).name() << endl;
            Number = Number2 + Number1;
            //cout<<"number 1 + number 2: "<<Number<<endl;
            p = CreateNode_Int(Number);
            PUSH(S, p);
            //cout<<"--->After Push + : ";
            //Print(S);
        }
        if(Char_In_Queue == '-')
        {
            POP_Int(S, Number1);
            POP_Int(S, Number2);
            Number = Number2 - Number1;
            p = CreateNode_Int(Number);
            PUSH(S, p);
        }
        if(Char_In_Queue == '*')
        {
            POP_Int(S, Number1);
            POP_Int(S, Number2);
            Number = Number1 * Number2;
            p = CreateNode_Int(Number);
            PUSH(S, p);
        }
        if(Char_In_Queue == '/')
        {
            POP_Int(S, Number1);
            POP_Int(S, Number2);
            Number = Number2 / Number1;
            p = CreateNode_Int(Number);
            PUSH(S, p);
        }
        else if(Char_In_Queue >= '0' && Char_In_Queue <= '9')
        {
            Value_into_Stack = (int)(Char_In_Queue - '0');
            p = CreateNode_Int(Value_into_Stack);
            PUSH(S, p);
            //cout<<"--->After Push Number : ";
            //Print(S);
        }
        
    }
    //cout<<"--------------Print final edition: ";
    //Print(S);
    return Number;
}

int Operator(char &ch)
{
    int result = 0;
    if(ch == '(') result = 0;
    if(ch == '+' || ch == '-') result = 1;
    if(ch == '*' || ch == '/') result = 2;
    if(ch == '^') result = 3;
    
    return result;
}

LIST Convert_infix_into_postfix(LIST &l)
{
    LIST Q;
    LIST S;
    CreateList(Q);
    CreateList(S);
    NODE *p;
    char Char_in_List;
    char Char_in_Stack = '\0';
    int Number_first_operator =0; // operator in Stack;
    int Number_second_operator =0; // operator in List;
    while(l.Bottom != NULL)
    {
        POP_Char(l, Char_in_List);
        //cout<<">>>>>>Test Char_in_List: "<<Char_in_List<<endl;
        //cout<<endl;
        if(Char_in_List >= '0' && Char_in_List <= '9') // Enqueue into Queue
        {
            //cout<<"-----IN 1 Number:"<<endl;
            //cout<<"qqqqq ->Char_in_List Q: "<<Char_in_List<<endl;
            p = CreateNode_Char(Char_in_List);
            EnQueue(Q, p);
            //cout<<"Queue: ";
            //Print(Q);
        }
        if(Char_in_List == '+' || Char_in_List == '-' || Char_in_List == '*' || Char_in_List == '/' ) // PUSH into Stack
        {
            //cout<<"-----IN 2:"<<endl;
           
            Number_second_operator = Operator(Char_in_List); // Get Number of operator in list to Compare
            //cout<<"Char_in_List: "<<Char_in_List<<endl;
            //cout<<"Compare_second_operator: "<<Number_second_operator<<endl;
            //cout<<endl;
            
            // get Number of operator from Stack into Queue to Compare.
            POP_Char(S, Char_in_Stack);
            Number_first_operator = Operator(Char_in_Stack);
            //cout<<"Compare_second_operator vs Compare_first_operator: "<<Char_in_List<<" vs "<<Char_in_Stack<<endl;
            //cout<<"Compare_second_operator vs Compare_first_operator: "<<Number_second_operator<<" vs "<<Number_first_operator<<endl;
            
            if(Number_second_operator <= Number_first_operator) // if list's operator is bigger than stack's operator
            {
                while(Number_second_operator <= Number_first_operator)
                {
                    // Get operator from Stack into Queue
                    p = CreateNode_Char(Char_in_Stack);
                    EnQueue(Q, p);
                    
                    // Continue to take the operator in Stack to check with the one in list
                    POP_Char(S, Char_in_Stack);
                    //cout<<"Char_in_Stack: "<<Char_in_Stack<<endl;
                    Number_first_operator = Operator(Char_in_Stack);
        
                }
                if(Number_second_operator > Number_first_operator)
                {
                    // Get operator in Stack again
                    p = CreateNode_Char(Char_in_Stack);
                    PUSH(S, p);
                }
                // get operator from List into Stack
                p = CreateNode_Char(Char_in_List);
                PUSH(S, p);
            }
            else
            {
                // Get operator in Stack again
                p = CreateNode_Char(Char_in_Stack);
                PUSH(S, p);
                // Get operator from list into Stack
                p = CreateNode_Char(Char_in_List);
                PUSH(S, p);
            }
            //cout<<"Stack: ";
           //Print(S);
            
        }
        
        if(Char_in_List == '(')
        {
            //cout<<"--IN 3:"<<endl;
            p = CreateNode_Char(Char_in_List);
            PUSH(S, p);
            //cout<<"Stack: ";
            //Print(S);
            Number_first_operator = Operator(Char_in_List);
            //cout<<"Compare_first_operator: "<<Number_first_operator<<endl;
        }
        
        if(Char_in_List == ')') // Get Operation in Stack when meet ')'
        {
            //cout<<"----------------------IN 4 :"<<endl;
            
            {
                //cout<<"qqqqq ->Char_in_List Q: "<<Char_in_Stack<<endl;
                
                //cout<<"pop after ')' "<<endl;
                POP_Char(S, Char_in_Stack);
                //cout<<"Char_in_Stack: "<<Char_in_Stack<<endl;
                p = CreateNode_Char(Char_in_Stack);
                EnQueue(Q, p);
                if(Char_in_Stack != '(')
                {
                    while(Char_in_Stack != '(')
                    {
                        POP_Char(S, Char_in_Stack);
                        //cout<<"Char_in_Stack Second POP: "<<Char_in_Stack<<endl;
                        if(Char_in_Stack == '(') continue;
                        p = CreateNode_Char(Char_in_Stack);
                        EnQueue(Q, p);
                        
                    }
                }
                //cout<<"Queue: ";
                //Print(Q);
                //cout<<"Stack: ";
                //Print(S);
            }
        }
    }
    //cout<<"After end the list, continue Take(Enqueue) element from Stack to Queue: "<<endl;
    while(S.Bottom != NULL)
    {
        //cout<<"final: "<<endl;
        POP_Char(S, Char_in_Stack);
        //cout<<"Char_in_Stack: "<<Char_in_Stack<<endl;
        if(Char_in_Stack == '(')
        {
            if(EmptyList(S))
            {
                //cout<<"empty!!!"<<endl;
                continue;
            }
            POP_Char(S, Char_in_Stack);
        }
        
        //cout<<"overcome: "<<endl;
        p = CreateNode_Char(Char_in_Stack);
        EnQueue(Q, p);
        //cout<<"Queue: ";
        //Print(Q);
    }
    
    return Q;
}


/////.     EXAMPLE. !!!!!

/// INFIX -       -------->>.  POSTFIX ------------->>>>.    RESULT

// (4+8)*(6-5)/((3-2)*(2+2))  -->> 48+65-*32–22+*/   --->>>. 3

/// 48+65-*32-22+*/

// 3+4*5/6.  --->> 345*6/+. ----->>>. 6.33
// 5+6/3*(5+6)-7. ---->>> 563/56+*+7-  --->>>. 20
// 5+((1+2)*4)+3 --->> 512+4*+3+.   --->>> 20

// 512+3+4++
int main()
{
    LIST l;
    CreateList(l);
    Input(l);
    Print(l);
    
    LIST Convert_Infix_Into_Postfix;
    CreateList(Convert_Infix_Into_Postfix);
    Convert_Infix_Into_Postfix = Convert_infix_into_postfix(l);
    cout<<endl;
    cout<<">>>>>>>>>>>>Infix to Postfix Convertion: ";
    Print(Convert_Infix_Into_Postfix);
    
    
    int Result = 0;
    Result = Convert_Postfix_into_Result(Convert_Infix_Into_Postfix);
    cout<<"The Final Result: "<<Result<<endl;
    
    
    /*
    int Result = 0;
    Result = Convert_Postfix_into_Result(l);
    cout<<"The Final Result: "<<Result<<endl;
    */
}
