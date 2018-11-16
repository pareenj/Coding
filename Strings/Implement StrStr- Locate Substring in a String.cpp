int Solution::strStr(const string &haystack, const string &needle) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int m = haystack.length(), n = needle.length();
    if(n == 0) return -1;
    
    for(int i = 0; i < m - n + 1; i++)
    {
        int j = 0;
        while(j < n)
        {
            if(haystack[i+j] != needle[j]) break;
            j++;
        }
        if(j == n) return i;
    }
    return -1;
}

// https://www.youtube.com/watch?v=GTJr8OvyEVQ
// https://www.youtube.com/watch?v=KG44VoDtsAA
// https://discuss.leetcode.com/topic/15569/explained-4ms-easy-c-solution
