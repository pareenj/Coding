vector<int> Solution::maxset(vector<int> &A) {

    int n = A.size();
    vector<int> ans;

    int currentLeft = 0, currentRight = 0;
    long currentSum = 0;
    int ansLeft = 0, ansRight = 0;
    long ansSum = INT_MIN;
    bool allNegative = true;

    for(int i = 0; i < n; i++)
    {
        if(A[i] >= 0)
        {
            allNegative = false;
            currentLeft = i;
            currentSum = 0;
            while(A[i] >= 0 && i < n)
            {
                currentSum += A[i];
                i++;
            }
            currentRight = i-1;
        }
        
        if(currentSum > ansSum)
        {
            ansLeft = currentLeft;
            ansRight = currentRight;
            ansSum = currentSum;
        }

        else if(ansSum == currentSum)
        {
            if(currentRight - currentLeft > ansRight - ansLeft)
            {
                ansLeft = currentLeft;
                ansRight = currentRight;
            }

            else if(currentRight - currentLeft == ansRight - ansLeft)
            {
                if(currentLeft < ansLeft)
                {
                    ansLeft = currentLeft;
                    ansRight = currentRight;
                }
            }
        }

        else
        {
//          currentLeft = i;
//          currentRight = i;
            currentSum = 0;
        }
    }

    if(allNegative) return ans;

    for(int i = ansLeft; i <= ansRight; i++)
    {
        ans.push_back(A[i]);
    }

    return ans;
}

vector<int> Solution::maxset(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i, n;
    n = A.size();
    
    if(n == 1 && A[0] >= 0) 
    {
        return A;
    }
    
    long int currentSum = 0, maxSum = 0;
    int currentLeftIndex = 0, currentRightIndex = 0, currentLength = 0;
    int ansLeftIndex = 0, ansRightIndex = 0, ansLength = 0;
    int negativeCount = 0;
    vector<int> ans;
    
    i = 0;
    LOOP: while(i < n)
    {
        if(A[i] >= 0)
        {
            currentSum = 0;
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
            i++;
            negativeCount++;
            if(negativeCount == n) return ans;
            goto LOOP;
        }
        i++;
    }
    
    for(int i = ansLeftIndex; i <= ansRightIndex; i++)
    {
        ans.push_back(A[i]);
    }
    return ans;
}