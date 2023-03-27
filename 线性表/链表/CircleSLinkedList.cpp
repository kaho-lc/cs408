// 实现一个循环单链表
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int ElementType;

typedef struct LNode {
  // 数据域
  ElementType data;
  // 指针域
  struct LNode *next;
} LNode, *CSLinked;

// 初始化循环单链表
bool InitCSLinked(CSLinked L) {
  // 为L分配空间
  L = (LNode *)malloc(sizeof(LNode));
  // 如果分配失败，则直接返回false
  if (L == NULL) {
    return false;
  }
  L->next = L;
  return true;
}
