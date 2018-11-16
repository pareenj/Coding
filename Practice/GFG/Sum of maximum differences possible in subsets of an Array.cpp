#include<bits/stdc++.h>
using namespace std;

int MaxMinDiff(vector<int> A)
{
	int n = A.size();

	sort(A.begin(), A.end());

	int maxSum = 0, minSum = 0;

	for(int i = 0; i < n; i++)
	{
		minSum = 2*minSum + A[i];
		maxSum = 2*maxSum + A[n-i-1];
	}

	return maxSum - minSum;

}

int main()
{
	vector<int> arr = {1, 2, 3, 4};
	cout << MaxMinDiff(arr);
	return 0;
}