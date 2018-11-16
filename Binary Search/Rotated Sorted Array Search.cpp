int findPivot(const vector<int> &A)
{
    int n = A.size();
    int low = 0, high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        int next = (mid+1) % n;
        int prev = (mid+n-1) % n;
        if(A[low] <= A[high]) return low;
        else if((A[mid] <= A[prev]) && (A[mid] <= A[next])) return mid;
        else if(A[mid] <= A[high]) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int binarySearch(const vector<int> &A, int low, int high, int key)
{
    // if(high < low) return -1;
    // int mid = low + (high-low)/2;
    // if(A[mid] == key) return mid;
    // else if(A[mid] < key) return binarySearch(A, mid+1, high, key);
    // else return binarySearch(A, low, mid-1, key);
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(A[mid] == key) return mid;
        else if(A[mid] > key) high = mid-1;
        else low = mid+1;
    }
    return -1;
}

int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n = A.size();
    int pivot = findPivot(A);
    
    // if(pivot == -1) return binarySearch(A, 0, n-1, B);
    
    // if(A[pivot] == B) return pivot;
    // if(A[0] <= B) return binarySearch(A, 0, pivot-1, B);
    // else return binarySearch(A, pivot+1, n-1, B);
    
    if(A[pivot] == B) return pivot;
    int result = binarySearch(A, 0, pivot-1, B);
    if(result == -1) result = binarySearch(A, pivot+1, n-1, B);
    return result;
}

// http://www.geeksforgeeks.org/search-an-element-in-a-sorted-and-pivoted-array/