int Solution::removeElement(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    
    int i = 0;
    for(int j = 0; j < n; j++)
    {
        if(A[j] != B)
        {
            A[i] = A[j];
            i++;
        }
    }
    return i;
    
    // int i = 0;
    // while(i < n)
    // {
    // 	if(A[i] == B) 
    // 	{
    // 		A[i] = A[n-1];
    // 		n--;
    // 	}
    // 	else 
    // 	{
    // 	    i++;
    // 	}

    // }
    // return n;

    // int i = 0;
    // for(int i = 0; i < n; i++)
    // {
    // 	if(A[i] == B) 
    // 	{
    // 		A[i] = A[n-1];
    // 		n--;
    // 	}
    // }
    // return n;
}

// https://leetcode.com/articles/remove-element/
