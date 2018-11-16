bool Larger(int A, int B)
{
    if(A > B) return true;
    return false;
}

void Solution::merge(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = B.size();
    int i = 0, j = 0;

    while((i < A.size()) && (j < n))
    {
    	bool a = Larger(A[i], B[j]);

    	if(a)
    	{
    		A.insert(A.begin()+i, B[j]);
    		i++; j++;
    	}
    	else i++;
    }
    while(j != n)
    {
    	A.push_back(B[j]);
    	j++;
    }
    
    // int m = A.size(), n = B.size();
    // for(int i = n-1; i >= 0; i--)
    // {
    //     /* Find the smallest element greater than ar2[i]. Move all
    //       elements one position ahead till the smallest greater
    //       element is not found */
    //     int j, last = A[m-1];
    //     for(j = m-2; j >= 0 && A[j] > B[i]; j--) A[j+1] = A[j];
        
    //     // If there was a greater element
    //     if(j != m-2 || last > B[i])
    //     {
    //         A[j+1] = B[i];
    //         B[i] = last;
    //     }
    // }
}

// http://www.geeksforgeeks.org/merge-two-sorted-arrays-o1-extra-space/