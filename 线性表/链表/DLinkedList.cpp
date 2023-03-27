// 双向链表
#include <corecrt_malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

// 定义结构图节点
typedef struct DNode {
  ElementType data;
  struct DNode *prior, *next;
} DNode, *DLinkedList;

// 初始化双向链表
bool InitDLinkedList(DLinkedList &L) {
  // 给头节点L分配内存空间
  L = (DNode *)malloc(sizeof(DNode));
  // 代表分配内存空间失败
  if (L == NULL) {
    return false;
  }

  // 将prior和next指针都指向null
  L->prior = NULL;
  L->next = NULL;
  return true;
}
// 在p节点后面插入s节点
bool InsertNextDNode(DNode *p, DNode *s) {
  // 输入的参数非法
  if (p == NULL || s == NULL) {
    return false;
  }

  s->next = p->next;
  // 确保p节点的后面还有节点
  if (p->next != NULL) {
    p->next->prior = s;
  }
  s->prior = p;
  p->next = s;
  return true;
}

// 删除p节点的后继节点
bool DeleteNextNode(DNode *p) {
  // 非法传参
  if (p == NULL) {
    return false;
  }
  // 保存p的下一个节点
  DNode *s = p->next;
  // 如果p没有下一个节点，则直接返回false
  if (s == NULL) {
    return false;
  }
  p->next = s->next;
  // 如果s节点的存在下一个节点的话,就将其prior指针指向p
  if (s->next != NULL) {
    s->next->prior = p;
  }
  // 释放p的下一个节点s
  free(s);
  return true;
}
// 判断双向链表是否为空表
bool isEmpty(DLinkedList &L) {

  if (L->next == NULL) {
    return true;
  } else {
    return false;
  }
}
// 销毁双向链表
void DestoryDList(DLinkedList &L) {
  while (L->next != NULL) {
    // 删除当前节点的后面节点
    DeleteNextNode(L);
  }
  // 释放头指针L指向的头节点
  free(L);
  // 重新将头指针L指向null
  L = NULL;
}
