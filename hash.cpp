#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define HASHSIZE 13

typedef int KeyType;

typedef struct {} Recode;

typedef struct 
{
	KeyType key;
	Recode *rec;
}ElemType;


typedef struct HashNode
{
	ElemType data;
	struct HashNode *next;
}HashNode;

typedef struct HashTable
{
	struct HashNode *table[HASHSIZE];
	int count;
}HashTable;


//函数实现
//初始化hashtable
bool Init_Hash(HashTable &ht)
{
	for(int i = 0; i < HASHSIZE; i++)
	{
		ht.table[i] = NULL;
	}
	ht.count = 0;
	return true;
}

//销毁hash
bool Destroy(HashTable &ht)
{
	for(int i = 0; i < HASHSIZE; i++)
	{
		while(ht.table[i] != NULL)
		{
			HashNode *p = ht.table[i];
			ht.table[i] = p->next;
			free(p);
			p = NULL;
		}
	}
	ht.count = 0;
	return true;
}

//购买节点
HashNode *BuyNode(ElemType x)
{
	HashNode *p = (HashNode *)malloc(sizeof(HashNode));
	if(NULL == p)
	{
		return NULL;
	}
	p->next = NULL;
	p->data = x;
	return p;
}

//计算散列值
int Hash(KeyType key)
{
	return key % HASHSIZE;
}

//查找元素
HashNode *FindKey(HashTable &ht,KeyType key) 
{
	int index = Hash(key);
	HashNode *p = ht.table[index];
	while(p != NULL)
	{
		if(p->data.key == key)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

//插入元素
bool Insert_Hash(HashTable &ht,ElemType ex)
{
	HashNode *p = FindKey(ht,ex.key);
	if(p == NULL)
	{
		int index = Hash(ex.key);
		HashNode *pGet = BuyNode(ex);
		if(NULL == pGet)
		{
			return false;
		}
		pGet->next = ht.table[index]->next;
		ht.table[index] = pGet;
	}
	return true;
}

//删除元素
bool Remove_Hash(HashTable &ht,ElemType ex)
{
	int index = Hash(ex.key);
	HashNode *prev = NULL;
	HashNode *p = ht.table[index];
	while(p != NULL)
	{
		if(p->data.key == ex.key)
		{
			if(NULL == prev)
			{
				ht.table[index] = p->next;
			}
			else
			{
				prev->next = p->next;
			}
			free(p);
			p = NULL;
			break;
		}
		prev = p;
		p = p->next;
	}
	if(NULL == p)
	{
		return false;
	}
	return true;
}

int main()
{
	
	return 0;
}
