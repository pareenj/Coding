/*	Instead of maintaing two arrays of size n for storing left and right max of each element, 
	we will just maintain two variables to store the maximum till that point. 
	Since water trapped at any element = min( max_left, max_right) – arr[i] we will calculate water 
	trapped on smaller element out of A[lo] and A[hi] first and move the pointers till lo doesn’t cross hi.
*/

int Solution::trap(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    if(A.size() == 0) return 0;
    int n = A.size();

    // Initialize answer
    int answer = 0;

    // Initialize maximum element on left and right
    int leftMax = 0, rightMax = 0;

    // indices to traverse the array
    int low = 0, high = n-1;

    while(low <= high)
    {
    	if(A[low] < A[high])
    	{
    		if(A[low] > leftMax) // update leftMax
    			leftMax = A[low];
    		else // water on current element = max - current
    			answer += leftMax - A[low];
    		low++;
    	}
    	else
    	{
    		if(A[high] > rightMax) // update rightMax
    			rightMax = A[high];
    		else
    			answer += rightMax - A[high];
    		high--;
    	}
    }

    return answer;
}

// https://leetcode.com/problems/trapping-rain-water/solution/
// http://www.geeksforgeeks.org/trapping-rain-water/

// https://www.interviewbit.com/problems/rain-water-trapped/

int Solution::trap(const vector<int> &A) {
    vector <int> left(A.size());
    vector <int> right(A.size());
    
    int leftMax=A[0], rightMax = A[A.size()-1] ;
    int ans=0;
    
    for(int i=0;i<A.size();i++){
        leftMax=max(A[i],leftMax);
        left[i]=leftMax;
    }
    
    for(int i=A.size()-1; i>=0; i--){
        rightMax=max(A[i],rightMax);
        right[i]=rightMax;
    }
    
    for(int i=0 ; i<A.size() ; i++){
        ans += min(left[i], right[i]) - A[i]; 
    }
    
    return ans;
}