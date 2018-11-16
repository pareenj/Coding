void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    int size = A.size();
    if(size == 0 || size == 1) return;
    int i = size - 2;
    
    // Find first decreasing element from the end
    while(i >= 0 && A[i+1] <= A[i]) i--;
    
    
    if(i >= 0)
    {
        int j = size - 1;
        
        //Finding number just larger than the decreasing element found
        while(j >= 0 && A[j] <= A[i]) j--;
        
        swap(A[j], A[i]);
        
        reverse(A.begin() + i + 1, A.end());
    }
    
    if(i < 0)
    {
        for(int j = 0; j < size/2; j++) swap(A[j], A[size - 1- j]);
    }
}

// https://leetcode.com/problems/next-permutation/solution/