#include "algorithms.h"

int main() {
	//Quick_Test
	int* quick_array = new int[10];
	cout << "Checking Quick Sort:" << endl;
	quick_array = Generate_Array(quick_array, 10);
	for (int i = 0; i < 10; i++)
		cout << quick_array[i] << " ";
	QuickSort(quick_array, 0, 10 - 1); cout << endl;
	for (int i = 0; i < 10; i++)
		cout << quick_array[i] << " ";
	delete[]quick_array;
	cout << endl << endl;

	//Insert_Test
	int* insert_array = new int[10];
	cout << "Checking Insertion Sort:" << endl;
	insert_array = Generate_Array(insert_array, 10);
	for (int i = 0; i < 10; i++)
		cout << insert_array[i] << " ";
	InsertionSort(insert_array, 10); cout << endl;
	for (int i = 0; i < 10; i++)
		cout << insert_array[i] << " ";
	delete[]insert_array;
	cout << endl << endl;

	//Bogo_Test
	int* bogo_array = new int[10];
	cout << "Checking Bogo Sort and Binary Search:" << endl;
	bogo_array = Generate_Array(bogo_array, 10);
	for (int i = 0; i < 10; i++)
		cout << bogo_array[i] << " ";
	BogoSort(bogo_array, 10); cout << endl;
	for (int i = 0; i < 10; i++)
		cout << bogo_array[i] << " ";
	try {
		BinarySearch(bogo_array, 42, 10);
	}
	catch (const invalid_argument error){
		cout << endl << "There is no such element in the array" << error.what();
	}
	try {
		cout << endl << "Index element: " << BinarySearch(bogo_array, 16, 10);
	}
	catch (const invalid_argument error) {
		cout << endl << "There is no such element in the array" << error.what();
	}
	BinarySearch(bogo_array, 16, 10);
	delete[]bogo_array;
	cout << endl << endl;

	//Couiting_Test
	char* char_array = new char[10];
	cout << "Checking Couting Sort:" << endl;
	for (int i = 0; i < 10; i++) {
		char_array[i] = rand() % 255;
		cout << char_array[i] << " ";
	}
	cout << endl;
	CountingSort(char_array, 10);
	for (int i = 0; i < 10; i++)
		cout << char_array[i] << " ";
	delete[]char_array;
	cout << endl << endl;


	//Checking the running time of QuickSort and InsertSort
	cout << "Checking the running time of QuickSort and InsertionSort" << endl;
	//QuickSort
	cout << "QuickSort";
	for (int i = 1; i < 6; i++) {
		int size = pow(10, i);
		int* first_array = new int[size];
		first_array = Generate_Array(first_array, size);
		long double first_seconds = 0;
		for (int i = 0; i < 10; i++) {
			clock_t begin = clock();
			QuickSort(first_array, 0, size - 1);
			clock_t end = clock();
			first_seconds += long double(end - begin) / CLOCKS_PER_SEC;
		}
		cout << endl << size << " elements " << first_seconds << " seconds";
		delete[]first_array;
	}
	cout << endl;
	//InsertSort
	cout << "InsertionSort";
	for (int i = 1; i < 6; i++) {
		int size = pow(10, i);
		int* second_array = new int[size];
		second_array = Generate_Array(second_array, size);
		long double first_seconds = 0;
		for (int i = 0; i < 10; i++) {
			clock_t begin = clock();
			InsertionSort(second_array, size);
			clock_t end = clock();
			first_seconds += long double(end - begin) / CLOCKS_PER_SEC;
		}
		cout << endl << size << " elements " << first_seconds << " seconds";
		delete[]second_array;
	}
	
	return 0;
}