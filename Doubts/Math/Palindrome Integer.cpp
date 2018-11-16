bool Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A < 0 || (A != 0 && A % 10 == 0)) return false;
    
    int rev = 0, num = A;
    while(num > rev)
    {
        rev = rev*10 + num % 10;
        num = num/10;
    }
    return (rev == num) || (rev/10 == num);
    
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

int reverse(int x) {
    int rev = 0, digit;
    while (x > 0) {
        digit = x%10;
        // check for overflow here
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) {
            return -1;
        }
        rev = rev * 10 + digit;
        x/=10;
    }
    return rev;
}

bool Solution::isPalindrome(int A) {
    if (A < 0) return false;
    // Lets try reversing x. If reverse overflows, 
    // then the number is not palindromic anyway. 
    return A == reverse(A);
}

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx

bool Solution::isPalindrome(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    //if(A < 0 || (A != 0 && A % 10 == 0)) return false;
    if (A < 0) return false;
    
    int rev = 0, num = A, digit;
    while(num > 0)
    {
        digit = num % 10;
        if (rev > (INT_MAX / 10) || (rev == (INT_MAX / 10) && digit > (INT_MAX % 10))) 
        {
            return -1;
        }
        rev = rev*10 + digit;
        num = num/10;
    }
    return (rev == A) || (rev/10 == A);
}

// http://www.geeksforgeeks.org/check-if-a-number-is-palindrome/