#include "pch.h"
#include "List.h"


template <typename E>
LIST_API List<E>::List()
{
	cout << "List()" << endl;
	Initialize();
}

template <typename E>
LIST_API List<E>::~List()
{
	cout << "~List()" << endl;
	DeInitialize();
}

template <typename E>
void LIST_API List<E>::Initialize()
{
	cout << "Initialize()" << endl;
	head = NULL;
	tail = NULL;
}

template <typename E>
void LIST_API List<E>::DeInitialize()
{
	cout << "DeInitialize()" << endl;
	if (head != NULL)
	{
		Empty(head);
		head = NULL;
		tail = NULL;
	}
}

template <typename E>
void LIST_API List<E>::Empty(ListNode<E>* pNode)
{
	cout << "Empty(ListNode<E>* " << pNode << ")" << endl;
	if (pNode != NULL)
	{
		Empty(pNode->next);
		delete pNode;
	}
}

template <typename E>
void LIST_API List<E>::Insert(const E& data)
{
	cout << "Insert(const E & " << data << ")" << endl;
	ListNode<E>* whereAt = NULL;
	if (head == NULL)
	{
		head = new ListNode<E>(data);
	}
	else
	{
		whereAt = head;
		while (whereAt->next != NULL)
		{
			whereAt = whereAt->next;
		}
		whereAt->next = new ListNode<E>(data);
		whereAt->next->previous = whereAt;
	}

}

template <typename E>
void LIST_API List<E>::Remove(E& object)
{
	cout << "Remove(E& " << object << ")" << endl;
	ListNode<E>* node = NULL;
	node = Find(object);
	if (node != NULL)
	{
		Remove(node);
	}

}

template <typename E>
void List<E>::Remove(ListNode<E>* pNode)
{
	cout << "Remove(ListNode<E>* " << pNode << ")" << endl;
	if ((head == NULL) || (pNode == NULL))
	{
		return;
	}
	if (head == pNode)
	{
		head = pNode->next;
	}
	if (pNode->next != NULL)
	{
		pNode->next->previous = pNode->previous;
	}
	if (pNode->previous != NULL)
	{
		pNode->previous->next = pNode->next;
	}
	delete pNode;
}

template <typename E>
LIST_API ListNode<E>* List<E>::Find(const E& data)
{
	cout << "Find(E " << data << ")" << endl;
	int findResult = 0;
	ListNode* node = NULL;
	if (head != NULL)
	{
		node = head;
		while ((node != NULL) && (findResult == 0))
		{
			if (node->data == data)
			{

				cout << "Found " << node << " ->data = " << node->data << endl;

				findResult = 1;
			}
			else
			{
				node = node->next;
			}
		}
	}

	if (findResult == 0)
	{
		cout << endl << "Did not find " << data << endl;
		node = NULL;
	}

	return node;
}

template <typename E>
void LIST_API List<E>::Print()
{
	cout << "Print()" << endl;
	ListNode* node = NULL;
	if (head != NULL)
	{
		node = head;
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}

template <typename E>
void LIST_API List<E>::PrintAll()
{
	cout << "PrintAll()" << endl;
	ListNode* node = NULL;
	if (head != NULL)
	{
		node = head;
		while (node != NULL)
		{
			cout << "          node :" << node << endl;
			cout << "    node->data :" << node->data << endl;
			cout << "    node->next :" << node->next << endl;
			cout << "node->previous :" << node->previous << endl;
			cout << "---------------" << endl;
			node = node->next;
		}
	}
}
