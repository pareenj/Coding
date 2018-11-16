// Minimum Swaps required to bring all elements less than equal K together

#include<bits/stdc++.h>
using namespace std;

int minSwaps(vector<int> A, int K)
{
	int n = A.size();
	int count = 0;

	for(int i = 0; i < n; i++)
	{
		if(A[i] <= K)
		{
			count++;
		}
	}

	int i = 0, j = 0;
	int minSwaps = 0;

	for(j = 0; j < count; j++)
	{
		if(A[j] > K)
		{
			minSwaps++;
		}
	}

	int swaps = minSwaps;
	while(j < n)
	{
		if(A[i] > K)
		{
			swaps--;
		}

		if(A[j+1] > K)
		{
			swaps++;
		}

		minSwaps = min(swaps, minSwaps);

		i++;
		j++;
	}

	return minSwaps;
}

int main()
{
	vector<int> arr = {2, 1, 5, 6, 3};
	int k = 3;
	cout << minSwaps(arr, k) << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Minimum number of swaps required for arranging pairs adjacent to each other

// https://www.geeksforgeeks.org/minimum-number-of-swaps-required-for-arranging-pairs-adjacent-to-each-other/


////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Wave Array

#include<bits/stdc++.h>
using namespace std;

vector<int> waveArray(vector<int> &A)
{
	int n = A.size();

	sort(A.begin(), A.end());

	for(int i = 1; i < n-1; i = i+2)
	{
		swap(A[i], A[i+1]);
	}

	return A;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	int n = A.size();
	A = waveArray(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

// Sort and array in Wave Form
// An array ‘arr[0..n-1]’ is sorted in wave form if arr[0] >= arr[1] <= arr[2] >= arr[3] <= arr[4] >= …..

#include<bits/stdc++.h>
using namespace std;

vector<int> waveArray(vector<int> &A)
{
	int n = A.size();

	for(int i = 0; i < n; i += 2)
	{
		if(i > 0 && A[i-1] > A[i])
		{
			swap(A[i], A[i-1]);
		}

		if(i < n-1 && A[i] < A[i+1])
		{
			swap(A[i], A[i+1]);
		}
	}

	return A;
}

int main()
{
	vector<int> A = {10, 90, 49, 2, 1, 5, 23};
	int n = A.size();
	A = waveArray(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange array such that even index elements are smaller and odd index elements are greater
#include<bits/stdc++.h>
using namespace std;

vector<int> waveRearrange(vector<int> A)
{
	int n = A.size();

	for(int i = 0; i < n - 1; i++)
	{
		if(i % 2 == 0 && A[i] > A[i+1])
		{
			swap(A[i], A[i+1]);
		}

		if(i % 2 != 0 && A[i] < A[i+1])
		{
			swap(A[i], A[i+1]);
		}
	}

	return A;
}

int main()
{
	vector<int> A = { 6, 4, 2, 1, 8, 3 };
	int n = A.size();
	A = waveRearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange array such that even positioned are greater than odd

#include<bits/stdc++.h>
using namespace std;

vector<int> waveArray(vector<int> A)
{
	int n = A.size();

	sort(A.begin(), A.end(), greater<int>());

	for(int i = 0; i < n-1; i = i+2)
	{
		swap(A[i], A[i+1]);
	}

	return A;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	int n = A.size();
	A = waveArray(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Rearrange array such that 1. arr[i] >= arr[j] if i is even & 2. arr[i] <= arr[j] if i is odd for j < i
#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &A)
{
	int n = A.size();
	vector<int> copy = A;
	sort(copy.begin(), copy.end());

	int evenCount = n/2, oddCount = n - evenCount;

	for(int i = oddCount-1, j = 0; i >= 0; i--, j += 2)
	{
		A[j] = copy[i];
	}

	for(int i = oddCount, j = 1; i < n; i++, j += 2)
	{
		A[j] = copy[i];
	}

	return A;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6, 7};
	int n = A.size();
	A = rearrange(A);

	for(int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	return 0;
}