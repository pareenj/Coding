int Solution::maxSpecialProduct(vector<int> &A) {

	int n = A.size();
	int maxSpProd = 0;

	for(int i = 0; i < n; i++)
	{
		int left = 0, right = 0;
		for(int j = i-1; j >= 0; j--)
		{
			if(A[j] > A[i])
			{
				left = j;
				break;
			}
		}

		for(int j = i+1; j < n; j++)
		{
			if(A[j] > A[i])
			{
				right = j;
				break;
			}
		}

		if(left * right > maxSpProd)
		{
			maxSpProd = left * right;
		}
	}

	return maxSpProd;
}