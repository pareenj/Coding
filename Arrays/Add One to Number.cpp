vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    vector<int> result;
    int size = A.size();
    int sum = 0, carry = 1;

    for(int i = size-1; i >= 0; i--)
    {
    	sum = A[i] + carry;
    	carry = sum/10;
    	result.push_back(sum % 10)
    }
    result.push_back(carry);
    reverse(result.begin(), result.end());
    //size = result.size();

    while(result[0] == 0)
    {
        result.erase(result.begin());
    	//size--;
    }

    return result;
}

vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    A.push_back(0);
    int size = A.size();
    int i = 1;
    while(i < size)
    {
        A[size - i] = A[size - i - 1];
        i++;
    }
    A[0] = 0;

    int sum = 0, carry = 1;
    
    for(int i = size-1; i >= 0; i--)
    {
        sum = A[i] + carry;
        carry = sum/10;
        A[i] = sum % 10;
    }

    while(A[0] == 0)
    {
        A.erase(A.begin());
    }

    return A;
}