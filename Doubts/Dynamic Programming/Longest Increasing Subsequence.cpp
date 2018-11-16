int Solution::lis(const vector<int> &A) {

	int n = A.size();
	vector<int> LIS(n, 1);

	int lengthLIS = 0;

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(A[j] < A[i])
			{
				LIS[i] = max(LIS[j] + 1, LIS[i]);
			}
		}

		lengthLIS = max(lengthLIS, LIS[i]);
	}

	return lengthLIS;
}

// http://www.geeksforgeeks.org/longest-increasing-subsequence/
// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
void printLIS(vector<int>& arr)
{
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

vector<int> Solution::lis(const vector<int> &A) {

	int n = A.size();
	vector<vector<int> > LIS(n);

	LIS[0].push_back(A[0]);

	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if((A[i] > A[j]) && (LIS[i].size() < LIS[j].size() + 1))
				LIS[i] = LIS[j];
		}
		LIS[i].push_back(A[i]);
	}

	vector<int> max = LIS[0];
	for(vector<int> x: LIS)
		if(x.size() > max.size()) max = x;

	return max;

	// printLIS(max);
}

// http://www.geeksforgeeks.org/construction-of-longest-increasing-subsequence-using-dynamic-programming/
