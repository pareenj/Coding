int Solution::nTriang(vector<int> &A) {
    
    long long int n = A.size();
    long long int maxi = 10e9 + 7;
	sort(A.begin(), A.end());

	long long int count = 0;

	// Fix the first element.  We need to run till n-3 as the other two elements are selected from arr[i+1...n-1]
	for(long long int i = 0; i < n-2; i++)
	{
		// Initialize index of the rightmost third element
		long long int k = i+2;

		// Fix the second element
		for(long long int j = i+1; j < n; j++)
		{
			// Find the rightmost element which is smaller than the sum of two fixed elements
            // The important thing to note here is, we use the previous  value of k. If value of 
            // arr[i] + arr[j-1] was greater than arr[k], then arr[i] + arr[j] must be greater than k, 
            // because the array is sorted.
            while(k < n && A[i] + A[j] > A[k]) k++;

            // Total number of possible triangles that can be formed with the two fixed elements is
            //  k - j - 1.  The two fixed elements are arr[i] and arr[j].  All elements between arr[j+1]/ to 
            // arr[k-1] can form a triangle with arr[i] and arr[j].
            // One is subtracted from k because k is incremented one extra in above while loop.
            // k will always be greater than j. If j becomes equal to k, then above loop will increment k, because 
            // arr[k] + arr[i] is always greater than arr[k]
            count += k - j - 1;
            count = count % maxi;
		}
	}
	return (int) count;
}

// http://www.geeksforgeeks.org/find-number-of-triangles-possible/
