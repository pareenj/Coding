vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int n = A.size();
    vector<int> result;
    vector<int> copy = A;

    // Repeating Element
    for(int i = 0; i < n; i++)
    {
    	int x = copy[i];

    	if(copy[abs(x) - 1] > 0) copy[abs(x) - 1] *= -1;
    	else result.push_back(abs(x));
    }

    // Missing Element
    for(int i = 0; i < n; i++)
    {
    	if(copy[i] > 0) result.push_back(i+1);
    }

    return result;
}

vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    for(int i = 0; i < n; i++)
    {
        int index = A[i] % n;
        A[i] += n;
    }

    for(int i = 0; i < n; i++)
    {
        if(A[i]/n > 1) repeatElement = i;
    }
}

// http://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// http://www.geeksforgeeks.org/find-first-repeating-element-array-integers/
// http://www.geeksforgeeks.org/duplicates-array-using-o1-extra-space-set-2/