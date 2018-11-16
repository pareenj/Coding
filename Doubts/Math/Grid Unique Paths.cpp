int Solution::uniquePaths(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int ans = 1, minval = min(A, B);
    
    for(int i = 1; i < minval; i++) ans = (ans * (A+B-2 - (i-1)))/i;
    
    return ans;
}

// https://leetcode.com/problems/unique-paths/#/solutions
// http://qa.geeksforgeeks.org/3676/number-of-unique-paths
// http://www.geeksforgeeks.org/count-possible-paths-top-left-bottom-right-nxm-matrix/
