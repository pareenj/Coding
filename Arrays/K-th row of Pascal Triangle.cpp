vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    int c = 1;
    if(A == 0)
    {
        ans.push_back(1);
        return ans;
    }
    
    for(int i = 0; i <= A; i++)
    {
        if(i == 0) c = 1;
        else c = c * (A - i + 1)/i;
        ans.push_back(c);
    }
}
