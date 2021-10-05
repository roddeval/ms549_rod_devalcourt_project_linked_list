#pragma once

#ifndef __LIST_H
#define __LIST_H
#endif

#ifdef __LIST_H
#define LIST_API __declspec(dllexport) 
#else
#define LIST_API __declspec(dllimport)  
#endif

#include <iostream>
using namespace std;

template <typename T> struct ListNode
{
	T data;
	ListNode(const T& object, ListNode<T>* nextNode = NULL, ListNode<T>* prevNode = NULL) :
	         data(object), next(nextNode), previous(prevNode) {}
	ListNode<T>* next;
	ListNode<T>* previous;
};

template <typename E> 
class List
{
	private:
		ListNode<E>* head;
		ListNode<E>* tail;
		LIST_API void Empty(ListNode<E>* pNode);
	public:
		LIST_API List();
		LIST_API ~List();
		LIST_API void Initialize();
		LIST_API void DeInitialize();
		LIST_API void Insert(const E& data);
		LIST_API void Remove(E& object);
		LIST_API void Remove(ListNode<E>* pNode);
		LIST_API ListNode<E>* Find(const E& data);
		LIST_API void Print();
		LIST_API void PrintAll();
};
