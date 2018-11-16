// https://www.interviewbit.com/problems/generate-all-parentheses/

bool ArePair(char opening, char closing)
{
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;
}

int Solution::isValid(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> S;
    int n = A.length();
    for(int i = 0; i < n; i++)
    {
        if(A[i] == '(' || A[i] == '{' || A[i] == '[') S.push(A[i]);
        else if(A[i] == ')' || A[i] == '}' || A[i] == ']')
        {
            if(S.empty() || !ArePair(S.top(), A[i])) return 0;
            else S.pop();
        }
    }
    return S.empty() ? 1 : 0;
}