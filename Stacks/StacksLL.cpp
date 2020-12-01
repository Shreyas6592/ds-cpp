#include <iostream>
#include <stdint.h>

using namespace std;

struct LNode
{
    int data;
    LNode *next;
};

struct Stack
{ 
    LNode *top;
};

Stack *createStack()
{
    Stack *S = new(Stack);
    return S;
}

void push(Stack *s, int data)
{
    if(s->top)
    {
        LNode *temp = new(LNode);
        temp->data = data;
        temp->next = s->top;
        s->top = temp;
    }
    else
    {
        LNode *temp = new(LNode);
        temp->data = data;
        temp->next = NULL;
        s->top = temp;
    }
}

void pop(Stack *s)
{
    LNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
}



void display(Stack *s)
{
    LNode *temp = s->top;
    
    do{
        if(temp == NULL)
        {   
            cout<<endl;
            break;
        }           
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(1);
}

int main()
{
    Stack *S = createStack();
    cout<<S<<endl;
    push(S,1);
    push(S,2);
    push(S,3);
    display(S);
    pop(S);
    display(S);
    pop(S);    
    display(S);
    pop(S);
    //display(S);
}