vector<vector<int> > Solution::prettyPrint(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = 2*A-1;
    vector<vector<int>> ans(n, vector<int>(n));

    int dir = 0;
    int left = 0, right = n-1, top = 0, bottom = n-1;
    
    LOOP: while(left <= right && top <= bottom)
    {
        //Left to Right
        for(int i = left; i <= right; i++)
        {
            ans[top][i] = A;
        }
        
        // Top to Bottom
        for(int i = top; i <= bottom; i++)
        {
            ans[i][right] = A;
        }
        
        // Right to Left
        for(int i = right; i >= left; i--)
        {
            ans[bottom][i] = A;
        }
        
        // Bottom to Top
        for(int i = bottom; i >= top; i--)
        {
            ans[i][left] = A;
        }
        
        A--;
        top++; bottom--; left++; right--;
        
    }
    
    return ans;
}