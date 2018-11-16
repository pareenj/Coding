/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int maxSubArray(const int* A, int n1) {
    if(n1 == 1) return A[0];
    int sum, mss, i;
    sum = 0; mss = A[0];
    for(i = 0; i < n1; i++)
    {
        sum = sum + A[i];
        if(sum < A[i]) sum = A[i];
        if(sum > mss) mss = sum; 
    }
    return mss;
}
