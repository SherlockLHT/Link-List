// LinkList.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "LinkList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ListNode* head_node = new ListNode(1);
	DisplayLinkList(head_node);

	head_node = Append(head_node, 2);
	DisplayLinkList(head_node);

	head_node = Append(head_node, 2);
	DisplayLinkList(head_node);

	head_node = Append(head_node, 5);
	DisplayLinkList(head_node);

	head_node = Append(head_node, 3);
	DisplayLinkList(head_node);

	head_node = RemoveFirstValue(head_node, 12);
	DisplayLinkList(head_node);

	ReleaseLinkList(head_node);

	return 0;
}
