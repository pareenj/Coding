string Solution::reverseString(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    stack<char> S;
    int n = A.length();
    
    // Loop for Push
	for(int i = 0; i < n; i++) S.push(A[i]);
	
	// Loop for Pop
	for(int i = 0; i < n; i++)
	{
		A[i] = S.top();
		S.pop();
	}
    
    return A;
}