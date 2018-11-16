string longestcommonprefix(string A, string B)
{
    string ans = "";
    
    int n = A.length(), m = B.length();
    
    for(int i = 0, j = 0; (i < n && j < m) && (A[i] == B[j]); i++, j++) ans += A[i];
    
    return ans;
}

string Solution::longestCommonPrefix(vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    string ans = A[0];
    
    for(int i = 1; i < n; i++) ans = longestcommonprefix(ans, A[i]);
    
    return ans;
}
