int Solution::mice(vector<int> &A, vector<int> &B) {

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int ans = INT_MIN;
	int n = A.size();

	for (int i = 0; i < n; ++i)
	{
		ans = max(ans, abs(A[i] - B[i]));
	}

	return ans;
}

// http://www.geeksforgeeks.org/assign-mice-holes/