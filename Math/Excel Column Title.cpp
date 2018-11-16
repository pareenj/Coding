string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    string ans = "";
    while(A > 0)
    {
    	int rem = A % 26;

    	if(rem == 0)
    	{
    		ans += 'Z';
    		A = A/26 - 1;
    	}
    	else
    	{
    		ans += (rem - 1) + 'A';
    		A = A/26;
    	}
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
