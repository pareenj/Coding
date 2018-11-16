vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    vector<int> ans;

    if(n < 2) return ans;

    unordered_map<int, int> hashMap;

    int index1 = 0, index2 = INT_MAX;
    int flag = 0;

    for(int i = 0; i < n; i++)
    {
    	int complement = B - A[i];

    	if(hashMap.find(complement) == hashMap.end())
    	{
    		hashMap.insert({A[i], i});
    	}

    	else
    	{
    		flag = 1; 
    		int tempIndex1 = hashMap[complement];
    		int tempIndex2 = i;

    		if(tempIndex2 < index2)
    		{
    			index2 = tempIndex2;
    			index1 = tempIndex1;
    		}
    		else if(tempIndex2 == index2)
    		{
    			if(tempIndex1 < index1)
    			{
    				index2 = tempIndex2;
    				index1 = tempIndex1;
    			}
    		}
    	}
    }

    if(flag)
    {
    	ans.push_back(index1 + 1);
    	ans.push_back(index2 + 1);
    }

    return ans;
}

// https://leetcode.com/problems/two-sum/solution/