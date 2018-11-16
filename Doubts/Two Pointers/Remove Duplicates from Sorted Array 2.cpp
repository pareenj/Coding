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
    	if(j < 2 || i > A[j-2]) A[j++] = i;
    }  
    
    return j;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/
// http://qa.geeksforgeeks.org/3810/qa.geeksforgeeks.org/3810/remove-the-duplicates