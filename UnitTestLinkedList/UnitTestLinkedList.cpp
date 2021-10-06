#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include "..\DoubleLinkedList\DoubleLinkedList.h"

namespace UnitTestLinkedList
{
	TEST_CLASS(UnitTestLinkedList)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            DoubleLinkedList list;
            int findResult = 0;
            list.Insert(4);
            list.Insert(3);
            list.Insert(2);
            list.Insert(1);
            Assert::IsTrue(list.Count() == 4);
            findResult = list.Find(3);

            findResult = list.Find(15);
            if (findResult == 0)
            {
                list.Insert(15);
                Assert::IsTrue(list.Count() == 5);
            }

            list.Remove(3);
            Assert::IsTrue(list.Count() == 4);
        }
	};
}
