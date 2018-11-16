int BinarySearch(const vector<int> &A, int B, bool searchFirst)
{
    int n = A.size();
    int low = 0, high = n-1, result = -1;
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(A[mid] == B)
        {
            result = mid;
            if(searchFirst) high = mid-1;
            else low = mid + 1;
        }
        else if(A[mid] < B) low = mid+1;
        else high = mid-1;
    }
    return result;
}

int Solution::findCount(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int firstIndex = BinarySearch(A, B, true);
    if(firstIndex == -1) return 0;
    else
    {
        int lastIndex = BinarySearch(A, B, false);
        return (lastIndex - firstIndex + 1);
    }

}
