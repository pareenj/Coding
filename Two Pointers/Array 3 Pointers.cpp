int Solution::minimize(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
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