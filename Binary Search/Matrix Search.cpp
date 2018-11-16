int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size(), m = A[0].size();
    int low = 0, high = n * m - 1;
    
    while(low <= high)
    {
        int mid = (low + high)/2;
        int midx = mid / m, midy = mid % m;
        
        if(A[midx][midy] == B) return 1;
        else if(A[midx][midy] > B) high = mid-1;
        else low = mid+1;
    }
    
    return 0;
}

// https://www.youtube.com/watch?v=0-rX-Wocuew
// http://www.geeksforgeeks.org/search-element-sorted-matrix/
// https://discuss.leetcode.com/topic/3227/don-t-treat-it-as-a-2d-matrix-just-treat-it-as-a-sorted-list
