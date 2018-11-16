vector<int> Solution::prevSmaller(vector<int> &A) {

	int n = A.size();

	stack<int> s;

	for(int i = 0; i < n; i++)
	{
		int temp = A[i];
		while(!s.empty() && s.top() >= A[i]) s.pop();

		if(s.empty()) A[i] = -1;
		else A[i] = s.top();

		s.push(temp);
	}
	return A;
}

vector<int> Solution::prevSmaller(vector<int> &A) {

    if(A.size() == 0){
        return A;
    }
    
    vector<int> check(A.size(), 0);
    
    int smaller = A[0];
    
    for(int i = 0; i < A.size(); i++){
        if(A[i] <= smaller){
            check[i] = 1;
            smaller = A[i];
        }
    }
    
    vector<int> ans(A.size(), -1);
    
    int j = check.size()-1;
    
    for(int i = check.size()-1; i >= 0; i--){
        if(check[i] == 0){
            while(j >= i){
                j--;
            }
            while(j >= 0){
                if(A[i] > A[j]){
                    ans[i] = A[j];
                    break;
                }
                j--;
            }
            if(j != -1){
                j = i-1;
            }
        }
    }
    
    return ans;
}