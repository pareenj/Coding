/* Returns a boolean which indicates whether any assigned entry
   in the specified row matches the given number. */
bool usedInRow(vector<vector<char> > &A, int row, int num)
{
	for(int col = 0; col < 9; col++)
	{
		if(A[row][col] == num + '0') return true;
	}
	return false;
}

/* Returns a boolean which indicates whether any assigned entry
   in the specified column matches the given number. */
bool usedInCol(vector<vector<char> > &A, int col, int num)
{
	for(int row = 0; row < 9; row++)
	{
		if(A[row][col] == num + '0') return true;
	}
	return false;
}

/* Returns a boolean which indicates whether any assigned entry
   within the specified 3x3 box matches the given number. */
bool usedInBox(vector<vector<char> > &A, int boxStartRow, int boxStartCol, int num)
{
	for(int row = 0; row < 3; row++)
	{
		for(int col = 0; col < 3; col++)
		{
			if(A[row + boxStartRow][col + boxStartCol] == num + '0') return true;
		}
	}
	return false;
}

/* Searches the grid to find an entry that is still empty. 
   If found, the reference parameters row, col will be set the location that is empty, and true is returned. 
   If no empty celss remain, false is returned. */
bool findEmptyCells(vector<vector<char> > &A, int &row, int &col)
{
	for(row = 0; row < 9; row++)
	{
		for(col = 0; col < 9; col++)
		{
			if(A[row][col] == '.') return true;
		}
	}
	return false;
}

/* Returns a boolean which indicates whether it will be legal to assign
   num to the given row,col location. */
bool isValid(vector<vector<char> > &A, int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
       current column and current 3x3 box */
	return !usedInRow(A, row, num) && !usedInCol(A, col, num) && !usedInBox(A, row - row % 3, col - col % 3, num);
}

bool solve(vector<vector<char> > &A)
{
	int size = 9;
    int row, col;

    // If there are no empty cells, then we are done
    if(!findEmptyCells(A, row, col)) return true;

    // Consider digits from 1 to 9
    for(int num = 1; num <= 9; num++)
    {
    	// If the number is valid in the position
    	if(isValid(A, row, col, num))
    	{
    		// Make tentative assignment
    		A[row][col] = num + '0';

    		// Return, if success
    		if(solve(A)) return true;

    		// If failure, unmake and try again
    		A[row][col] = '.';
    	}
    }
    return false;
}

void Solution::solveSudoku(vector<vector<char> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    solve(A);
}

// http://www.geeksforgeeks.org/backtracking-set-7-suduku/
// https://www.hackerearth.com/practice/notes/sudoku-solver-using-backtracking-2/

#define FOR(a,b) for(a=0;a<b;a++)
void initialize(bool *seen){
    int i;
    FOR(i,10)
        seen[i]=0;
}
bool validSudoko(int **arr,int row,int col){
    int i,j,n=9;
    bool seen[n+1];
    initialize(seen);
    FOR(i,n){   // checking in same row
        if(arr[row][i]>0 && seen[arr[row][i]])
            return 0;
        else if(arr[row][i]>0)
            seen[arr[row][i]]=1;
    }
    initialize(seen);  //checking in same column
    FOR(i,n){
        if(arr[i][col]>0 && seen[arr[i][col]])
            return 0;
        else if(arr[i][col]>0)
            seen[arr[i][col]]=1;
    }
    initialize(seen);
    int gridr=(int)row/3;
    int gridcol=(int)col/3;
    gridr*=3;
    gridcol*=3;
    FOR(i,3)    //check square
        FOR(j,3){
            if(arr[gridr+i][gridcol+j]>0 && seen[arr[gridr+i][gridcol+j]])
                return 0;
            else if(arr[gridr+i][gridcol+j]>0)
                seen[arr[gridr+i][gridcol+j]]=1;
        }
    return 1;
}
struct Pairs{
    int x,y;
};
Pairs setP(int a,int b){
    Pairs pair{a,b};
    return pair;
}
bool solve(int **a,vector<Pairs> &v,int i){
    if(i==v.size())
        return 1;
    int m=v[i].x,
        n=v[i].y,
        k;
    FOR(k,9){
        a[m][n]=k+1;
        if(validSudoko(a,m,n))
            if(solve(a,v,i+1))
                return 1;
        else a[m][n]=-1;
    }
    a[m][n]=-1;
    return 0;
}
void Solution::solveSudoku(vector<vector<char> > &A) {
    int n=9;
    int i,j;
    int **arr=new int *[n];
    vector<Pairs> v;
    FOR(i,n)
        arr[i]=new int[n];
    FOR(i,n)
        FOR(j,n){
            if(A[i][j]=='.'){
                arr[i][j]=-1;
                v.push_back(setP(i,j));
            }
            else arr[i][j]=A[i][j]-'0';
        }
    solve(arr,v,0);
    FOR(i,n)
        FOR(j,n)
            A[i][j]=arr[i][j]+'0';
}