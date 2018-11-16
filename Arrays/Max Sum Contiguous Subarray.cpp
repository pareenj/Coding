int Solution::maxSubArray(const vector<int> &A) {

    int n = A.size();
    int currentSum = 0, maxSum = INT_MIN;

    for(int i = 0; i < n; i++)
    {
        currentSum += A[i];
        maxSum = max(currentSum, maxSum);
        if(currentSum < 0) currentSum = 0;
    }

    return maxSum;
}

int Solution::maxSubArray(const vector<int> &A) {

    int n = A.size();
    int currentSum = 0, maxSum = INT_MIN;
    int startIndex = 0, endIndex = 0;
    int left = 0;

    for(int i = 0; i < n; i++)
    {
        currentSum += A[i];

        if(currentSum > maxsum)
        {
            maxsum = currentSum;
            startIndex = left;
            endIndex = i+1;
        }

        if(currentSum < 0) 
        {
            currentSum = 0;
            left = i+1;
        }
    }

    return maxSum;
}

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int maxsum = INT_MIN;
    int currentsum = 0;
    //int maxval = INT_MIN;
    
    for(int i = 0; i < A.size(); i++) {
        //maxval = max(maxval, A[i]);
        currentsum += A[i];
        maxsum = max(currentsum, maxsum);
        if(currentsum < 0) {
            currentsum = 0;
        }
    }
    
    // return max(maxval, maxsum);
    return maxsum;
}

/*

int Solution::maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    if(n == 1) return A[0];
    int currentSum = 0, maxSum = 0;
    int currentLeftIndex = 0, currentRightIndex = 0, currentLength = 0;
    int ansLeftIndex = 0, ansRightIndex = 0, ansLength = 0;
    
    for(int i = 0; i < n; i++)
    {
        if(A[i] >= 0)
        {
            currentLeftIndex = i;
            while(A[i] >= 0 && i < n)
            {
                currentSum = currentSum + A[i];
                i++;
            }
            currentRightIndex = i - 1;
            currentLength = currentRightIndex - currentLeftIndex + 1;
            
            if(currentSum > maxSum)
            {
                maxSum = currentSum;
                ansLeftIndex = currentLeftIndex;
                ansRightIndex = currentRightIndex;
                ansLength = currentLength;
            }
            
            else if(currentSum == maxSum)
            {
                if(currentLength > ansLength)
                {
                    ansLeftIndex = currentLeftIndex;
                    ansRightIndex = currentRightIndex;
                    ansLength = currentLength;
                }
                else if(currentLength == ansLength)
                {
                    if(A[currentLeftIndex] < A[ansLeftIndex])
                    {
                        ansLeftIndex = currentLeftIndex;
                        ansRightIndex = currentRightIndex;
                        ansLength = currentLength;
                    }
                }
            }
        }
        else
        {
            currentSum = 0;
            continue;
        }
    }
    
    return maxSum;
    
    // vector<int> ans;
    // for(int i = ansLeftIndex; i <= ansRightIndex; i++)
    // {
    //     ans.push_back(A[i]);
    // }
    // return ans;
}

*/