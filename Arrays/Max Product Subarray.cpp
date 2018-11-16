int Solution::maxProductSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int maxProd = 1;
    int currMax = 1; // max positive product ending at the current position
    int currMin = 1; // min negative product ending at the current position

    for(int i = 0; i < A.size(); i++)
    {
        if(A[i] > 0)
        {
            currMax = currMax * A[i];
            currMin = min(currMin * A[i], 1); // Update currMin only if currMin is negative
        }

        else if(A[i] == 0)
        {
            currMax = 1;
            currMin = 1;
        }

        else
        {
            int temp = currMax;
            currMax = max(currMin * A[i], 1);
            currMin = temp * A[i];
        }

        if(maxProd < currMax) maxProd = currMax;
    }

    return maxProd;
}