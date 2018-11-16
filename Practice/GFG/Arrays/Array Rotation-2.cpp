// Maximum Value of Sum(i*arr[i]) with only rotations allowed

#include<bits/stdc++.h>
using namespace std;

int maxSumRotated(vector<int> A)
{
	int n = A.size();

	int sum_0 = 0, arraySum = 0;

	for(int i = 0; i < n; i++)
	{
		sum_0 += (i * A[i]);
		arraySum += A[i];
	}

	int currentSum = sum_0, maxSum = sum_0;

	for(int i = 1; i < n; i++)
	{
		currentSum += arraySum - (n * A[n-i]);
		maxSum = max(maxSum, currentSum);
	}

	return maxSum;
}

int main()
{
	vector<int> arr = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << maxSumRotated(arr);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Find a rotation with Maximum Hamming Distance
#include<bits/stdc++.h>
using namespace std;

int maxHamming(vector<int> A)
{
	int n = A.size();
	int maxHamming = 0;

	for(int i = 1; i < n; i++)
	{
		int hammingDistance = 0;
		for(int j = 0; j < n; j++)
		{
			if(A[(i + j) % n] != A[j])
			{
				hammingDistance++;
			}
		}
		maxHamming = max(maxHamming, hammingDistance);
	}

	return maxHamming;
}

int main()
{
	vector<int> arr = {2, 4, 8, 0};
	cout << maxHamming(arr);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 3 types of queries on Left and Right Circular Shift on Array

#include<bits/stdc++.h>
using namespace std;

vector<int> rotateArray(vector<int> &A, int &netRotations)
{
	int n = A.size();
	vector<int> copy(2*n);

	for (int i = 0; i < n; ++i)
	{
		copy[i] = A[i];
		copy[i + n] = A[i];
	}
	
	if(netRotations > 0)
	{
		int r = n - (netRotations % n);
		for(int i = 0; i < n; i++)
		{
			A[i] = copy[r + i];
		}
	}

	else if(netRotations < 0)
	{
		int r = (-netRotations) % n;
		for(int i = 0; i < n; i++)
		{
			A[i] = copy[r + i];
		}
	}

	netRotations = 0;
	return A;
}

void processQueries(vector<int> &A, vector<vector<int> > queries)
{
	int n = A.size();
	int netRotations = 0; // Net Rotations in the Right Direction

	for(int i = 0; i < queries.size(); i++)
	{
		vector<int> query = queries[i];
		int queryType = query[0];

		if(queryType == 3)
		{
			vector<int> prefixSum(n);

			for(int i = 0; i < n; i++)
			{
				if(i == 0)
				{
					prefixSum[i] = A[i];
				}
				else
				{
					prefixSum[i] = prefixSum[i-1] + A[i];
				}
			}

			int left = query[1], right = query[2];
			cout << (prefixSum[right] - prefixSum[left-1]) << endl;
		}

		else if(queryType == 1)
		{
			netRotations += query[1];
			A = rotateArray(A, netRotations);

			for(int i = 0; i < n; i++)
			{
				cout << A[i] << " ";
			}

			cout << endl;
		}

		else
		{
			netRotations -= query[1];
			A = rotateArray(A, netRotations);

			for(int i = 0; i < n; i++)
			{
				cout << A[i] << " ";
			}

			cout << endl;
		}
	}
	
	// return netRotations;
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5};
	vector<vector<int> > queries;

	vector<int> query1 = {1, 3};
	vector<int> query2 = {3, 0, 2};
	vector<int> query3 = {2, 1};
	vector<int> query4 = {3, 1, 4};

	queries.push_back(query1);
	queries.push_back(query2);
	queries.push_back(query3);
	queries.push_back(query4);

	processQueries(A, queries);

	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Find element at given Index after given rotations

#include<bits/stdc++.h>
using namespace std;

int findElement(vector<int> A, vector<vector<int> > ranges, int index)
{
	int n = A.size();
	int rotations = ranges.size();

	int lastIndex = index;

	for(int i = rotations - 1; i >= 0; i--)
	{
		int left = ranges[i][0], right = ranges[i][1];

		if(lastIndex >= left && lastIndex <= right)
		{
			if(lastIndex == left)
			{
				lastIndex = right;
			}
			else
			{
				lastIndex--;
			}
		}
	}

	return A[lastIndex];
}

int main()
{
	vector<int> A = {1, 2, 3, 4, 5, 6};

	vector<vector<int> > ranges;

	vector<int> range1 = {0, 2};
	vector<int> range2 = {3, 4};
	vector<int> range3 = {1, 5};
	ranges.push_back(range1);
	ranges.push_back(range2);
	ranges.push_back(range3);

	int index = 1;

	cout << findElement(A, ranges, index);

	return 0;
}