int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int low = 0, high = n-1, mid;
    while(low <= high)
    {
        mid = low + (high-low)/2;
        int next = (mid + 1) % n;
        int prev = (mid + n - 1) % n;
        if(A[low] <= A[high]) return A[low];
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])) return A[mid];
        else if(A[mid] <= A[high]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}