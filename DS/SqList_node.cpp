#include"stdio.h"
#include"stdlib.h"
using namespace std;
/*
struct LNode{
    int data;
    struct LNode *next;
};
typedef struct LNode LNode;
typedef struct LNode *LinkList;
//等价于
*/
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode,*LinkList;

bool List_Init(LinkList &L)
{//初始化链表
    L=(LNode *)malloc(sizeof(LNode));//分配一个头节点
    if(L==NULL) return false;//判断是否位空指针
    else
    {//头节点不存储数据，是其指针域指向NULL
    //不带头节点的链表的头指针存储数据
        L->next=NULL;
        return true;
    }
    
}
bool List_Insert(LinkList &L,int loc,int elem)
{//若链表是不带头节点的情况下，我们要对头指针进行修改
//而带头指针的情况下就不用了，因为头节点本身不存储数据
    if(loc<1) return false;
    else
    {
        LNode *p;
        p=(LNode *)malloc(sizeof(LNode));
        p=L;
        for(int i=0;p!=NULL && i<loc-1;i++)
        {//p!=NULL有效的预防了错误插入的情况
        //若插入位置超过了当前长度+1，那么会运行到p=NULL的位置
        //然后跳出循环
            p=p->next;
        }
        LNode *q;
        q=(LNode *)malloc(sizeof(LNode));
        q->data=elem;
        q->next=p->next;
        p->next=q;
        return true;
    }
    
}
void List_Print(LinkList L)
{//打印链表
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p = L;
    if(L->next->next != NULL)
    {
        while(p != NULL)
        {
            p = p->next;
            if(p == NULL) break;
            printf("%d\n",p->data);
        }
    }
    else printf("error!\n");
}
bool List_Append(LinkList &L,int elem)
{//后增
    LNode *p;
    p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL) return false;
    p = L;
    while(p->next != NULL)
    {
        p = p->next;
    }
    LNode *q = (LNode *)malloc(sizeof(LNode));
    q->data = elem;
    q->next = NULL;
    //这个地方尤其要注意，虽然添加了节点，但该节点的next一定要赋值为NULL
    //或者是新增节点的next指向最后一个节点的next的位置（也是NULL）
    //也就是说这里可以写作 q->next = p->next
    p->next = q;
    return true;
}

bool LNode_Insert_before(LNode *n1,LNode *n2)
{//这种情况不用管是不是头节点尾节点
//本质上属于后插然后交换数据域
    n2->next = n1->next;
    n1->next = n2;
    int tmp = n1->data;
    n1->data = n2->data;
    n2->data = tmp;
    return true;
}
bool LNode_Insert_behind(LNode *n1,LNode *n2)
{//后插
    if(n1 == NULL || n2 == NULL) return false;
    n2->next = n1->next;
    n1->next = n2;
    return true;
}
bool List_Lnode_Delete(LinkList &L, int loc, int &elem)
{//删除节点并返回删除的值
//带头节点
    if(loc<1) return false;
    LNode *p = (LNode *)malloc(sizeof(LNode));
    if(p == NULL) return false;
    p=L;
    for(int i = 0; i < loc-1 && p != NULL; i++)
    {
        p = p->next;
    }
    if(p == NULL) return false;
    elem=p->next->data;
    LNode *q=p->next;
    p->next=p->next->next;
    free(q);
    return true;
}
bool List_LNode_Delete(LNode *n1)
{//不考虑头节点
//不看节点前的元素
//这段代码有bug！！！
    if(n1 == NULL) return false;
    LNode *q=n1->next;
    n1->data = n1->next->data;//若要删除的节点刚好是最后一个节点
    //这里可能会出现空指针的错误！！！！
    //要避免的话对单链表而言智能从头节点开始找，最土的方法
    n1->next=n1->next->next;
    free(q);
    return true;
}
int main()
{//测试用例
    printf("----BEGIN----\n");
    LinkList l1;
    printf("----List_Init----\n");
    List_Init(l1);
    printf("----List_Insert----\n");
    List_Insert(l1,1,1);
    printf("----List_Insert----\n");
    List_Insert(l1,1,3);
    printf("----List_Insert----\n");
    List_Insert(l1,3,0);
    printf("----List_Print----\n");
    List_Print(l1);
    printf("----List_Append----\n");
    List_Append(l1,5);
    printf("----List_Insert----\n");
    List_Insert(l1,4,2);
    printf("----List_Print----\n");
    List_Print(l1);
    printf("----List_Node_Delete----\n");
    int elem;
    List_Lnode_Delete(l1,5,elem);
    printf("del = %d\n",elem);
    printf("----List_Print----\n");
    List_Print(l1);
    LinkList l2;
    l2=l1;
    printf("----List_Print----\n");
    List_Print(l2);
    printf("----END----\n");
    system("pause");
    return 0;
}