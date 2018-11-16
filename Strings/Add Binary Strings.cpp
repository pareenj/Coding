string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    string ans = "";
    int digitSum = 0;

    int m = A.size() - 1, n = B.size() - 1;
    while(m >= 0 || j >= 0 || digitSum == 1)
    {
    	digitSum += ((m >= 0) ? A[m] - '0' : 0);
    	digitSum += ((n >= 0) ? B[n] - '0' : 0);

    	ans = char(digitSum % 2 + '0') + ans;

    	digitSum /= 2;

    	m--; n--;
    }

    return ans;
}
