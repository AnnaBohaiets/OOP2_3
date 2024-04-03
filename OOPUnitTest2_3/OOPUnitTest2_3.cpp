#include "pch.h"
#include "CppUnitTest.h"
#include "../OOPLab2_3/Money.h"
#include "../OOPLab2_3/Money.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace OOPUnitTest23
{
	TEST_CLASS(OOPUnitTest23)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Money a;
			a.setFirst(3);
			a.setSecond(9);
			++a;
			Money b;
			b.setFirst(4);
			b.setSecond(0);
			Assert::AreEqual(a.getFirst(), b.getFirst());
		}
	};
}
