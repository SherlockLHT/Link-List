#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode* next;
	ListNode(int val) :value(val), next(NULL){}
};

//显示链表
void DisplayLinkList(ListNode* p_head);

//追加链表
ListNode* Append(ListNode* p_head, int value);

//在特定位置插入节点
//index表示插入位置， <=0 均在头部插入，超出大小则在尾部追加
ListNode* InsertAt(ListNode* p_head, int index, int value);

//在特定值后面插入节点
//在pre_value后面插入，若没有pre_value，则在最后插入
ListNode* InsertAfter(ListNode* p_head, int pre_value, int value);

//在特定值前面插入节点
//在after_value前面插入，若没有after_value，则插在头部
ListNode* InsertAhead(ListNode* p_head, int after_value, int value);

//删除指定位置的节点
//若超出大小则不删
//index < 0，不删
ListNode* RemoveAt(ListNode* p_head, int index);

//删除特定数值的节点
ListNode* RemoveAllValue(ListNode* p_head, int value);

//删除第一次出现的值的节点
ListNode* RemoveFirstValue(ListNode* p_head, int value);

//头部插入
ListNode* InsertHead(ListNode* p_head, int value);

//释放链表
void ReleaseLinkList(ListNode* p_head);

#endif // LINK_LIST_H