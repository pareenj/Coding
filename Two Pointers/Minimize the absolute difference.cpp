int Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {

	int a = A.size(), b = B.size(), c = C.size();

	int minDiff = INT_MAX;

	int i = 0, j = 0, k = 0;
	while(i < a && j < b && k < c)
	{
		int minimum = min(A[i], min(B[j], C[k]));
		int maximum = max(A[i], max(B[j], C[k]));

		int currDiff = maximum - minimum;

		minDiff = min(currDiff, minDiff);

		if(A[i] == minimum) i++;
		else if(B[j] == minimum) j++;
		else k++;
	}

	return minDiff;
}

// http://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/