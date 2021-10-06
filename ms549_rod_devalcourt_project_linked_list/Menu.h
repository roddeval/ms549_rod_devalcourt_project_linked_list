#pragma once

#include <cstddef>
#include <iostream>
using namespace std;
#include "..\DoubleLinkedList\DoubleLinkedList.h"

struct MenuItem
{
	int option = 0;
	string text = "";
};

class Menu
{
	private:
		int mnLimit;
		int mnCurrentCount;
		int mnMenuChoice;
		MenuItem marrMenuItem[10];
		DoubleLinkedList mList;
	public:
		Menu();
		void Initialize();
		void AddMenuOption(int num, string sText);
		void DisplayMenu();
		void ProcessMenu();
		void ProcessMenuSelection(int value);
		void Setup10();
		void Setup100();
		void Setup1000();
};

