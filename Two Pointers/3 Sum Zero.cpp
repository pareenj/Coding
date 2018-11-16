vector<vector<int> > Solution::threeSum(vector<int> &A) {

    vector<vector<int> >ans;
    sort(A.begin(), A.end());
    int n = A.size();

    for(int i = 0; i < n-1; i++)
    {
        unordered_set<int> hashSet;
        for(int j = i+1; j < n; j++)
        {
            int Ak = A[i] + A[j];
            if(hashSet.find(-Ak) != hashSet.end())
            {
                vector<int> vec;
                vec.push_back(A[i]); vec.push_back(A[j]); vec.push_back(-Ak);
                sort(vec.begin(), vec.end());
                ans.push_back(vec);
            }
            else
            {
                hashSet.insert(A[j]);
            }
        }
    }

    unique(ans.begin(), ans.end());
    return ans;
}

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > sol;
    int n = A.size();
    
    if(n < 2){
        return sol;
    }
    
    sort(A.begin(), A.end()); 

    for(int i = 0; i < n-1; i++)
    {
    	int left = i+1, right = n-1;
    	int x = A[i];
    	while(left < right)
    	{
    		int sum = x + A[left] + A[right];
    		if(sum == 0)
    		{
    			vector<int> temp;
    			temp.push_back(A[i]); temp.push_back(A[left]); temp.push_back(A[right]);
    			sol.push_back(temp);

    			while(A[left] == A[left + 1])
    			{
    				left++;
    				if(left == n) break;
    			}
    			while(A[right] == A[right - 1])
    			{
    				right--;
    				if(right == -1) break;
    			}
    			left++;
    			right--;
    		}
    		else if(sum < 0)
    		{
    			while(A[left] == A[left + 1])
    			{
    				left++;
    				if(left == n) break;
    			}
    			left++;
    		}
    		else
    		{
    			while(A[right] == A[right - 1])
    			{
    				right--;
    				if(right == -1) break;
    			}
    			right--;
    		}
    	}
    	while(A[i+1] == A[i])
    	{
    		i++;
    		if(i == n-1) return sol;
    	}
    }
    return sol;
}

// http://www.geeksforgeeks.org/find-triplets-array-whose-sum-equal-zero/