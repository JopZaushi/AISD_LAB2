#pragma once
#include <iostream>
#include <ctime>
using namespace std;

//Generate Array
int* Generate_Array(int* array, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
	return array;
}

//BinarySearch
int BinarySearch(int* array, int elem, int size) {
	bool proverka = false, exception = false;
	int left = 0, right = size - 1, index;
	for (int i = 0; i < size; i++) {
		if (array[i] == elem)
			exception = true;
	}
	if (exception == true) {
		while (proverka != true) {
			if (array[(left + right) / 2] < elem) {
				left = (left + right) / 2; 
			}
			if (array[(left + right) / 2] > elem) {
				right = (left + right) / 2; 
			}
			if (array[(left + right) / 2] == elem)
				proverka = true;
		}
		index = ((left + right) / 2); //the returned index of the element
		return index;
	}
	else {
		throw invalid_argument("There is no such element in the array");
	}
}

//QuickSort
void QuickSort(int* array, int begin, int end) {
	int left = begin, right = end;
	int twin_elem;
	int pillar = (left + right + 1) / 2;
	while (left < right) {
		while (array[left] < array[pillar])
			left++;
		while (array[right] > array[pillar])
			right--;
		if (left <= right) {
			twin_elem = array[left];
			array[left] = array[right];
			array[right] = twin_elem;
			left++; right--;
		}
	}
	if (begin < right)
		QuickSort(array, begin, right);//recursion
	if (left < end)
		QuickSort(array, left, end);//recursion
}

//InsertionSort
void InsertionSort(int* array, int size) {
	int twin_elem, index;
	for (int i = 0; i < size - 1; i++) {
		twin_elem = array[i + 1];
		for (index = i; (index >= 0) && (array[index] > twin_elem); index--)
			array[index + 1] = array[index];
		array[index + 1] = twin_elem;
	}
}

//BogoSort
void BogoSort(int* array, int size) {
	int twin_elem, index = 0;
	do {
		if (array[index + 1] < array[index]) {
			twin_elem = array[index];
			array[index] = array[index + 1];
			array[index + 1] = twin_elem;
			index = 0;
		}
		else index++;

	} while (index != size - 1);
}

//CoutingSort
void CountingSort(char* array, int size) {
	char char_array[256] = { 0 };
	for (int i = 0; i < size; i++) {
		char_array[array[i]]++;
	}
	int index = 0;
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < char_array[i]; j++) {
			array[index] = i;
			index++;
		}
	}
}
