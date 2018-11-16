int Solution::braces(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    stack<char> S;

    int n = A.length();
    for(int i = 0; i < n; i++)
    {
    	while((i < n) && (A[i] == '(' || A[i] == '+' || A[i] == '*' || A[i] == '-' || A[i] == '/'))
    	{
    		S.push(A[i]);
    		i++;
    	}

    	if(A[i] == ')' )
    	{
    		if(!S.empty() && (S.top() == '(' )) return 1;
    		else
    		{
    			while(S.top() != '(') S.pop();
    			S.pop();
    		}
    	}
    }
    return 0;    
}