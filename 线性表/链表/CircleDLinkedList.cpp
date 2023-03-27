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

bool InitCDLinkedList(CDLinkedList &L) {

  L = (DNode *)malloc(sizeof(DNode));

  if (L == NULL) {
    return false;
  }
  //循环双向链表,将头节点的prior和next指针都指向自己
  L->next = L;
  L->prior = L;
  return true;
}
