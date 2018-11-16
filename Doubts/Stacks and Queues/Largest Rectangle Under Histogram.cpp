// https://leetcode.com/problems/largest-rectangle-in-histogram/
// http://www.geeksforgeeks.org/largest-rectangular-area-in-a-histogram-set-1/
// http://www.geeksforgeeks.org/largest-rectangle-under-histogram/

int Solution::largestRectangleArea(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int n = A.size();
    stack<int> s;
    
    int maxArea = 0, area = 0;
    int i = 0;
    int top;
    
    while(i < n)
    {
        if(s.empty() || A[i] >= A[s.top()]) s.push(i++);
        else
        {
            top = s.top();
            s.pop();
            
            if(s.empty()) area = A[top]*i;
            else area = A[top]*(i - s.top() - 1);
            
            maxArea = max(area, maxArea);
        }
    }
    
    while(!s.empty())
    {
        top = s.top();
        s.pop();
        
        if(s.empty()) area = A[top]*i;
        else area = A[top]*(i - s.top() - 1);
            
        maxArea = max(area, maxArea);
    }
    
    return maxArea;
}
