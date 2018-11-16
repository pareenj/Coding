void combinations(vector<int> &row, vector<vector<int> > &ans, int i, int n, int k)
{
	if(k == 0) 
	{
		ans.push_back(row);
		return;
	}

	if(i == n) return;

	for(int j = i; j < n; j++)
	{
		row.push_back(j+1);
		combinations(row, ans, j+1, n, k-1);
		row.pop_back();
	}
}

vector<vector<int> > Solution::combine(int n, int k) {

	vector<vector<int> > ans;
	vector<int> row;
	combinations(row, ans, 0, n, k);
	return ans;
}

// http://www.geeksforgeeks.org/print-all-possible-combinations-of-r-elements-in-a-given-array-of-size-n/