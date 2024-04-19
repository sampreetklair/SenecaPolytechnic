// -----------------------------------------------------------
// Name: Sampreet Klair
// Student ID: sklair2@myseneca.ca
// Student Number: 145031225
// Section: ZDD
// -----------------------------------------------------------

#include "pre-compiled-header.h"
#include "customer.h"
#include "customer_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
		// Black box testing by giving valid input.
		TEST_METHOD(TestMethod1)
		{
			char pos1[] = "X1Y 2Z3";
			Assert::IsTrue(pos1);
		}

		// Black box testing by giving invalid input.
		TEST_METHOD(TestMethod2)
		{
			char pos2[] = "XY1 2Z3";
			Assert::IsFalse(pos2);
		}

		// Black box testing by giving valid input.
		TEST_METHOD(TestMethod3)
		{
			char pos3[] = "A1B 2C3";
			Assert::IsTrue(pos3);
		}

		// Black box testing by giving invalid input.
		TEST_METHOD(TestMethod4)
		{
			char pos4[] = "X1Y 23Z";
			Assert::IsFalse(pos4);
		}

		// Black box testing by giving valid input.
		TEST_METHOD(TestMethod5)
		{
			char pos5[] = "A1B2C3";
			Assert::IsTrue(pos5);
		}

		// Black box testing by giving invalid input.
		TEST_METHOD(TestMethod6)
		{
			char pos6[] = "123 456";
			Assert::IsFalse(pos6);
		}

		// White box testing by giving valid input.
		TEST_METHOD(TestMethod7)
		{
			char pos7[] = "X4Y 5Z6";
			Assert::IsTrue(pos7);
		}

		// White box testing by giving invalid input.
		TEST_METHOD(TestMethod8)
		{
			char pos8[] = "X7Y 8Z 9";
			Assert::IsFalse(pos8);
		}

		// White box testing by giving valid input.
		TEST_METHOD(TestMethod9)
		{
			char pos9[] = "x8y46z";
				Assert::IsTrue(pos9);
		}

		// White box testing by giving invalid input.
		TEST_METHOD(TestMethod10)
		{
			char pos10[] = "X4Y AZ6";
			Assert::IsFalse(pos10);
		}
	
		// White box testing by giving valid input.
		TEST_METHOD(TestMethod11)
		{
			char pos11[] = "x8y46z";
				Assert::IsTrue(pos11);
		}

		// White box testing by giving valid input.
		TEST_METHOD(TestMethod12)
		{
			char pos12[] = "x8y 4z6";
			Assert::IsTrue(pos12);
		
		}

		// White box testing by giving invalid input.
		TEST_METHOD(TestMethod13)
		{
			char pos13[] = "123456";
			Assert::IsFalse(pos13);
		}
	};
}
