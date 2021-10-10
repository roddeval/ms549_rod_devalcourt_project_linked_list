#include "Menu.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include <cstddef>
#include <chrono>
#include <sstream> // stringstream
#include <fstream>
#include <iomanip> // put_time
#include <string>  // string
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


void Menu::Setup10()
{
	cout << "Menu::Setup10" << endl;
	auto start = std::chrono::high_resolution_clock::now();
	mList = DoubleLinkedList();
	for (int x = 0; x < 10; x++)
	{
		mList.Insert(x);
	}

	mList.Print();

	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = stop - start;

	std::cout << "Elapsed time: " << elapsed.count() << " s" << endl;

}
void Menu::Setup100()
{
	cout << "Menu::Setup100" << endl;
	auto start = std::chrono::high_resolution_clock::now();
	mList = DoubleLinkedList();
	for (int x = 0; x < 100; x++)
	{
		mList.Insert(x);
	}

	mList.Print();

	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = stop - start;

	cout << "Elapsed time: " << elapsed.count() << " s" << endl;


}
void Menu::Setup1000()
{
	cout << "Menu::Setup1000" << endl;
	auto start = std::chrono::high_resolution_clock::now();
	mList = DoubleLinkedList();
	for (int x = 0; x < 1000; x++)
	{
		mList.Insert(x);
	}

	mList.Print();
	auto stop = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed = stop - start;

	cout << "Elapsed time: " << elapsed.count() << " s" << endl;
}

void Menu::Setup100000()
{
	string pathFile = "C:\\Users\\rdeva\\source\\repos\\roddeval\\MS549_Rod_DeValcourt_BinarySearchTree\\100000_numbers.txt";
	fstream file;
	file.open(pathFile, ios::in);
	string line = "";
	std::string::size_type sz;
	int value = 0;

	if (file.is_open())
	{
		mList = DoubleLinkedList();

		cout << "100000 numbers" << endl;
		
		auto now = std::chrono::system_clock::now();

		auto in_time_t = std::chrono::system_clock::to_time_t(now);

		std::stringstream ss;

		ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
		string timeString = ss.str();

		cout << "start time: " << timeString << endl;

		while (getline(file, line))
		{
			value = std::stoi(line, &sz);
			mList.Insert(value);
		}

		mList.Print();

		auto now2 = std::chrono::system_clock::now();
		auto in_time_t2 = std::chrono::system_clock::to_time_t(now2);
		std::stringstream ss2;
		ss2 << std::put_time(std::localtime(&in_time_t2), "%Y-%m-%d %X");
		string timeString2 = ss2.str();

		cout << "stop time: " << timeString2 << endl;

		std::chrono::duration<double> elapsed = now2 - now;

		std::cout << "Elapsed time: " << elapsed.count() << " s" << endl;

	}
	file.close();

}
