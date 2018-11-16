int Solution::isValidSudoku(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    // int n = A.size();

    for(int i = 0; i < 9; i++)
    {
    	unordered_set<char> rows;
    	unordered_set<char> cols;
    	unordered_set<char> cube;

    	// string A_i = A[i];

    	// int n_i = A[i].size();
    	for(int j = 0; j < 9; j++)
    	{
    		if(A[i][j] != '.')
    		{
    			if(rows.find(A[i][j]) != rows.end()) return 0;
    			else rows.insert(A[i][j]);
    		}

    		if(A[j][i] != '.')
    		{
    			if(cols.find(A[j][i]) != cols.end()) return 0;
    			else cols.insert(A[j][i]);
    		}

    		int rowIndex = (3 * (i / 3)) + (j / 3);
    		int colIndex = (3 * (i % 3)) + (j % 3);
    		if(A[rowIndex][colIndex] != '.')
    		{
    			if(cube.find(A[rowIndex][colIndex]) != cube.end()) return 0;
    			else cube.insert(A[rowIndex][colIndex]);
    		}

    	}
    }
    return 1;
}