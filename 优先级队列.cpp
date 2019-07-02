#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 10
#define INCSIZE 2

typedef struct 
{
    int prev;
    int sign;
    int weight;
}Node;


typedef Node ElemType;

//typedef int ElemType;

typedef struct 
{
    ElemType *data;
    int cursize;    //已使用的长度
    int maxsize;    //最大长度
    int front;      //队列的头
    int rear;       //队列的尾部
}Queue;

void InitQueue(Queue &qt)
{
    qt.cursize = 0;
    qt.maxsize = QUEUESIZE;
    qt.front = 0;
    qt.rear = 0;
    ElemType *data = (ElemType *)malloc(sizeof(ElemType)*QUEUESIZE);
    if(data != NULL)
    {
        qt.data = data;
    }
}

void Destroy(Queue &qt)
{
    qt.cursize = 0;
    qt.front = 0;
    qt.rear = 0;
    qt.maxsize = 0;
    free(qt.data);
    qt.data = NULL;
}

void Adjust(int *arr,int start,int end)
{
    int tmp = arr[start];
    int i = 0;
    for(i = start*2+1; i <= end; i = i*2)
    {
        if((i+1) <= end && arr[i] < arr[i+1])
        {
            i++;
        }
        if(arr[i] > tmp)
        {
            arr[start] = arr[i];
            start = i;
        }
        if(arr[i] < tmp)
        {
            break;
        }
    }
    arr[start] = tmp;
}

bool IsEmpty(Queue &qt)
{
    return qt.cursize == 0;
}

bool IsFull(Queue &qt)
{
    return qt.cursize == qt.maxsize;
}

bool IncCap(Queue &qt)
{
    ElemType *newdata = (ElemType *)malloc(sizeof(ElemType)*qt.maxsize*INCSIZE);
    if(newdata == NULL) return false;
    int i = 0;
    for(i = 0; i < qt.maxsize; i++)
    {
        newdata[i] = qt.data[qt.front];
        qt.front = (qt.front+1)%qt.maxsize;
    }
    free(qt.data);
    qt.data = newdata;
    qt.front = 0;
    qt.rear = qt.maxsize;
    qt.maxsize = qt.maxsize*INCSIZE;
    return true;
}

bool Bigger(void *p1,void *p2)
{
    ElemType *e1 = (ElemType *)p1;
    ElemType *e2 = (ElemType *)p2;
    if(e1->weight > e2->weight)
    {
        return true;
    }
    return false;
}

void Adjust1(Queue &qt,int start,int end,bool(*Compare)(void *,void *))
{
    ElemType tmp = qt.data[start];
    int i = 0;
    for(i = start*2+1; i <= end; i = i*2)
    {
        if((i+1) <= end && Compare(&qt.data[i],&qt.data[i+1]))
        {
            i++;
        }
        if(Compare(&tmp,&qt.data[i]))
        {
            qt.data[start] = qt.data[i];
            start = i;
        }
        if(!Compare(&tmp,&qt.data[i]))
        {
            break;
        }
    }
    qt.data[start] = tmp;
}

bool InsertQueue(Queue &qt,ElemType val)
{
    if(IsFull(qt))
    {
        if(!IncCap(qt))
        {
            return false;
        }
    }
    qt.data[qt.rear] = val;
    qt.rear = qt.rear+1;
    qt.cursize++;
    int i = 0;
    for(i = (qt.cursize-2)/2; i >=0 && (qt.cursize-2) >= 0; i--)
    {
        Adjust1(qt,i,qt.cursize-1,Bigger);
    }
    return true;
}

bool PopQueue(Queue &qt,ElemType *val)
{
    if(IsEmpty(qt))
    {
        return false;
    }
    *val = qt.data[qt.front];
    qt.data[qt.front] = qt.data[--qt.rear];
    qt.cursize--;
    Adjust1(qt,0,qt.cursize,Bigger);
    return true;
}


void Sort(int *arr,int len)
{
    int i = 0;
    for(i = (len-2)/2; i>= 0; i--)
    {
        Adjust(arr,i,len-1);
    }
    int tmp = 0;
    for(i = len-1; i >= 0; i--)
    {
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        Adjust(arr,0,i-1);
    }
}

/*
void ShowQueue(Queue &qt)
{
    int i = qt.front;
    int j = 0;
    for(j = 0; j < qt.cursize; j++)
    {
        printf("%d ",qt.data[i]);
        i = (i+1)%qt.maxsize;
    }
}
*/


void Show(int *arr,int len)
{
    int i = 0;
    for(i = 0; i < len; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


/*
int main()
{
    Queue qu;
    InitQueue(qu);
    int arr[] = {23,1,34,2,45,12,55,44,33,67,89,11,25};
    int len = sizeof(arr)/sizeof(arr[0]);
    int i = 0;
    for(i; i < len; i++)
    {
        InsertQueue(qu,arr[i]);
    }
    ElemType val;
    for(i = 0; i < len; i++)
    {
        PopQueue(qu,&val);
        printf("%d ",val);
    }
    printf("\n");
    //Sort(arr,len);
    return 0;
}
*/





