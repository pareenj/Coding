int Solution::diffPossible(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    if(n == 0 || n == 1) return 0;

    int i = 0, j = 1;

    while((i < n) && (j < n))
    {
    	if(j == i)
    	{
    		j++;
    		continue;
    	}

    	int diff = A[j] - A[i];
    	if(diff == B) return 1;
    	else if (diff < B) j++;
    	else if(diff > B) i++;
    }
    
    return 0;
}

// http://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
