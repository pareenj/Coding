void paranthesis(vector<string>&ans, string x, int open, int close, int A)
{
    if(open == A && close == A) ans.push_back(x);
    
    else
    {
        if(open < A) paranthesis(ans, x+"(", open + 1, close, A);       
        if(close < open) paranthesis(ans, x+")", open, close + 1, A);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<string> ans;
    paranthesis(ans, "", 0, 0, A);
    
    return ans;
}


// https://discuss.leetcode.com/topic/8724/easy-to-understand-java-backtracking-solution
// http://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
// https://discuss.leetcode.com/topic/4485/concise-recursive-c-solution