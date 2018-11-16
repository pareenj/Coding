vector<int> Solution::lszero(vector<int> &A) {
	// Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> sum;
    int n = A.size();

    if(n == 0) return sum; // empty vector

    sum.push_back(A[0]);
    for(int i = 0; i < n-1; i++) sum.push_back(sum[i] + A[i+1]);

    int start = 0;
	int end = 0;
    map<int, int> hashMap;

    for(int i = 0; i < n; i++)
    {
    	if(sum[i] == 0)
    	{
    		int temp_start = 0, temp_end = i+1;
    		if(temp_end - temp_start >= end - start)
    		{
    			start = temp_start;
    			end = temp_end;
    		}
    	}
    	else
    	{
    		if(hashMap.find(sum[i]) != hashMap.end())
    		{
    			int temp_start = hashMap[sum[i]] + 1;
    			int temp_end = i+1;
    			if(temp_end - temp_start > end - start)
    			{
    				start = temp_start;
    				end = temp_end;
    			}
    			else if(temp_end - temp_start == end - start && temp_start < start)
    			{
    				start = temp_start;
    				end = temp_end;
    			}
    		}
    		else hashMap[sum[i]] = i;
    	}
    }

    vector<int> ans;
    for(int i = start; i < end; i++) ans.push_back(A[i]);

    return ans;
}

// http://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/

vector<int> Solution::lszero(vector<int> &A) {
	// Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> ans;
    unordered_map<int, int> hashMap;

    int sum = 0; // Initialize sum of elements
    int max_len = 0; // Initialize result

    int n = A.size();
    // Traverse through the given array
    for(int i = 0; i < n; i++)
    {
    	// Add current element to sum
    	sum += A[i];

    	if(A[i] == 0 && max_len == 0) max_len = 1;
    	if(sum == 0) max_len = i+1;

    	// Look this sum in hash table
    	int j = hashMap.find(sum);
    	if(j != hashMap.end()) max_len = max(max_len, i - j);
    	else hashMap.insert(sum, i);
    }

    return max_len;
}