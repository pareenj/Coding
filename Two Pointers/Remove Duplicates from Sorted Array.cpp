int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    if(n == 0 || n == 1) return n;

    int j = 0;
    for(int i = 0; i < n-1; i++)
    {
    	// If current element is not equal to next element then store that current element
    	if(A[i] != A[i+1]) A[j++] = A[i];

    	// while(i + 1 < A.size() && A[i] == A[i+1]) i++;
    }

    // Store the last element as whether it is unique or repeated, it hasn't stored previously
    A[j++] = A[n-1];
    
    return j;
}

// https://leetcode.com/articles/remove-duplicates-sorted-array/
// http://www.geeksforgeeks.org/remove-duplicates-sorted-array/