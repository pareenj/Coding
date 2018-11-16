vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> >ans(A, vector<int>(A));
    
	 char dir;
	 int top, bottom, left, right;
	 int i, n = 1;
	 dir = 'R';
	 top = 0; bottom = A - 1;
	 left = 0; right = A - 1; 
	 
	 LOOP: while(left <= right && top <= bottom)
	 {
	     if(dir == 'R')
	     {
	         for(i = left; i <= right; i++)
	         {
	             ans[top][i] = n;
	             n++;
	         }
	         top++;
	         dir = 'D';
	         goto LOOP;
	     }
	     else if(dir == 'D')
	     {
	         for(i = top; i <= bottom; i++)
	         {
	             ans[i][right] = n;
	             n++;
	         }
	         right--;
	         dir = 'L';
	         goto LOOP;
	     }
	     else if(dir == 'L')
	     {
	         for(i = right; i >= left; i--)
	         {
	             ans[bottom][i] = n;
	             n++;
	         }
	         bottom--;
	         dir = 'U';
	         goto LOOP;
	     }
	     else if(dir == 'U')
	     {
	         for(i = bottom; i >= top; i--)
	         {
	             ans[i][left] = n;
	             n++;
	         }
	         left++;
	         dir = 'R';
	         goto LOOP;
	     }
	     
	 }
	 
	 return ans;
}
