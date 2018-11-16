int Solution::gcd(int A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(B < A)
    {
        int temp = A;
        A = B;
        B = temp;
    }
    
    if(A != 0 && B % A == 0) return A;
    
    while(A != 0)
    {
        int temp = B;
        B = A;
        A = temp % A;
    }
    
    return B;
}

int Solution::gcd(int m, int n) {
    if(m < n)
        swap(m, n);
        
    if(n == 0)
        return m;

    return gcd(m % n, n);
}