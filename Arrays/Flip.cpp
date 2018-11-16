vector<int> Solution::flip(string A) {

	int n = A.length();

	vector<int> ans;

	// int origZerosCount = 0;
	int currMaxDiff = 0, maxDiff = INT_MIN;
	int startIndex = 0, endIndex = 0, left = 0;

	for(int i = 0; i < n; i++)
	{
		int val = (A[i] == '1') ? 1 : -1;

		currMaxDiff += val;

		if(currMaxDiff > maxDiff)
		{
			maxDiff = currMaxDiff;
			startIndex = left;
			endIndex = i;
		}

		if(currMaxDiff < 0)
		{
			left = i + 1;
			currMaxDiff = 0;
		}

		// // Count of Zeros in Original Array
		// if(A[i] == 0) origZerosCount++;
	}

	if(maxDiff <= 0)
		return ans;
	else
	{
		ans.push_back(startIndex + 1);
		ans.push_back(endIndex + 1);
	}

	return ans;
}

// http://www.geeksforgeeks.org/maximize-number-0s-flipping-subarray/

#include<bits/stdc++.h>
using namespace std;

int findMaxZeroCount(vector<int> A)
{
	int n = A.size();

	int origZerosCount = 0; // Initialize count of 0s in original array
	int maxDiff = 0; // Initialize max_diff = maximum of (Count of 0s - count of 1s) for all subarrays.
	int currMaxDiff = 0;

	for(int i = 0; i < n; i++)
	{
		// Count of Zeros in Original Array
		if(A[i] == 0) origZerosCount++;

		int val = (A[i] == 1) ? 1 : -1;

		currMaxDiff = max(currMaxDiff + val, val);
		maxDiff = max(maxDiff, currMaxDiff);
	}

	maxDiff = max(0, maxDiff);

	return origZerosCount + maxDiff;
}

