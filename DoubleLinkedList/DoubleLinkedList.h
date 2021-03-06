#pragma once

#ifdef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_API __declspec(dllexport) 
#else
#define DOUBLELINKEDLIST_API __declspec(dllimport)  
#endif

struct DoubleLinkedListNode
{
	int data;
	DoubleLinkedListNode* previous;
	DoubleLinkedListNode* next;
};

class DoubleLinkedList
{
	public:
		DOUBLELINKEDLIST_API DoubleLinkedList();
		DOUBLELINKEDLIST_API DoubleLinkedList(int debug);
		DOUBLELINKEDLIST_API ~DoubleLinkedList();
		DOUBLELINKEDLIST_API void Initialize(int debug);
		DOUBLELINKEDLIST_API void DeInitialize();
		DOUBLELINKEDLIST_API void Insert(int newData);
		DOUBLELINKEDLIST_API void Print();
		DOUBLELINKEDLIST_API void PrintAll();
		DOUBLELINKEDLIST_API void Remove(int data);
		DOUBLELINKEDLIST_API int Find(int data);
		DOUBLELINKEDLIST_API int Count();
	protected:
		DOUBLELINKEDLIST_API void Empty(DoubleLinkedListNode* pCurrent);
		DOUBLELINKEDLIST_API DoubleLinkedListNode* Search(int data);
		DOUBLELINKEDLIST_API void Remove(DoubleLinkedListNode* del);
		DOUBLELINKEDLIST_API DoubleLinkedListNode* CreateNewNode(int data);
		DOUBLELINKEDLIST_API void AddHead(int newData);
		DOUBLELINKEDLIST_API void AddTail(int newData);
private:
		DoubleLinkedListNode* mnHead;
		int mnCount;
		int mnDebug;
};


