#include "pch.h"
#include "CppUnitTest.h"
#include "..\5.4\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double tmp = S1(0., 0., 1);
			Assert::AreEqual(0., tmp);
		}
	};
}
