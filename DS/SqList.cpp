#include"stdio.h"
#include"stdlib.h"
#define MaxSize 10
#define InitSize 10
using namespace std;

typedef struct SqList
{ //数组顺序表
	int *data;
	int len;
	int maxsize=MaxSize;
}SqList;
//静态分配
void List_init1(SqList &L)
{
    L.len=0;
}
//动态分配
void List_Init2(SqList &L)
{
    L.data=(int *)malloc(sizeof(int)*InitSize);
    L.len=0;
    L.maxsize=InitSize;
}
//打印列表
void List_Print(SqList L)
{
    for(int i=0;i<L.len;i++)
    {
        printf("%d\n",L.data[i]);
    }
}
//增加值
SqList List_Append(SqList &L,int elem)
{
    if(L.len==L.maxsize)
    {
        L.len+=1;
        L.maxsize+=1;
        int *tmp=(int *)malloc(sizeof(int)*L.len);
        for(int i=0;i<L.len;i++)
        {
            tmp[i]=L.data[i];
        }
        tmp[L.len-1]=elem;
        L.data=tmp;
        free(tmp);
    }
    else
    {
        L.len+=1;
        L.data[L.len-1]=elem;
    }
    return L;
}
//插入值
SqList List_Insert(SqList &L,int loc, int elem)
{
    if(loc>=0 && loc<=L.len+1)
    {
        if(L.len==L.maxsize)
        {
            L.len+=1;
            L.maxsize+=1;
            for(int i=L.len-1;i>=loc;i--)
            {
                L.data[i]=L.data[i-1];
            }
            L.data[loc-1]=elem;
        }
        else
        {
            L.len+=1;
            for(int i=L.len-1;i>=loc;i--)
            {
                L.data[i]=L.data[i-1];
            }
            L.data[loc-1]=elem;
        }
    }
    else
    {
        printf("error!\n");
    }
    return L;
}
//删除值
void List_Del(SqList &L,int loc,int &elem)
{
    if(loc>=0 && loc<=L.len)
    {
        int elem=L.data[loc-1];
        for(int i=loc-1;i<L.len;i++)
        {
            L.data[i]=L.data[i+1];
        }
        L.len-=1;
    }
    else
    {
        printf("error!\n");
    }
}
int GetElem_Loc(SqList L,int loc)
{//按位查找
    if(loc<=L.len)
        return L.data[loc-1];
    else
    {
        printf("error\n");
        return -1;
    }
}
int *GetElem_Val(SqList L,int val)
{//按值查找
    int *a,count=0;
    a=(int *)malloc(sizeof(int)*L.len);
    for(int i=0;i<L.len;i++)
    {
        if(L.data[i]==val)
        {
            count+=1;
            a[count-1]=val;
        }
    }
    if(count==0)
    {
        return NULL;
    }
    else
    {
        return a;
    }
}
int main()
{
    printf("----Begin----\n");
    SqList L;
    printf("----ListInit----\n");
    List_Init2(L);
    printf("----ListPrint----\n");
    List_Print(L);
    printf("----ListAppend=1----\n");
    List_Append(L,1);
    printf("len=%d\n",L.len);
    printf("----ListInsert(2,4)----\n");
    List_Insert(L,2,4);
    printf("----ListInsert(2,2)----\n");
    List_Insert(L,2,2);
    printf("----ListPrint----\n");
    List_Print(L);
    printf("----ListPrint----\n");
    printf("len=%d\n",L.len);
    int e=0;
    printf("----ListDelete_loc=3----\n");
    List_Del(L,3,e);
    printf("----ListPrint----\n");
    List_Print(L);
    printf("len=%d\n",L.len);
    printf("----ListInsert(3,0)----\n");
    List_Insert(L,3,0);
    printf("----ListPrint----\n");
    List_Print(L);
    printf("----ListAppend=3----\n");
    List_Append(L,3);
    printf("----ListAppend=7----\n");
    List_Append(L,7);
    printf("----ListAppend=9----\n");
    List_Append(L,9);
    printf("----ListPrint----\n");
    List_Print(L);
    printf("len=%d\n",L.len);
    printf("----GetElem_loc=4----\n");
    printf("Elem=%d\n",GetElem_Loc(L,4));
    printf("----End----\n");
    system("pause");
    return 0;
}