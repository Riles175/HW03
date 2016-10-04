#include "stdafx.h"
#include "CppUnitTest.h"
#include "fstream"
#include "iostream"
#include "readint.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(READINT_TEST)
	{
	public:
		TEST_METHOD(TestCase1) {
			std::ifstream ss("..\\UnitTest1\\zeroinput.txt");

			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", -3, 3), 0);

			std::cin.rdbuf(orig_cin);

			ss.close();


		}
		
		TEST_METHOD(TestCase2) // Test case 2: for invalid argument
		{
			// define a C++11 Lambda function to be called by your test
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 5, 1);
			};
			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}

		TEST_METHOD(TestCase3) {
			
			std::ifstream ss("..\\UnitTest1\\zeroinput.txt");

			if (ss.fail())
				throw int(-1);

			std::streambuf *orig_cin = std::cin.rdbuf(ss.rdbuf());

			Assert::AreEqual(read_int("My prompt: ", 0, 4), 3);

			std::cin.rdbuf(orig_cin);

			ss.close();
		}

		TEST_METHOD(TestCase4) {
			auto func = []() {
				// call with incorrect arguments (test case 2)
				read_int("My prompt: ", 0, 0);
			};
			// We expect an invalid_argument exception to be thrown when we call func!
			Assert::ExpectException<std::invalid_argument>(func);
		}

	};
}