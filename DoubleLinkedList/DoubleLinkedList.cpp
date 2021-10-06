#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#endif
#include "pch.h"
#include "DoubleLinkedList.h"

#include <iostream>
using namespace std;

DoubleLinkedList::DoubleLinkedList()
{
	cout << "DoubleLinkedList::DoubleLinkedList()" << endl;
	Initialize();
}

DoubleLinkedList::~DoubleLinkedList()
{
	cout << "DoubleLinkedList::~DoubleLinkedList()" << endl;
	DeInitialize();
}

void DoubleLinkedList::Initialize()
{
	cout << "DoubleLinkedList::Initialize()" << endl;
	mnHead = NULL;
	mnCount = 0;
}

void DoubleLinkedList::DeInitialize()
{
	cout << "DoubleLinkedList::DeInitialize()" << endl;
	if (mnHead != NULL)
	{
		Empty(mnHead);
		mnHead = NULL;
		mnCount = 0;
	}
}

void DoubleLinkedList::Empty(DoubleLinkedListNode* pCurrent)
{
	if (pCurrent != NULL)
	{
		cout << "DoubleLinkedList::Empty(DoubleLinkedListNode* " << pCurrent << ")" << endl;
		Empty(pCurrent->next);
		delete pCurrent;
	}
}

int DoubleLinkedList::Count()
{
	return mnCount;
}

void DoubleLinkedList::Insert(int newData)
{
	cout << "DoubleLinkedList::Insert(int " << newData << ")" << endl;
	DoubleLinkedListNode* node = NULL;
	node = Search(newData);
	if (node == NULL)
	{
		AddTail(newData);
	}
}

void DoubleLinkedList::AddHead(int newData)
{
	cout << "DoubleLinkedList::AddHead(int " << newData << ")" << endl;
	DoubleLinkedListNode* newNode = CreateNewNode(newData);
	if (newNode != NULL)
	{
		newNode->next = mnHead;
		newNode->previous = NULL;

		if (mnHead != NULL)
		{
			mnHead->previous = newNode;
			cout << "node prepended as previous node " << newData << endl;
		}
		else
		{
			cout << "node prepended as head node " << newData << endl;
		}

		mnHead = newNode;
		mnCount++;
	}
}

void DoubleLinkedList::AddTail(int newData)
{
	cout << "DoubleLinkedList::AddTail(int " << newData << ")" << endl;
	DoubleLinkedListNode* newNode = CreateNewNode(newData);
	DoubleLinkedListNode* node = NULL;
	if (newNode != NULL)
	{
		if (mnHead == NULL)
		{
			mnHead = newNode;
			cout << "node apppended as head node " << newData << endl;
		}
		else
		{
			node = mnHead;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = newNode;
			newNode->previous = node;
			cout << "node apppended " << newData << endl;
		}

		mnCount++;
	}
}

void DoubleLinkedList::Print()
{
	cout << "DoubleLinkedList::Print" << endl;
	cout << "Count = " << mnCount << endl;
	DoubleLinkedListNode* node = NULL;
	if (mnHead != NULL)
	{
		node = mnHead;
		while (node != NULL)
		{
			cout << node->data << " ";
			node = node->next;
		}
		cout << endl;
	}
}

void DoubleLinkedList::PrintAll()
{
	cout << "DoubleLinkedList::PrintAll" << endl;
	cout << "Count = " << mnCount << endl;
	DoubleLinkedListNode* node = NULL;
	if (mnHead != NULL)
	{
		node = mnHead;
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

int DoubleLinkedList::Find(int data)
{
	cout << "DoubleLinkedList::Find(int " << data << ")" << endl;
	DoubleLinkedListNode* node = NULL;
	int nodeFound = 0;
	int result = 0;
	if (mnHead != NULL)
	{
		node = mnHead;
		while ((node != NULL) && (nodeFound == 0))
		{
			if (node->data == data)
			{
				result = node->data;
				nodeFound = 1;
			}
			else
			{
				node = node->next;
				nodeFound = 0;
			}
		}
	}

	if (nodeFound == 0)
	{
		cout << endl << "Did not find " << data << endl;
		result = 0;
	}
	else
	{
		cout << "Found " << node << " ->data = " << node->data << endl;
	}
	return result;
}

DoubleLinkedListNode* DoubleLinkedList::Search(int data)
{
	cout << "DoubleLinkedList::Search(int " << data << ")" << endl;
	DoubleLinkedListNode* node = NULL;
	int nodeFound = 0;
	if (mnHead != NULL)
	{
		node = mnHead;
		while ((node != NULL) && (nodeFound == 0))
		{
			if (node->data == data)
			{

				nodeFound = 1;
			}
			else
			{
				node = node->next;
			}
		}
	}

	if (nodeFound == 0)
	{
		cout << endl << "Did not find " << data << endl;
		node = NULL;
	}
	else
	{
		cout << "Found " << node << " ->data = " << node->data << endl;
	}

	return node;
}

void DoubleLinkedList::Remove(int data)
{
	cout << "DoubleLinkedList::Delete(int " << data << ")" << endl;
	DoubleLinkedListNode* node = NULL;
	node = Search(data);
	if (node != NULL)
	{
		Remove(node);
	}

}

void DoubleLinkedList::Remove(DoubleLinkedListNode* del)
{
	cout << "DoubleLinkedList::Remove(DoubleLinkedListNode(DoubleLinkedListNode* " << del << ")" << endl;

	if ((mnHead == NULL) || (del == NULL))
	{
		return;
	}
	if (mnHead == del)
	{
		mnHead = del->next;
	}
	if (del->next != NULL)
	{
		del->next->previous = del->previous;
	}
	if (del->previous != NULL)
	{
		del->previous->next = del->next;
	}
	delete del;
	mnCount--;
}

DoubleLinkedListNode* DoubleLinkedList::CreateNewNode(int data)
{
	cout << "DoubleLinkedList::CreateNewNode(int " << data << ")" << endl;
	DoubleLinkedListNode* node = new DoubleLinkedListNode();
	if (node != NULL)
	{
		node->data = data;
		node->previous = NULL;
		node->next = NULL;
	}
	return node;
}
