vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > ans(A);
    int c;
    
    for(int i = 0; i < A; i++)
    {
        c = 1;
        for(int j = 0; j <= i; j++)
        {
            if(j == 0) c = 1;
            else c = c * (i - j + 1) / j;
            ans[i].push_back(c);
        }
    }
    return ans;
}

vector<vector<int> > Solution::generate(int A) {

    vector<vector<int> > ans;

    if(A == 0) return ans;

    vector<int> row1;
    row1.push_back(1);
    ans.push_back(row1);

    if(A == 1) return ans;

    for(int i = 2; i <= A; i++)
    {
        vector<int> row;
        int ansSize = ans.size();
        row.push_back(1);

        vector<int> prevRow = ans[ansSize-1];
        int rowSize = prevRow.size();
        for(int j = 0; j < rowSize-1; j++)
        {
            row.push_back(prevRow[j] + prevRow[j+1]);
        }

        row.push_back(1);
        ans.push_back(row);
    }

    return ans;
}

vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> > ans;
            
    if (A <= 0) return ans;

    // 1st Row
    vector<int> row1; 
    row1.push_back(1);
    ans.push_back(row1);

    for (int i = 0; i < A - 1; i++) 
    {
        // New Row- Inserting 1 beginning
        vector<int> newRow;
        newRow.push_back(1);
        int newSize = ans[i].size();

        // New Row- Inserting Middle Elements
        for (int j = 0; j < newSize - 1; j++) 
        {
            newRow.push_back(ans[i][j] + ans[i][j + 1]);
        }

        // New Row- Inserting 1 ending
        newRow.push_back(1);
        ans.push_back(newRow);
    }
    return ans;
}