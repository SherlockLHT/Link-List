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

//��ʾ����
void DisplayLinkList(ListNode* p_head);

//׷������
ListNode* Append(ListNode* p_head, int value);

//���ض�λ�ò���ڵ�
//index��ʾ����λ�ã� <=0 ����ͷ�����룬������С����β��׷��
ListNode* InsertAt(ListNode* p_head, int index, int value);

//���ض�ֵ�������ڵ�
//��pre_value������룬��û��pre_value������������
ListNode* InsertAfter(ListNode* p_head, int pre_value, int value);

//���ض�ֵǰ�����ڵ�
//��after_valueǰ����룬��û��after_value�������ͷ��
ListNode* InsertAhead(ListNode* p_head, int after_value, int value);

//ɾ��ָ��λ�õĽڵ�
//��������С��ɾ
//index < 0����ɾ
ListNode* RemoveAt(ListNode* p_head, int index);

//ɾ���ض���ֵ�Ľڵ�
ListNode* RemoveAllValue(ListNode* p_head, int value);

//ɾ����һ�γ��ֵ�ֵ�Ľڵ�
ListNode* RemoveFirstValue(ListNode* p_head, int value);

//ͷ������
ListNode* InsertHead(ListNode* p_head, int value);

//�ͷ�����
void ReleaseLinkList(ListNode* p_head);

#endif // LINK_LIST_H