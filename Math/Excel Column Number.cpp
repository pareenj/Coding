int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans = 0;
    int multiplier = 1;
    int length = A.length();
    for(int i = length - 1; i >= 0; i--)
    {
        ans += (A[i] - 'A' + 1)*multiplier;
        multiplier *= 26;
    }
    return ans;
}
