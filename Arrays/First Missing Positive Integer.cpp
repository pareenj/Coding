// void swap(int &x, int &y){
//     int temp = x;
//     x = y;
//     y = temp;
// }

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int shiftIndex = 0;
    int n = A.size();
    
    if(n == 1 && A[0] == 1) return 2;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] <= 0) swap(A[i], A[shiftIndex++]);
    }
    
    if(shiftIndex == n) return 1;
    
    for(int i = shiftIndex; i < n; i++)
    {
        if(abs(A[i]) + shiftIndex <= n && A[abs(A[i]) - 1 + shiftIndex] > 0) 
        A[abs(A[i]) - 1 + shiftIndex] *= -1;
    }
    
    for(int i = shiftIndex; i < n; i++)
    {
        if(A[i] > 0) return (i+1-shiftIndex);
    }
    
    return n + 1;
}
