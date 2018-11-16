int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(x == 0) return 0;
    if(n == 0) return 1 % d;
    if(d == 1) return 0;
    bool flag = false;
    if(x < 0)
    {
        x = abs(x);
        if(n % 2 != 0) flag = true;
    }
    
    long long int ans = 1, temp = x % d;
    
    while(n > 0)
    {
        if(n % 2 != 0) ans = ((ans % d) * (temp % d)) % d;
        temp = ((temp % d)*(temp % d)) % d;
        n = n/2;
    }
    
    if(flag) ans = d - ans;
    
    return ans;
}

// http://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-arithmetic/