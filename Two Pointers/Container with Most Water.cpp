int Solution::maxArea(vector<int> &A) {

	int maximumArea = 0;
	int left = 0, right = A.size() - 1;

	while(left < right)
	{
		maximumArea = max(maximumArea, (min(A[left], A[right]) * (right - left)));

		if(A[left] < A[right]) left++;
		else right--;
	}

	return maximumArea;
}

// https://leetcode.com/articles/container-most-water/