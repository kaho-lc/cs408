// 实现循环双链表
#include <corecrt_malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>


typedef int ElementType;

typedef struct DNode {
  ElementType data;
  struct DNode *prior, *next;
} DNode, *CDLinkedList;

// 初始化双向循环链表
bool InitCDLinkedList(CDLinkedList &L) {

  L = (DNode *)malloc(sizeof(DNode));

  if (L == NULL) {
    return false;
  }
  // 循环双向链表,将头节点的prior和next指针都指向自己
  L->next = L;
  L->prior = L;
  return true;
}
// 判断循环双向链表是否为空
bool isEmpty(CDLinkedList &L) { return L->next == NULL; }

// 判断节点p是否为循环单链表的尾节点
bool isTail(CDLinkedList L, DNode *P) { return P->next == L; }

// 在p结点之后插入s结点
bool InsetNextCDNode(DNode *p, DNode *s) {
  // 判断p结点是否含有下一个结点
  if (p->next != NULL) {
    s->next = p->next;
    p->next->prior = s;
  }
  p->next = s;
  s->prior = p;
  return true;
}
// 删除p结点后面的s结点
bool DeleteNode(DNode *p, DNode *s) {
  if (s->next != NULL) {
    p->next = s->next;
    s->next->prior = p;
  }
  free(s);
}
