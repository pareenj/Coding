void generateSubsets(vector<int> &A, int start, vector<int> &subset, vector<vector<int> > &setOfSubsets)
{
	setOfSubsets.push_back(subset);
	int n = A.size();
	for(int i = start; i < n; i++)
	{
		if(i > start && A[i] == A[i-1]) continue; // skip duplicates
		subset.push_back(A[i]);
		generateSubsets(A, i+1, subset, setOfSubsets);
		subset.pop_back();
	}
}

// Recursive/Back Tracking
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
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