#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Selection Sort
vector<int> Solution::SelectionSort(vector<int> A) {

	int n = A.size();
	for(int i = 0; i < n-1; i++)
	{
		int min = A[i];
		int minIndex = i;
		for(int j = i+1; j < n; j++)
		{
			if(A[j] < min)
			{
				min = A[j];
				minIndex = j;
			}
		}
		int temp = A[i];
		A[i] = min;
		A[minIndex] = temp;
	}

	return A;
}

// Bubble Sort 
vector<int> Solution::BubbleSort(vector<int> A) {

	int n = A.size();

	for(int k = 0; k < n-1; k++)
	{
		int flag = 0;
		for(int i = 0; i < n-k-1; i++)
		{
			if(A[i+1] < A[i])
			{
				int temp = A[i];
				A[i+1] = A[i];
				A[i] = temp;

				flag = 1;
			}
		}
		if(flag == 0)
		{
			break;
		}
	}

	return A;
}

// Insertion Sort 1
vector<int> Solution::InsertionSort(vector<int> A) {

	int n = A.size();

	for(int i = 1; i < n-1; i++)
	{
		value = A[i];
		hole = i;

		while(hole > 0 && A[hole-1] > value)
		{
			A[hole-1] = A[hole];
			hole = hole-1;
		}

		A[hole] = value;
	}

	return A;
}

// Insertion Sort 2
vector<int> Solution::InsertionSort(vector<int> A) {

	int n = A.size();

	for(int i = 1; i < n; i++)
	{
		value = A[i];
		
		for(int j = i-1; j >= 0; j--)
		{
			if(A[j] > value)
			{
				A[j+1] = A[j];
				A[j] = value;
			}

			else
			{
				break;
			}
		}
	}

	return A;
}

// Merge Sort 1
void merge(vector<int> left, vector<int> right, vector<int> A) {

	int left_size = left.size();
	int right_size = right.size();

	int i = j = k = 0;

	while(i <= left_size && j <= right_size)
	{
		if(left[i] < right[j])
		{
			A[k++] = left[i++];
		}
		else
		{
			A[k++] = right[j++];
		}
	}

	while(i <= left_size)
	{
		A[k++] = left[i++];
	}

	while(j <= right_size)
	{
		A[k++] = right[j++];
	}
}

void Solution::MergeSort(vector<int> A) {

	int n = A.size();
	if(n < 2) return;
	int mid = n/2;

	vector<int> left(n/2);
	vector<int> right(n - mid);

	for(int i = 0; i < mid; i++)
		left[i] = A[i];
	for(int i = mid; i < n; i++)
		right[i - mid] = A[i];

	MergeSort(left);
	MergeSort(right);
	merge(left, right, A);
}

// Merge Sort 2
void merge(int left[], int right[], int A[], int low, int high)
{
	int i = j = 0;
	int k = low;

	int mid = low + (high - low)/2;

	while(i < mid - low && j <= high - mid)
	{
		if(left[i] < right[j])
		{
			A[k++] = left[i++];
		}
		else
		{
			A[k++] = right[j++];
		}
	}

	while(i < mid - low)
	{
		A[k++] = left[i++];
	}

	while(j < high - mid)
	{
		A[k++] = right[j++];
	}

}

void MergeSort(int A[], int low, int high)
{
	int mid = low + (high - low)/2;

	int left[], right[];

	for(int i = 0; i < mid; i++)
		left[i] = A[i];
	for(int i = mid; i < high; i++)
		right[i-mid] = A[i];

	MergeSort(left, low, mid);
	MergeSort(right, mid + 1, high);
	merge(left, right, A, low, high);
}

// Merge Sort 3
void merge(int *A, int *B, int *S, int m, int n)
{
	int i = j = k = 0;

	while(i < m && j < n)
	{
		if(A[i] < B[j])
		{
			S[k++] = A[i++];
		}
		else
		{
			S[k++] = B[j++];
		}
	}

	while(i < m)
	{
		S[k++] = A[i++];
	}

	while(j < n)
	{
		S[k++] = B[j++];
	}
}

void MergeSort(int *A, int n)
{
	if(n < 2) return;
	
	int *S = (int *)malloc(n * sizeof(int));
	int i = n/2;
	
	MergeSort(A, i);
	MergeSort(A+i, n-i);
	merge(A, A+i, S, i, n-i);
	
	for(int j = 0; j < n; j++)
		A[j] = S[j];
	
	free(S);
}

// Quick Sort
int partition(int *A, int start, int end)
{
	int pivot = A[end];
	int partitionIndex = start;

	for(int i = start; i < end-1; i++)
	{
		if(A[i] <= pivot)
		{
			int temp = A[partitionIndex];
			A[partitionIndex] = A[i];
			A[i] = temp;

			partitionIndex++;
		}
	}

	A[end] = A[partitionIndex]; 
	A[partitionIndex] = pivot;

	return partitionIndex;
}

void QuickSort(int *A, int start, int end)
{
	if(start < end)
	{
		int partitionIndex = partition(A, start, end);
		QuickSort(A, start, partitionIndex-1);
		QuickSort(A, partitionIndex+1, end);
	}
}


// Doubt: 3-way Quick Sort