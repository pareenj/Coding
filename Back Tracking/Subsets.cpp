void generateSubsets(vector<int> &A, int start, vector<int> &subset, vector<vector<int> > &setOfSubsets)
{
	setOfSubsets.push_back(subset);
	int n = A.size();
	for(int i = start; i < n; i++)
	{
		subset.push_back(A[i]);
		generateSubsets(A, i+1, subset, setOfSubsets);
		subset.pop_back();
	}
}

// Recursive/Back Tracking
vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());
	
	vector<vector<int> > setOfSubsets;
	vector<int> subset;

	generateSubsets(A, 0, subset, setOfSubsets);

	return setOfSubsets;
}

// Iterative
vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());
	
	vector<vector<int> > setOfSubsets(1, vector<int>());

	int n = A.size();
	for (int i = 0; i < n; i++)
	{
		int m = setOfSubsets.size();
		for (int j = 0; j < m; j++)
		{
			setOfSubsets.push_back(setOfSubsets[j]);
			setOfSubsets.back().push_back(A[i]);
		}
	}

	return setOfSubsets;
}

// Bit Manipulation
vector<vector<int> > Solution::subsets(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    sort(A.begin(), A.end());

    int n = A.size();
    int size = pow(2, n);

    vector<vector<int> > setOfSubsets(size, vector<int>());
    for(int i = 0; i < n; i++)
    {
    	for(int j = 0; j < size; j++)
    	{
    		if((j >> i) & 1) setOfSubsets[j].push_back(A[i]);
    	}
    }
    return setOfSubsets;
}

// https://discuss.leetcode.com/topic/46159/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning
// https://discuss.leetcode.com/topic/19110/c-recursive-iterative-bit-manipulation-solutions-with-explanations
// http://www.geeksforgeeks.org/power-set/
// http://www.geeksforgeeks.org/find-distinct-subsets-given-set/
// https://gist.github.com/pdu/4595053