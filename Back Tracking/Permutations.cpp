void swap(int *A, int *B)
{
	int temp = *B;
	*B = *A;
	*A = temp;
}

void permuteRecursive(vector<int> &A, int start, vector<vector<int> > &permutations)
{
	int n = A.size();
	if(start >= n)
	{
		permutations.push_back(A); // One permutation instance
		return;
	}

	for(int i = start; i < n; i++)
	{
		swap(A[start], A[i]);
		permuteRecursive(A, start + 1, permutations);

		// Reset
		swap(A[start], A[i]);
	}
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > permutations;
    permuteRecursive(A, 0, permutations);
    return permutations;
}

// https://discuss.leetcode.com/topic/5881/my-elegant-recursive-c-solution-with-inline-explanation
// http://xiaohuiliucuriosity.blogspot.in/2014/12/permutations.html
// http://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
// https://www.youtube.com/watch?v=AfxHGNRtFac
// https://www.youtube.com/watch?v=nYFd7VHKyWQ