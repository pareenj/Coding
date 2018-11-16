void combSum(vector<vector<int> > &ans, vector<int> &row, vector<int> &A, int B, int start)
{
	int n = A.size();
	if(B < 0 || start == n) return;
	else if(B == 0) 
	{
		ans.push_back(row);
		return;
	}
	else
	{
		for(int i = start; i < n; i++)
		{
			row.push_back(A[i]);
			combSum(ans, row, A, B - A[i], i);
			row.pop_back();
		}
		// if(start)
		// row.push_back(A[start]);
		// combSum(ans, row, A, B - A[start], start);
		// row.pop_back();
		// combSum(ans, row, A, B, start + 1);
	}
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B) {

	sort(A.begin(), A.end());
	vector<vector<int> > ans;
	vector<int> row;
	
	vector<int> a;
	a.push_back(A[0]);
	for(int i = 1; i < A.size(); i++)
	{
	    if(A[i] != a[a.size() - 1]) a.push_back(A[i]);
	}

	combSum(ans, row, a, B, 0);
	return ans;
}

// https://discuss.leetcode.com/topic/46159/a-general-approach-to-backtracking-questions-in-java-subsets-permutations-combination-sum-palindrome-partitioning/2