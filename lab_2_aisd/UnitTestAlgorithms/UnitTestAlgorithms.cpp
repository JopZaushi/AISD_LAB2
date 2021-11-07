#include "pch.h"
#include "CppUnitTest.h"
#include "..\\lab_2_aisd\algorithms.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAlgorithms
{
	TEST_CLASS(UnitTestAlgorithms)
	{
	public:
		
		TEST_METHOD(TestGenerateArray){
			int* array = new int[10];
			array = Generate_Array(array, 10);
			bool proverka = true;
			for (int i = 0; i < 10 - 1; i++) {
				if ((array[i] > 99) || (array[i] < 0))
					proverka = false;
			}
			Assert::IsTrue(proverka == true);
			delete[]array;
		}
		TEST_METHOD(TestBinarySearch) {
			int* array = new int[10];
			for (int i = 0; i < 10 - 1; i++) {
				array[i] = i;
			}
			for (int i = 0; i < 10 - 1; i++) {
				Assert::IsTrue(BinarySearch(array, i, 10) == i);
			}
			try {
				BinarySearch(array, 44, 10);
			}
			catch (const invalid_argument error) {
				Assert::AreEqual("There is no such element in the array", error.what());
			}
			delete[]array;
		}
		TEST_METHOD(TestInsertionSort) {
			int* array = new int[10];
			array = Generate_Array(array, 10);
			bool proverka = true;
			InsertionSort(array, 10);
			for (int i = 0; i < 10 - 2; i++) {
				if (array[i] > array[i + 1])
					proverka = false;
			}
			Assert::IsTrue(proverka == true);
			delete[]array;
		}
		TEST_METHOD(TestQuickSort) {
			int* array = new int[10];
			for (int i = 0; i < 10 - 1; i++) {
				array[i] = 10 - i;
			}
			bool proverka = true;
			QuickSort(array, 0, 10 - 1);
			for (int i = 0; i < 10 - 2; i++) {
				if (array[i] > array[i + 1])
					proverka = false;
			}
			Assert::IsTrue(proverka == true);
			delete[]array;
		}
		TEST_METHOD(TestBogoSort) {
			int* array = new int[10];
			array = Generate_Array(array, 10);
			bool proverka = true;
			BogoSort(array, 10);
			for (int i = 0; i < 10 - 2; i++) {
				if (array[i] > array[i + 1])
					proverka = false;
			}
			Assert::IsTrue(proverka == true);
			delete[]array;
		}
		TEST_METHOD(TestCountingSort) {
			char* array = new char[6];
			array[0] = 'n'; array[1] = 'd'; array[2] = 's';
			array[3] = 'p'; array[4] = 'r'; array[5] = 'o';
			CountingSort(array, 6);
			Assert::IsTrue(array[0] == 'd');
			Assert::IsTrue(array[1] == 'n');
			Assert::IsTrue(array[2] == 'o');
			Assert::IsTrue(array[3] == 'p');
			Assert::IsTrue(array[4] == 'r');
			Assert::IsTrue(array[5] == 's');
			delete[]array;
		}
	};
}
