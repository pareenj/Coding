int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    vector<bool> boolArray(n);
    int min = A[0];
    int maxGap = -1;
    int i, j;
    i = j = n - 1;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] <= min) 
        {
            min = A[i];
            boolArray[i] = true;
        }
        else boolArray[i] = false;
    }
    
    LOOP: while(i >= 0)
    {
        if(boolArray[i] == false)
        {
            i--;
            goto LOOP;
        }
        
        while(A[i] > A[j] && j > i) j--;
        
        if((j - i) > maxGap) maxGap = j - i;
        
        i--;
    }
    
    return maxGap;
}

int Solution::maximumGap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    vector<int> LMin(n), RMax(n);

    /* Construct LMin[] such that LMin[i] stores the minimum value
       from (A[0], A[1], ... A[i]) */
    LMin[0] = A[0];
    for(int i = 1; i < n; i++) LMin[i] = min(A[i], LMin[i-1]);

    /* Construct RMax[] such that RMax[j] stores the maximum value
       from (A[j], A[j+1], ..A[n-1]) */
    RMax[n-1] = A[n-1];
    for (int j = n-2; j >= 0; j--) RMax[j] = max(A[j], RMax[j+1]);

    /* Traverse both arrays from left to right to find optimum j - i
        This process is similar to merge() of MergeSort */

    int maxGap = -1, i = 0, j = 0;
    while(i < n && j < n)
    {
        if(LMin[i] <= RMax[j])
        {
            maxGap = max(maxGap, j-i);
            j++;
        }
        else i++;
    }

    return maxGap;
}

// https://github.com/royalpranjal/Interview-Bit/blob/master/Arrays/MaxDistance.cpp
// http://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/