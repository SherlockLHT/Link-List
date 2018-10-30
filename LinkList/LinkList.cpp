#include "stdafx.h"
#include "LinkList.h"

void DisplayLinkList(ListNode* p_head)
{
	if (p_head == NULL)
	{
		return;
	}
	cout << p_head->value;
	p_head = p_head->next;
	while (p_head != NULL)
	{
		cout << "->" << p_head->value;
		p_head = p_head->next;
	}
	cout << endl;
}

ListNode* Append(ListNode* p_head, int value)
{
	ListNode* new_node = new ListNode(value);
	if (p_head == NULL)
	{	
		p_head = new_node;
		return p_head;
	}

	ListNode* tail_node = p_head;
	while (tail_node->next != NULL)
	{
		tail_node = tail_node->next;
	}
	tail_node->next = new_node;
	return p_head;
}

ListNode* InsertAt(ListNode* p_head, int index, int value)
{
	if (index <= 0 || p_head == NULL)
	{
		return InsertHead(p_head, value);
	}
	ListNode* index_node = p_head;
	ListNode* pre_node = NULL;
	int search_index = 0;
	while (index_node != NULL && search_index < index)
	{
		pre_node = index_node;
		index_node = index_node->next;
		search_index++;
	}
	ListNode* new_node = new ListNode(value);
	pre_node->next = new_node;
	new_node->next = index_node;
	return p_head;
}

ListNode* InsertAfter(ListNode* p_head, int pre_value, int value)
{
	ListNode* new_node = new ListNode(value);
	if (p_head == NULL)
	{
		return new_node;
	}
	ListNode* current_node = p_head;
	ListNode* after_node = current_node->next;
	while (current_node->value != pre_value && after_node != NULL)
	{
		current_node = current_node->next;
		after_node = current_node->next;
	}
	new_node->next = after_node;
	current_node->next = new_node;
	return p_head;
}

ListNode* InsertAhead(ListNode* p_head, int after_value, int value)
{
	ListNode* new_node = new ListNode(value);
	if (p_head == NULL || p_head->value == after_value)
	{
		return InsertHead(p_head, value);
	}
	ListNode* current_node = p_head;
	ListNode* ahead_node = p_head;
	while (current_node != NULL && current_node->value != after_value)
	{
		ahead_node = current_node;
		current_node = current_node->next;
	}
	if (current_node == NULL)
	{
		return InsertHead(p_head, value);
	}
	else
	{
		new_node->next = current_node;
		ahead_node->next = new_node;
		return p_head;
	}
}

ListNode* RemoveAt(ListNode* p_head, int index)
{
	if (p_head == NULL || index < 0)
	{
		return p_head;
	}
	if (index == 0)
	{
		return p_head->next;
	}
	ListNode* ahead_node = NULL;	//上一个位置节点
	ListNode* index_node = p_head;	//当前位置节点
	for (int search_index = 0; search_index < index; search_index++)
	{
		ahead_node = index_node;
		index_node = index_node->next;
		if (index_node == NULL)//没有搜索到位置
		{
			return p_head;
		}
	}
	delete index_node;	//节点资源释放
	ahead_node->next = index_node->next;
	return p_head;
}

ListNode* RemoveAllValue(ListNode* p_head, int value)
{
	if (p_head == NULL)
	{
		return p_head;
	}
	ListNode* ahead_node = NULL;
	ListNode* node = p_head;
	while (node != NULL)
	{
		if (node->value == value)
		{
			ListNode* node_next = node->next;
			delete node;	//释放节点资源
			node = node_next;
			if (ahead_node != NULL)
			{
				ahead_node->next = node;
			}
			else
			{
				p_head = node;
			}
		}
		else
		{
			ahead_node = node;
			node = node->next;
		}
	}
	return p_head;
}

ListNode* RemoveFirstValue(ListNode* p_head, int value)
{
	if (p_head == NULL)
	{
		return p_head;
	}
	ListNode* ahead_node = NULL;
	ListNode* node = p_head;
	while (node != NULL)
	{
		if (node->value == value)
		{
			ListNode* node_next = node->next;
			delete node;	//释放节点资源
			node = node_next;
			if (ahead_node == NULL)
			{
				p_head = node;
				break;
			}
			else
			{
				ahead_node->next = node;
			}
		}
		else
		{
			ahead_node = node;
			node = node->next;
		}
	}
	return p_head;
}

ListNode* InsertHead(ListNode* p_head, int value)
{
	ListNode* new_node = new ListNode(value);
	new_node->next = p_head;
	return new_node;
}

void ReleaseLinkList(ListNode* p_head)
{
	ListNode* next = p_head;
	while (p_head != NULL)
	{
		ListNode* current = p_head;
		p_head = p_head->next;
		delete current;
	}
}