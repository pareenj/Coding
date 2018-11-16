// Count Occurrences of a Number in a Sorted Array

#include<bits/stdc++.h>
using namespace std;

int countOccurences(vector<int> A, int B)
{
	int n = A.size();
	// vector<int> ans(2);

	int low = 0, high = n - 1;
	int firstIndex;

	while(low <= high)
	{
		int mid = low + (high - low)/2;

		if(A[mid] == B)
		{
			firstIndex = mid;
			high = mid - 1; // Go on searching towards left (lower indices)
		}
		else if(A[mid] > B)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	// ans.push_back(firstIndex);

	low = 0;
	high = n - 1;
	int lastIndex;

	while(low <= high)
	{
		int mid = low + (high - low)/2;

		if(A[mid] == B)
		{
			lastIndex = mid;
			low = mid + 1; // Go on searching towards right (higher indices)
		}
		else if(A[mid] > B)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	// ans.push_back(lastIndex);
	// return ans;
	return (lastIndex - firstIndex + 1);
}

int main()
{
	vector<int> A = {1, 1, 3, 3, 5, 5, 5, 5, 5, 9, 9, 11};
	int B = 5;
	// vector<int> ans = firstLastBinarySearch(A, 5);
	// cout << ans[0] << " : " << ans[1];
	// cout << endl;
	int ans = countOccurences(A, B);
	cout << ans;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// How many times is a Soretd Array Rotated?
#include<bits/stdc++.h>
using namespace std;

int findRotationCount(vector<int> A)
{
	int n = A.size();

	int low = 0, high = n - 1;

	while(low <= high)
	{
		if(A[low] <= A[high])
		{
			return low;
		}

		int mid = low + (high - low)/2;
		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;

		if(A[mid] <= A[next] && A[mid] <= A[prev])
		{
			return mid;
		}

		else if(A[mid] <= A[high])
		{
			high = mid - 1;
		}

		else if(A[mid] >= A[low])
		{
			low = mid + 1;
		}
	}

	return -1;
}

int main()
{
	vector<int> A = {15, 22, 23, 28, 31, 38, 5, 6, 8, 10, 12};

	int count = findRotationCount(A);

	cout << count << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Search element in Circular Sorted Array
#include<bits/stdc++.h>
using namespace std;

int circularArraySearch(vector<int> A, int B)
{
	int n = A.size();

	int low = 0, high = n - 1;


	while(low <= high)
	{
		int mid = low + (high - low)/2;	

		if(A[mid] == B)
		{
			return mid;
		}

		else if(A[mid] <= A[high])
		{
			if(A[mid] < B && A[high] >= B)
			{
				low = mid + 1;
			}
			else
			{
				high = mid - 1;
			}
		}
		else if(A[mid] >= A[low])
		{
			if(A[mid] > B && A[low] <= B)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
	}

	return -1;
}

int main()
{
	vector<int> A = {12, 14, 18, 21, 3, 6, 8, 9};
	int B = 6;
	int index = circularArraySearch(A, B);

	cout << index << endl;

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Find number of pairs with a given sum in a sorted & rotated array
#include<bits/stdc++.h>
using namespace std;

int findMinIndex(vector<int> A)
{
	int n = A.size();

	int low = 0, high = n - 1;

	while(low <= high)
	{
		if(A[low] <= A[high])
		{
			return low;
		}

		int mid = low + (high - low)/2;
		int next = (mid + 1) % n;
		int prev = (mid + n - 1) % n;

		if(A[mid] <= A[next] && A[mid] <= A[prev])
		{
			return mid;
		}

		else if(A[mid] <= A[high])
		{
			high = mid - 1;
		}

		else if(A[mid] >= A[low])
		{
			low = mid + 1;
		}
	}

	return -1;
}

int pairInSortedRotated(vector<int> A, int sum)
{
	int n = A.size();
	int minIndex = findMinIndex(A);
	int maxIndex = (minIndex - 1 + n) % n;

	int count = 0;

	while(minIndex != maxIndex)
	{
		if(A[minIndex] + A[maxIndex] == sum)
		{
			cout << minIndex << " " << maxIndex << endl;
			count++;

			if(minIndex == (maxIndex - 1 + n) % n)
			{
				return count;
			}

			minIndex = (minIndex + 1) % n;
			maxIndex = (maxIndex - 1 + n) % n;
		}

		else if(A[minIndex] + A[maxIndex] > sum)
		{
			maxIndex = (maxIndex - 1 + n) % n;
		}

		else if(A[minIndex] + A[maxIndex] < sum)
		{
			minIndex = (minIndex + 1) % n;
		}
	}

	return count;
}

int main()
{
	vector<int> arr = {11, 15, 6, 7, 9, 10};
	int sum = 16;
	cout << pairInSortedRotated(arr, sum);

	return 0;
}