#define MOD 10000003

int Solution::seats(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    int count = 0;

    for(int i = 0; i < n; i++)
    {
    	if(A[i] == 'x') count++;
    }

    if(count == 0 || count == 1) return 0;

    int medianIndex = 0;
    for(int i = 0; i < n; i++)
    {
    	if(A[i] == 'x')
    	{
    		medianIndex++;
    		if(medianIndex == (count/2)+1)
    		{
    			medianIndex = i;
    			break;
    		}
    	}
    }

    long long int left = medianIndex - 1, right = medianIndex + 1;
    long long int hops = 0;

    while(A[left] == 'x')
    {
    	left--;
    	if(A[left] == '.')
    		break;
    }

    while(A[right] == 'x')
    {
    	right++;
    	if(A[right] == '.')
    		break;
    }

    for(long long int i = left; i >= 0; i--)
    {
    	if(A[i] == 'x')
    	{
    		hops += left - i;
    		left--;
    	}
    }

    for(long long int i = right; i < n; i++)
    {
    	if(A[i] == 'x')
    	{
    		hops += i - right;
    		right++;
    	}
    }

    return (int)(hops % MOD);

}

// https://discuss.leetcode.com/topic/25877/minimum-number-of-jumps/4
// http://qa.geeksforgeeks.org/4088/what-are-the-total-number-minimum-hops-jumps-for-arrangement
// https://leetcode.com/articles/consecutive-available-seats/
// http://www.geeksforgeeks.org/minimum-number-of-swaps-required-for-arranging-pairs-adjacent-to-each-other/