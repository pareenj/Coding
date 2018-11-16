////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Heap Sort

#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &A, int toIndex, int fromIndex)
{
	int larger = fromIndex;
	int leftChild = (2*fromIndex) + 1;
	int rightChild = (2*fromIndex) + 2;

	if(leftChild < toIndex && A[leftChild] > A[larger])
	{
		larger = leftChild;
	}
	if(rightChild < toIndex && A[rightChild] > A[larger])
	{
		larger = rightChild;
	}

	if(larger != fromIndex)
	{
		swap(A[larger], A[fromIndex]);

		heapify(A, toIndex, larger);
	}
}

vector<int> heapSort(vector<int> &A)
{
	int n = A.size();

	for(int i = n/2 - 1; i >= 0; i--) // Because A[n/2, n/2 + 1, ..., n] are all leaf nodes
	{
		heapify(A, n, i);
	}

	for(int i = n-1; i >= 0; i--)
	{
		swap(A[i], A[0]);
		heapify(A, i, 0);
	}

	return A;
}

int main()
{
	vector<int> A= {12, 13, 6, 4, 5, 15, 1, 19};
	int n = A.size();
	A = heapSort(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}