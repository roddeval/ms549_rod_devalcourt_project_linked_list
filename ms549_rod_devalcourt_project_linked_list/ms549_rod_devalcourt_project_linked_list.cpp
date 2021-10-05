// ms549_rod_devalcourt_project_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

using namespace std;
#include <iostream>
#include "..\DoubleLinkedList\DoubleLinkedList.h"

int main()
{
    //std::cout << "Hello World!\n";
    DoubleLinkedList list;
    int result = 0;
    list.AddHead(4);
    list.AddHead(3);
    list.AddHead(2);
    list.AddHead(1);

    result = list.Find(3);

    result = list.Find(15);
    if (result == 0)
    {
        list.AddTail(15);
    }

    list.Delete(3);

    list.Print();

    list.PrintAll();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
