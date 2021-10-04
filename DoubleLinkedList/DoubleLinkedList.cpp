#include "DoubleLinkedList.h"
#include "pch.h"
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
	mnFindResult = 0;
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
	}
	cout << endl;
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
	cout << endl;
}

int DoubleLinkedList::Find(int data)
{
	cout << "DoubleLinkedList::Find(int " << data << ")" << endl;
	mnFindResult = 0;
	DoubleLinkedListNode* node = NULL;
	if (mnHead != NULL)
	{
		node = mnHead;
		while ((node != NULL) && (mnFindResult == 0))
		{
			if (node->data == data)
			{

				cout << "Found " << node << " ->data = " << node->data << endl;

				mnFindResult = 1;
			}
			node = node->next;
		}
	}

	if (mnFindResult == 0)
	{
		cout << endl << "Did not find " << data << endl;
	}
	else
	{
		cout << endl;
	}

	return mnFindResult;

}

DoubleLinkedListNode* DoubleLinkedList::CreateNewNode(int data)
{
	DoubleLinkedListNode* node = new DoubleLinkedListNode();
	if (node != NULL)
	{
		node->data = data;
		node->previous = NULL;
		node->next = NULL;
	}
	return node;
}
