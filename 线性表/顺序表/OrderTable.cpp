#include <stdio.h>
#include <stdbool.h>

#define MaxSize 20 // 定义顺序表的最大容量
typedef int ElemType;

typedef struct
{
    ElemType data[MaxSize]; // 顺序表的元素
    int length;             // 顺序表当前的长度
} sqllist;                  // 顺序表的类型定义

int main()
{
    sqllist L;
    return 0;
}
// 初始化顺序表
void initList(sqllist &L)
{
    for (int i = 0; i < L.length; i++)
    {
        L.data[i] = 0; // 将顺序表中每一个位置上的元素的初始值都设置为0
    }
    L.length = 0; // 将当前顺序表的长度设置为0
}
// 在顺序表第i个位置插入元素e
bool ListInsert(sqllist &L, int i, ElemType e)
{ // 判断插入的位置是否合法
    {
        return false;
    }

    if (L.length >= MaxSize) // 判断当前的顺序表是否已满
    {
        return false;
    }
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    // 将第i-1个元素的值赋为e
    L.data[i - 1] = e;
    L.length++;
    return true;
}

// 删除指定位置的元素，并将删除的元素返回
bool ListDelete(sqllist &L, int i, ElemType &e)
{
    if (i < 1 || i > L.length) // 判断要删除的位置是否合法
    {
        return false;
    }
    e = L.data[i - 1]; // 将要删除的元素返回
    for (int j = i - 1; j <= L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }

    L.length--;

    return true;
}

// 按值查找
int locateElem(sqllist &L, ElemType e)
{
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
}

// 按位查找
ElemType getElem(sqllist &L, int index)
{
    if (index < 1 || index > L.length)
    {
        /* code */
        printf("查找的位序非法");
        return;
    }

    return L.data[index - 1];
}

// 获取顺序表的长度
int getLength(sqllist &L)
{
    return L.length;
}

// 判断顺序表是否为空
bool isEmpty(sqllist &L)
{
    return L.length == 0;
}