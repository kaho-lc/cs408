#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int ElemType;
// 定义链表节点
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
} LNode, *LinkedList; // 此处的Lnode和*LinkedList是一样的

// 初始化一个带头节点的单链表
bool initList(LinkedList L)
{
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
    {
        return false; // 当前内存不足，分配空间失败
    }

    L->next = NULL; // 空表没有任何数据节点
    return true;
}

//todo 头插法建立单链表
LinkedList List_HeadInsert(LinkedList &L)
{

}

// 按位查找
LNode *GetElem(LinkedList &L, int i)
{
    if (i < 1)
    {
        return NULL; // 要插入的位置非法
    }
    LNode *p;
    p = L->next;
    int k = 1;
    while (p != NULL && k < i)
    {
        p = p->next;
        k++;
    }
    return p;
}

// 在位置i处插入节点，节点值为e
bool ListInsert(LinkedList &L, int i, ElemType e)
{
    // 先找到要插入位置的前一个节点
    LNode *prior = GetElem(L, i - 1);

    // 创建一个节点
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    if (newNode == NULL)
    {
        return false; // 内存不足分配空间失败
    }
    // 将新节点的数据域赋值
    newNode->data = e;
    // 下面两个的位置不能调换
    newNode->next = prior->next;
    prior->next = newNode;
    return true;
}
// 删除指定位置的节点，并将删除节点的值返回
bool ListDelete(LinkedList &L, int i, int &e)
{
    // 找到要删除位置的前一个节点
    LNode *prior = GetElem(L, i - 1);

    // 让p指针指向待删除节点
    LNode *p = prior->next;
    // 将要删除的节点的值返回
    e = p->data;

    prior->next = p->next;
    return true;
}

// 获取单链表的表长
int getLength(LinkedList &L)
{
    // 此表为空表
    if (L->next == NULL)
    {
        return 0;
    }

    LNode *p = L;
    int k = 0;
    while (p->next != NULL)
    {
        k++;
        p = p->next;
    }

    return k;
}

int main()
{
    LinkedList L;
    initList(L);
    return 0;
}
