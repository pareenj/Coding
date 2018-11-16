vector<int> Solution::subUnsort(vector<int> &A) {

    int n = A.size();
    
    int firstLeft = n-1, firstRight = 0;
    
    for(int i = 1; i < n; i++)
    {
        if(A[i] < A[i-1])
        {
            firstLeft = i-1;
            break;
        }
    }
    
    vector<int> ans;
    if(firstLeft == n-1)
    {
        ans.push_back(-1);
        return ans;
    }
    
    // cout << 10 << endl;

    for(int i = n-1; i > 0; i--)
    {
        if(A[i] < A[i-1])
        {
            firstRight = i;
            break;
        }
    }

    int firstMin = INT_MAX, firstMax = INT_MIN;
    for(int i = firstLeft; i <= firstRight; i++)
    {
        firstMin = min(firstMin, A[i]);
        firstMax = max(firstMax, A[i]);
    }

    int secondLeft = firstLeft, secondRight = firstRight;
    for(int i = 0; i < firstLeft; i++)
    {
       if(A[i] > firstMin) 
        {
            secondLeft = i;
            break;
        }
    }
    for(int i = n-1; i > firstRight; i--)
    {
        if(A[i] < firstMax)
        {
            secondRight = i;
            break;
        }
    }

    ans.push_back(secondLeft); ans.push_back(secondRight);
    return ans;
}


vector<int> Solution::subUnsort(vector<int> &A) {
    
    int size = A.size();
    int left, right, max, min;
    vector<int> ans;
    
    for(left = 0; left < size - 1; left++)
    {
        if(A[left] > A[left+1]) break;
    }
    
    if(left == size - 1) 
    {
        ans.push_back(-1);
        return ans;
    }
    
    for(right = size - 1; right > 0; right--)
    {
        if(A[right] < A[right-1]) break;
    }
    
    max = A[left]; min = A[left];
    for(int i = left + 1; i <= right; i++)
    {
        if(A[i] > max) max = A[i];
        if(A[i] < min) min = A[i];
    }
    
    for(int i = 0; i < left; i++)
    {
        if(A[i] > min)
        {
            left = i;
            break;
        }
    }
    for(int i = size-1; i > right; i--)
    {
        if(A[i] < max)
        {
            right = i;
            break;
        }
    }
    
    //for(int i = left; i <= right; i++) ans.push_back(A[i]);
    ans.push_back(left); ans.push_back(right);
    return ans;
    
}

// http://www.geeksforgeeks.org/minimum-length-unsorted-subarray-sorting-which-makes-the-complete-array-sorted/