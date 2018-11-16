vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();

    // Create an empty Hash to store mapping from sum to pair indexes
    unordered_map<int, pair<int, int> > hashMap;

    vector<int> ans;
    
    int count = 0;

    // Traverse through all possible pairs of A
    for(int i = 0; i < n-1	; i++)
    {
    	for(int j = i+1; j < n; j++)
    	{
    		// If sum of current pair is not in hash,
            // then store it and continue to next pair
    		int sum = A[i] + A[j];

    		if(hashMap.find(sum) == hashMap.end())
    		{
    			hashMap[sum] = make_pair(i, j);
    		}

    		else
    		{
    			vector <int> temp;
    			if(i == hashMap[sum].first || i == hashMap[sum].second || j == hashMap[sum].first || j == hashMap[sum].second)
    			{
    			    continue;
    			}
    			else
    			{
    			    temp.push_back(hashMap[sum].first);
    			    temp.push_back(hashMap[sum].second);
    			    temp.push_back(i);
    			    temp.push_back(j);
    			}
    			

    // 			for(int a = 0; a < temp.size() - 1; a++)
    // 			{
    // 				for(int b = a + 1; b < temp.size(); b++)
    // 				{
    // 					if(temp[a] == temp[b])
    // 					{
    // 						goto DOWN;
    // 					}
    // 				}
    // 			}

    			count++;
    			if(count == 1) ans = temp;
    			else
    			{
    				for(int c = 0; c < ans.size(); c++)
    				{
    					if(ans[c] > temp[c])
    					{
    						ans = temp;
    						break;
    					}
    					else if(ans[c] == temp[c]) continue;
    					break;
    				}
    			}
    // 			DOWN: temp.erase(temp.begin(), temp.end());
    		}
    	}
    }
    return ans;
}

// http://www.geeksforgeeks.org/find-four-elements-a-b-c-and-d-in-an-array-such-that-ab-cd/
