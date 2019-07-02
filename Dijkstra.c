#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "优先级队列.cpp"

#define BIG 214783647
#define ROW 5       //5 个节点 


void Path(int *k,int n,int key)
{
    if(k[n] != key)
    {
        printf("%d ",k[n]);
        Path(k,k[n],key);
    }
    else
    {
        printf("%d ",key);
    }
}

//优先级队列
void Show(int arr[ROW][ROW])
{
    int i = 0;
    int j = 0;
    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < ROW; j++)
        {
            printf("%-10d",arr[i][j]);
        }
        printf("\n");
    }
}

void Display(int *arr)
{
    int i = 0;
    for(i = 0; i < ROW; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void Dijkstra(int map[ROW][ROW],int n,int *k)
{
    Queue qu;
    InitQueue(qu);
    int dis[ROW] = {0};
    int i = 0;
    for(i = 0; i < ROW; i++)
    {    
        dis[i] = BIG;
    }
    int hashmap[ROW] = {0};
    dis[n-1] = 0;
    ElemType pGet = {n-1,n-1,0};
    InsertQueue(qu,pGet);
    hashmap[n-1] = 1;
    while(!IsEmpty(qu))
    {
        ElemType node;
        PopQueue(qu,&node);
        if(dis[node.prev] + node.weight <= dis[node.sign])
        {
            dis[node.sign] = dis[node.prev] + node.weight;
            hashmap[node.sign] = 1;
            for(i = 0; i < ROW; i++)
            {
                if(hashmap[i] == 0)
                {
                    ElemType p;
                    p.weight = map[node.sign][i];
                    p.sign = i;
                    p.prev = node.sign;
                    InsertQueue(qu,p);
                }
            }
            k[node.sign] = node.prev;
        }
    }
    Display(dis);
}


/*
 * O(n^3)
void Dijkstra(int map[ROW][ROW],int n)
{
    int i = 0; 
    int j = 0;
    int path[ROW] = {0};
    char hashU[ROW] = {0};
    int D[ROW];
    for(i = 0; i < ROW; i++)
    {
        D[i] = map[n-1][i];
    }
    hashU[n-1] = 1;
    int k = 0;
    while(k < ROW)
    {
        int j = 0;
        int min = BIG; 
        int x = -1;
        int y = -1;
        for(i = 0; i < ROW; i++)
        {
            if(hashU[i] == 1)
            {
                for(j = 0; j < ROW; j++)
                {
                    if(hashU[j] == 0&& min > map[i][j])
                    {
                        min = map[i][j];
                        x = j;
                        y = i;
                    }
                }
            }
        }
        if(x != -1)
        {
            if(min+D[y] < D[x])
            {
                D[x] = D[y]+min;
                path[x] = y;
            }
            hashU[x] = 1;
        }
        else
        {
            break;
        }
    }
    for(i = 0; i < ROW; i++)
    {
        printf("%d ",D[i]);
    }
    printf("\n");
    printf("\n");
    printf("\n");
}
*/


int main()
{
    int arr[][ROW] = { {0,4,6,6,BIG},
                        {BIG,0,1,BIG,7},
                        {BIG,BIG,0,BIG,6},
                        {BIG,BIG,2,0,BIG},
                        {BIG,BIG,BIG,BIG,0}
                    };
    int *k = (int *)malloc(sizeof(int)*ROW);
    assert(k != NULL);
    memset(k,0xff,sizeof(int)*ROW);
    Dijkstra(arr,0,k);
    Display(k);
    Show(arr);
    printf("\n");
    printf("\n");
    printf("\n");
    Path(k,3,1);
    printf("\n");
    printf("\n");
    return 0;
}
