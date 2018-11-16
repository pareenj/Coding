int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.length();

    int start = 0, end = 0;
    int longest = 0;

    // Hash which tracks the count of each character in the current window. 
    // We need to make sure that for a solution, none of the 
    // character count / hash value exceeds 1.
    int hash[260];
    memset(hash, 0, sizeof(hash));

    while(start <= end && end < n)
    {
    	hash[A[end]]++;
    	if(hash[A[end]] > 1)
    	{
    		// pop stuff out of hash till the count becomes 1.
    		while(start <= end && (hash[A[end]] > 1))
    		{
    			hash[A[start]]--;
    			start++;
    		}
    	}
    	end++;
    	longest = max(longest, end - start);
    }
    return longest;
}

// https://leetcode.com/articles/longest-substring-without-repeating-characters/
// http://www.geeksforgeeks.org/length-of-the-longest-substring-without-repeating-characters/

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.length(), ans = 0;

    unordered_map<char, int> hashMap; // Current index of character

    // Try to extend the range [i, j]
    for(int j = 0, i = 0; j < n; j++)
    {
    	if(hashMap.find(A[j]) != hashMap.end())
    	{
    		i = max(hashMap[A[j]], i);
    	}
    	else
          	hashMap.insert({A[j], j + 1});

        ans = max(ans, j - i + 1);
    }
    return ans;
}

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.length(), ans = 0;

    unordered_map<char, int> hashMap; // Current index of character

    // Try to extend the range [i, j]
    for(int j = 0, i = 0; j < n; j++)
    {
        if(hashMap.find(A[j]) == hashMap.end())
        {
            hashMap[A[j]] = 0;
        }
        hashMap[A[j]]++;
        
        if(hashMap[A[j]] > 1)
        {
            while(i <= j && (hashMap[A[j]] > 1) )
            {
                hashMap[A[i]]--;
                i++;
            }
        }
        
        ans = max(ans, j - i + 1);
    }
    return ans;
}