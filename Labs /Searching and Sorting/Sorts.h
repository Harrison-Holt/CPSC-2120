/*
 * Name: Harrison S. Holt 
 * Date Submitted: 2-20-23
 * Lab Section: 005
 * Assignment Name: Lab 4 
 */

// C++ Implementation of the Quick Sort Algorithm.
#pragma once 
#include <iostream>
#include <vector>
using namespace std; 

template<typename T>
void merge(vector<T>&data, int start, int end)
{
	int x, y, z, mid;
	vector<T> temp(end - start + 1);
	mid = (start + end) / 2;

	x = start;		// start index of first half [start, mid]
	y = mid + 1;	// start index of second half [mid+1, end]
	z = 0;			// start index of temp

	while (x <= mid && y <= end)
	{
		if (data[x] < data[y])
		{
			temp[z] = data[x];
			++x, ++z;
		}
		else
		{
			temp[z] = data[y];
			++y, ++z;
		}
	}

	while (x <= mid)
	{
		temp[z] = data[x];
		++x, ++z;
	}

	while (y <= end)
	{
		temp[z] = data[y];
		++y, ++z;
	}

	// write the merged sequence back to the original vector
	for (int i = start; i <= end; ++i)
	{
		data[i] = temp[i - start];
	}
}

// wrapper function that performs merge sort on vector (recursive)
template<typename T>
void mergeWrap(vector<T>&data, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;

	 // uses wrapper to perform operations
		mergeWrap(data, start, mid);
		mergeWrap(data, mid + 1, end);
    
    // merge the above 2 vectors 
		merge(data, start, end);   
	}
}

template <class T>
vector<T> mergeSort(vector<T> lst)
{
    std::vector<T> v = lst;
	mergeWrap(v, 0, v.size() - 1);
	return v;
}

template <typename T>
// swaps two elements
void swap(T* a, T* b) 	
{ 
        T t = *a; 
        *a = *b; 
        *b = t; 
} 

template <typename T>
int partition(vector<T> &data, int start, int end) {

	int pivot = end;
	int j = start;
	for (int i = start; i < end; ++i) {
		if (data[i] < data[pivot]) {
			swap(&data[i], &data[j]);
			++j;
		}
	}
	swap(&data[j], &data[pivot]);
	return j;
}

// wrapper function that performs quick sort on vector 
template <typename T>
void quickWrap(vector<T> &data, int start, int end ) {

	if (start < end) {
		int p = partition(data, start, end);
		quickWrap(data, start, p - 1);
		quickWrap(data, p + 1, end);
	}
}

template <class T>
vector<T> quickSort(std::vector<T> lst)
{
	vector<T> v = lst;
	quickWrap(v, 0, v.size() - 1);
	return v;
}
