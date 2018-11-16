bool isSafe(vector<string> &nQueens, int row, int col, int &A)
{
    //check if the column had a queen before.
	for (int i = 0; i != row; i++)
	{
		if(nQueens[i][col] == 'Q') return false;
	}
	
	//check if the 45° diagonal had a queen before.
	for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
	{
		if(nQueens[i][j] == 'Q') return false;
	}
	
	//check if the 135° diagonal had a queen before.
	for(int i = row - 1, j = col + 1; i >= 0 && j < A; i--, j++)
	{
		if(nQueens[i][j] == 'Q') return false;
	}

	return true;
}

void solveNQueensUtil(vector<vector<string>> &ans, vector<string> &nQueens, int row, int &A)
{
    /* base case: If all queens are placed then return true */
	if(row == A)
	{
		ans.push_back(nQueens);
		return;
	}
	
	/* Consider this row and try placing this queen in all columns one by one */
	for(int col = 0; col != A; col++)
	{
	    /* Check if queen can be placed on board[row][col] */
		if(isSafe(nQueens, row, col, A))
		{
		    /* Place this queen in board[row][col] */
			nQueens[row][col] = 'Q';
			
			/* recur to place rest of the queens */
			solveNQueensUtil(ans, nQueens, row + 1, A);
			
			/* If placing queen in board[row][col]
               doesn't lead to a solution, then
               remove queen from board[row][col] */
			nQueens[row][col] = '.'; // Backtrack
		}
	}
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<string>> ans;
	vector<string> nQueens(A, string(A, '.'));
	solveNQueensUtil(ans, nQueens, 0, A);
	return ans;
}

// https://www.youtube.com/watch?v=xouin83ebxE
// https://www.youtube.com/watch?v=0DeznFqrgAI
// https://www.youtube.com/watch?v=p4_QnaTIxkQ
// https://discuss.leetcode.com/topic/13617/accepted-4ms-c-solution-use-backtracking-and-bitmask-easy-understand
// http://www.geeksforgeeks.org/backtracking-set-3-n-queen-problem/