#pragma once

#ifdef MYDLL_EXPORT
#define MYDLL_API __declspec(dllexport) 
#else
#define MYDLL_API __declspec(dllimport)  
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
		MYDLL_API DoubleLinkedList();
		MYDLL_API ~DoubleLinkedList();
		void MYDLL_API Initialize();
		void MYDLL_API DeInitialize();
		void MYDLL_API AddHead(int newData);
		void MYDLL_API AddTail(int newData);
		void MYDLL_API Print();
		void MYDLL_API PrintAll();
		int MYDLL_API Find(int data);
		void MYDLL_API Delete(int data);
	protected:
		void Empty(DoubleLinkedListNode* pCurrent);
		void MYDLL_API DeleteNode(DoubleLinkedListNode* head_ref, DoubleLinkedListNode* del);
		DoubleLinkedListNode* CreateNewNode(int data);
	private:
		DoubleLinkedListNode* mnHead;
		int mnFindResult;
		int mnCount;
};


