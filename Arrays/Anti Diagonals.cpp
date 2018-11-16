vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {

	int n = A.size();
	vector<vector<int> > ans;

	for(int i = 0; i < n; i++)
	{
		vector<int> diag;
		for(int j = 0; j <= i; j++)
		{
			diag.push_back(A[j][i-j]);
		}
		ans.push_back(diag);
	}

	for(int i = 0; i < n-1; i++)
	{
		vector<int> diag;
		for(int j = n-1; j > i; j--)
		{
			diag.push_back(A[n+i-j][j]);
		}
		ans.push_back(diag);
	}

	return ans;
}

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    vector <vector<int> >v;
    
    for(int i=0;i<2*A[0].size()-1;i++){
        vector<int> temp;
        
        for(int k=0,j=i;k<2*A[0].size() && j>=0;k++,j--){
            if(k<A[0].size() && j>=0 && j<A[0].size())
                temp.push_back(A[k][j]);
        }
        
        v.push_back(temp);
    }
    
    return v;
}