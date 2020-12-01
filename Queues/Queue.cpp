#include <iostream>
#include <stdint.h>
#include <cstring>
#include <stdbool.h>

using namespace std;

class Queue
{
    public:
    int8_t front,rear;
    uint8_t capacity;
    uint8_t size;
    uint8_t *array;
    Queue(uint8_t s):front(-1),rear(-1),capacity(s),size(0),array(NULL){}
};

Queue* CreateQ(uint8_t capacity)
{
    Queue* q = (Queue*)new Queue(capacity);
    q->array = (uint8_t*)new int(q->capacity);
    memset(q->array,'0',10);
    return q;
}

void printQ(Queue *q)
{
    // uint8_t cntr = 0;
    // cout<<"Printing rear to front"<<endl;
    // while(cntr < q->size)
    // {
    //     cout<<(unsigned)q->array[cntr]<<": ";
    //     cntr += 1;
    // }
    // cout<<endl;
    cout<<"Front: "<<(unsigned)q->front<<" Rear: "<<(unsigned)q->rear<<endl;
    cout<<"EFront: "<<(unsigned)q->array[q->front]<<" ERear: "<<(unsigned)q->array[q->rear]<<" Size: "<<(unsigned)q->size<<endl;    
}

bool enQ(Queue *q, uint8_t data)
{
    bool ret = false;
    if(q->size == q->capacity)
    {
        cout<<"Queue is full"<<endl;
        return ret;
    }
    if(q && q->array)
    { 
        q->rear = (int)(q->rear+1) % q->capacity;
        q->array[q->rear] = data;
        if(q->front == -1)
            q->front = q->rear;
        q->size++;
        ret = true;
    }
    return ret;
}

bool deQ(Queue *q)
{
    bool ret = false;
    if(q && q->array)
    {
        if(q->size == 0)
        {
            cout<<"Queue is empty"<<endl;
            return ret;
        }
        cout<<"De-queue element:"<<(unsigned)q->array[q->front]<<endl;
        if(q->front == q->rear)
        {
            q->front = q->rear = -1;
            q->size = 0;
        }
        else
        {
            q->front = (q->front+1) % q->capacity;
            q->size--;
        }
        ret = true;
    }
    return ret;
}

int main()
{
    Queue *q = (Queue*)CreateQ(10);
    enQ(q,1);
    enQ(q,2);
    enQ(q,3);
    enQ(q,4);
    enQ(q,5);
    enQ(q,6);
    enQ(q,7);
    enQ(q,8);
    enQ(q,9);
    enQ(q,10);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);
    deQ(q);
    printQ(q);                
}