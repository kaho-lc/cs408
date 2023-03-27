#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
// 定义链表节点
typedef struct LNode {
  ElemType data;
  struct LNode *next;
} LNode, *LinkedList; // 此处的Lnode和*LinkedList是一样的

// 初始化一个带头节点的单链表
bool initList(LinkedList L) {
  // 动态分配一个头节点的空间，让L指向此空间
  L = (LNode *)malloc(sizeof(LNode));
  if (L == NULL) {
    return false; // 当前内存不足，分配空间失败
  }

  L->next = NULL; // 空表没有任何数据节点
  return true;
}

// todo 头插法建立单链表
LinkedList List_HeadInsert(LinkedList &L) {
  // 为头节点分配空间
  L = (LNode *)malloc(sizeof(LNode));
  //将头节点的next指针置空
  L->next = NULL;
  LNode *s;
  int x;
  scanf("%d", &x);
  while (x != 9999) {
    // 为新插入的节点s分配空间
    s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = L->next;

    L->next = s;
    scanf("%d", &x);
  }
  // 将创建的单链表返回
  return L;
}

//  尾插法建立单链表
LinkedList List_TailInsert(LinkedList &L) {
  // 给头节点分配空间
  L = (LNode *)malloc(sizeof(LNode));
  // 使用x来接收输入的值
  int x;
  //定义待插入的节点
  LNode *s;
  // 定义一个尾指针，初始情况下，尾指针等于头指针
  LNode *tail;
  //获取用户输入
  scanf("%d", &x);

  while (x != 9999) {
    // 为s分配一个空间
    s = (LNode *)malloc(sizeof(LNode));

    s->data = x;

    // 将s节点插入到当前尾节点的后面
    tail->next = s;
    // 将尾指针指向当前新增的节点
    tail = s;
    //继续获取用户输入
    scanf("%d", &x);
  }
  // 将尾节点的下一个节点制空
  tail->next = NULL;
  // 将创建的单链表返回
  return L;
}
// 按位查找
LNode *GetElem(LinkedList &L, int i) {
  if (i < 0) {
    return NULL; // 要查找的位置非法
  }
  LNode *p;
  p = L->next;
  int k = 0;
  while (p != NULL && k < i) {
    p = p->next;
    k++;
  }
  return p;
}
// 按值查找
LNode *GetElemByValue(LinkedList L, ElemType e) {
  // 定义一个执政p指向首元节点
  LNode *p = L->next;
  while (p != NULL && p->data != e) {
    p = p->next;
  }
  return p;
}

// 在位置i处插入节点，节点值为e
bool ListInsert(LinkedList &L, int i, ElemType e) {
  // 先判断插入的位置是否合法
  if (i < 1) {
    printf("要插入的位置非法");
    return false;
  }
  // 先找到要插入位置的前一个节点
  LNode *prior = GetElem(L, i - 1);

  // 创建一个节点
  LNode *newNode = (LNode *)malloc(sizeof(LNode));
  if (newNode == NULL) {
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
bool ListDelete(LinkedList &L, int i, int &e) {
  // 找到要删除位置的前一个节点
  LNode *prior = GetElem(L, i - 1);

  // 让p指针指向待删除节点
  LNode *p = prior->next;
  // 将要删除的节点的值返回
  e = p->data;
  // 将要删除节点的前一个节点的next指针指向要删除节点的next节点
  prior->next = p->next;

  return true;
}

// 获取单链表的表长
int getLength(LinkedList &L) {
  // 此表为空表
  if (L->next == NULL) {
    return 0;
  }
  LNode *p = L;
  int len = 0;
  while (p->next != NULL) {
    len++;
    p = p->next;
  }

  return len;
}
