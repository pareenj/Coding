int Solution::removeDuplicates(vector<int> &A) {
    
    int n = A.size();
    
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(i < n - 2 && A[i] == A[i+1] && A[i] == A[i+2]) continue;
        else
        {
            A[j++] = A[i];
        }
    }
    
    return j;
}

int Solution::removeDuplicates(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    if(n == 0 || n == 1) return n;

    int j = 0;
    for(int i = 0; i < n; i++)
    {
        A[j++] = A[i];
        
        if(i < n-1 && A[j-1] == A[i+1]) A[j++] = A[i+1];
        
        while(i < n-1 && A[i] == A[i+1]) i++;
    }  
    
    return j;
}
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/discuss/
// http://qa.geeksforgeeks.org/3810/qa.geeksforgeeks.org/3810/remove-the-duplicates
