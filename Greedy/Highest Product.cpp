// https://www.interviewbit.com/problems/highest-product/

int Solution::maxp3(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();

	// If size is less than 3, no triplet exists
    if(n < 3) return -1;

    // Initialize Maximum, Second Maximum, and Third Maximum Elements
    int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
    // Initialize Minimum and Second Minimum Elements
    int min1 = INT_MAX, min2 = INT_MAX;

    for(int i = 0; i < n; i++)
    {
    	// Update Maximum, Second Maximum, and Third Maximum
    	if(A[i] > max1)
    	{
    		max3 = max2;
    		max2 = max1;
    		max1 = A[i];
    	}
    	// Update Second Maximum, and Third Maximum
    	else if(A[i] > max2)
    	{
    		max3 = max2;
    		max2 = A[i];
    	}
    	// Update Third Element
    	else if(A[i] > max3)
    	{
    		max3 = A[i];
    	}

    	// Update Minimum, and Second Minimum
    	if(A[i] < min1)
    	{
    		min2 = min1;
    		min1 = A[i];
    	}
    	// Update Second Minimum
    	else if(A[i] < min2)
    	{
    		min2 = A[i];
    	}
    }

    return max(min1*min2*max1, max1*max2*max3);
}

// https://leetcode.com/problems/maximum-product-of-three-numbers/solution/
// http://www.geeksforgeeks.org/find-maximum-product-of-a-triplet-in-array/

// http://www.geeksforgeeks.org/maximum-product-subarray/
// https://leetcode.com/problems/maximum-product-subarray/