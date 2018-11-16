int Solution::majorityElement(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int ans = A[0];
    int count = 1;
    int n = A.size();

    for(int i = 0; i < n; i++)
    {
    	if(A[i] == ans) count++;
    	else count--;

    	if(count == 0)
    	{
    		ans = A[i];
    		count = 1;
    	}
    }

    return ans;
}

// http://www.geeksforgeeks.org/majority-element/
// https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations