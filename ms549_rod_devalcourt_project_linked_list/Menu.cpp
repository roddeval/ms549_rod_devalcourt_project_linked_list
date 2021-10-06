#include "Menu.h"
#include <cstddef>
#include <iostream>
using namespace std;

Menu::Menu()
{
	Initialize();
}

void Menu::Initialize()
{
	int option = 0;
	string text = "";
	mnCurrentCount = 0;
	mnLimit = 6;
	mnMenuChoice = 0;

	option = 1;
	text = "Add Number To List";
	AddMenuOption(option, text);

	option = 2;
	text = "Remove Number From List";
	AddMenuOption(option, text);

	option = 3;
	text = "Display";
	AddMenuOption(option, text);

	option = 4;
	text = "Find Number In List";
	AddMenuOption(option, text);

	option = 5;
	text = "Display All";
	AddMenuOption(option, text);

	option = 6;
	text = "Quit";
	AddMenuOption(option, text);

}
void Menu::AddMenuOption(int num, string sText)
{
	if (mnCurrentCount < mnLimit)
	{
		MenuItem menuItem;
		menuItem.option = num;
		menuItem.text = sText;
		marrMenuItem[mnCurrentCount] = menuItem;
		mnCurrentCount++;
	}
}
void Menu::DisplayMenu()
{
	for (int x=0; x < mnCurrentCount; x++)
	{
		cout << marrMenuItem[x].option << " : " << marrMenuItem[x].text << endl ;
	}
	cout << "---------" << endl;
}
void Menu::ProcessMenu()
{
	int ok = 0;
	int keepGoing = 1;

	while (keepGoing == 1)
	{
		DisplayMenu();
		cout << "Input Menu Option: ";
		cin >> mnMenuChoice;

		if ((mnMenuChoice < 1) || (mnMenuChoice > mnLimit))
		{
			ok = 0;
			keepGoing = 1;
		}
		else		
		{
			ProcessMenuSelection(mnMenuChoice);
			if (mnMenuChoice == 6)
			{
				keepGoing = 0;
			}
		}
	}

}
void Menu::ProcessMenuSelection(int value)
{
	int number = 0;
	int findNumber = 0;

	switch (value)
	{
		case 1:
			cout << "Input Number: ";
			cin >> number;
			findNumber = mList.Find(number);
			if (findNumber == 0)
			{
				mList.Insert(number);
			}
			mList.Print();

		break;
		case 2:
				cout << "Input Number To Remove From List: ";
				cin >> number;
				findNumber = mList.Find(number);
				if (findNumber == number)
				{
					mList.Remove(number);
				}
			mList.Print();

		break;
		case 3:
			mList.Print();
		break;
		case 4:
			cout << "Input Number To Find: ";
			cin >> number;
			findNumber = mList.Find(number);
			mList.Print();
		break;
		case 5:
			mList.PrintAll();
		break;
		case 6:
			cout << "quitting menu" << endl;
		break;
		default:
			cout << "Invalid Option Selected!" << endl;
		break;
	}
}
