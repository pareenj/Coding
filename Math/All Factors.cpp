vector<int> Solution::allFactors(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A < 2)
    {
        vector<int> ans;
        ans.push_back(A);
        return ans;
    }
    
    int length = 2;
    for(int i = 2; i <= sqrt(A); i++)
    {
        if(A % i == 0)
        {
            length++;
            if(A/i != i) length++;
        }
    }
    
    vector<int> ans(length);
    ans[0] = 1; ans[length - 1] = A;
    
    int index = 1;
    for(int i = 2; i <= sqrt(A); i++)
    {
        if(A % i == 0)
        {
            ans[index++] = i;
            if(A/i != i) ans[length - index] = A/i;
        }
    }
    
    return ans;
}

vector<int> Solution::allFactors(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<int> ans;
    
    if(A < 2)
    {
        ans.push_back(A);
        return ans;
    }
    
    ans.push_back(1); ans.push_back(A);
    
    for(int i = 2; i <= sqrt(A); i++)
    {
        if(A % i == 0)
        {
            ans.push_back(i);
            if(A/i != i) ans.push_back(A/i);
        }
    }
    
    sort(ans.begin(), ans.end());
    return ans;
}