vector<int> Solution::findPerm(const string A, int B) {

	vector<int> ans(B);
	ans[0] = 1;
	
	int i = 1;
	while(i < B)
	{
		ans[i] = i+1;
		int j = i;
		if(A[i-1] == 'D')
		{
			while(i < B && A[i-1] == 'D')
				i++;
			for(int k = j-1, c = i; k <= i-1; k++, c--)
				ans[k] = c;
		}
		else
			i++;
	}

	return ans;
}

// https://leetcode.com/articles/find-permutation/

vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans(B);
	for(int i = 0; i < B; i++)
	{
		ans[i] = i + 1;
	}

	int i = 1;
	while(i < B)
	{
		int j = i;
		while(i < B && A[i-1] == 'D')
			i++;
		reverse(ans.begin() + j - 1, ans.begin() + i);
		i++;
	}

	return ans;
}