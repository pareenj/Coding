string Solution::findDigitsInBinary(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A == 0) return "0";
    
    string rem;
    string ans = "";
    
    while(A > 0)
    {
        rem = to_string(A % 2);
        A = A/2;
        ans = ans + rem;
    }
    
    int size = ans.size();
    for(int i = 0; i < size/2; i++)
    {
        char temp = ans[i];
        ans[i] = ans[size - 1 - i];
        ans[size - 1 - i] = temp;
    }
    
    return ans;
    
}