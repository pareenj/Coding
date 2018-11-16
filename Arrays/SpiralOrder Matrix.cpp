vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	// DO STUFF HERE AND POPULATE result
	
	int dir = 1;
	int m = A.size(), n = A[0].size();
	int top = 0, left = 0, bottom = m-1, right = n-1;
	
	while(left <= right && top <= bottom)
	{
		if(dir == 1)
		{
			for(int i = left; i <= right; i++) result.push_back(A[top][i]);
			top++;
			dir = 2;

			if(top > bottom || left > right) break;

		}
		else if(dir == 2)
		{
			for(int i = top; i <= bottom; i++) result.push_back(A[i][right]);
			right--;
			dir = 3;

			if(left > right || top > bottom) break;
		}
		else if(dir == 3)
		{
			for(int i = right; i >= left; i--) result.push_back(A[bottom][i]);
			bottom--;
			dir = 4;

			if(top > bottom || left > right) break;
		}
		else if(dir == 4)
		{
			for(int i = bottom; i >= top; i--) result.push_back(A[i][left]);
			left++;
			dir = 1;

			if(left > right || top > bottom) break;
		}
	}
	
	return result;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}